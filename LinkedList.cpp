/******************************************************************************
** Author: Chris Nelson 
** Date: 05.10.2019 
** Description: This is the linked list class.  This class creates a linked 
** structure for the user to manipulate 
******************************************************************************/

#include<iostream>
#include"LinkedList.hpp"
#include"Helper.hpp"
#include"Space.hpp"



LinkedList::LinkedList()
{
  head = NULL;
}

LinkedList::~LinkedList()
{
	SpaceList* spacePtr = head;

	while(spacePtr != NULL)
	{
		SpaceList* garbabe = spacePtr;
		spacePtr = spacePtr->next;
 		delete garbabe;
	}
}

//****************************************************************************
//this funciton adds a node to the list
//****************************************************************************

void LinkedList::add(Space* in)
{
	if(head == NULL)
	{
		head = new SpaceList(in);
		SpaceList* currList = head;
		currList->prev = NULL;
		currList->next = NULL;
	}
	else
	{
		SpaceList* spacePtr = head;
		while(spacePtr->next != NULL)
		{
			spacePtr = spacePtr->next;
		}
		spacePtr->next = new SpaceList(in);
    SpaceList* currList = spacePtr->next;
    currList->prev = spacePtr;
	}

}

//****************************************************************************
//this funciton adds a node to the tail of the list
//****************************************************************************

void LinkedList::addTail(Space* in)
{
		SpaceList* spacePtr = head;
		if(head == NULL)
		{
			add(in);
		}
		else
		{
			while(spacePtr->next != NULL)
			{
				spacePtr = spacePtr->next;
			}
	  //we've found the last node
		spacePtr->next = new SpaceList(in);
    SpaceList* currList = spacePtr->next;
    currList->prev = spacePtr;
	}

}

//****************************************************************************
//this funciton adds a node to the head of the list
//****************************************************************************

void LinkedList::addHead(Space* in)
{
  //adding head to the first array element
	if(head == NULL)
	{
		add(in);
	}
	else
	{
		SpaceList* tempNext = head;
		SpaceList* spacePtr = tempNext->prev;
		spacePtr = new SpaceList(in);
		spacePtr->prev = NULL;
		spacePtr->next = tempNext; 
		tempNext->prev = spacePtr; 
		head = spacePtr;
	}
}


//****************************************************************************
//this funciton removes a node to the head of the list
//****************************************************************************

void LinkedList::removeHead()
{
	SpaceList* spacePtr = head;

	//we have at least one item in our list
  if(head != NULL)
	{
  	//first item of the list
		head = spacePtr->next; 
		delete spacePtr;
	}
	else
	{
 		Helper::printMessage("Your list is empty!",1);	
	}
}

//****************************************************************************
//this funciton removes a node to the tail of the list
//****************************************************************************

void LinkedList::removeTail()
{
	SpaceList* spacePtr = head;

	//list is empty
  if(head == NULL)
	{
 		Helper::printMessage("Your list is empty!",1);	
	}

	else
	{
		while(spacePtr->next != NULL)
		{
			spacePtr = spacePtr->next;
		}

		//one item in the list
		if(spacePtr->prev == NULL)
		{
			head = NULL;
			delete spacePtr;
		}
		//there is more than one item in list
		else
		{
			SpaceList* temp = spacePtr->prev;
			delete spacePtr;
			temp->next = NULL;
		}
	}
}

//****************************************************************************
//this funciton removes a node to the tail of the list
//****************************************************************************

void LinkedList::remove(int in)
{
	SpaceList* spacePtr = head;

  //first item of the list
  if(spacePtr->val == in)
	{
		head = spacePtr->next; 
		delete spacePtr;
	}
	else
	{
		while(spacePtr->next != NULL && spacePtr->val != in)
		{
				spacePtr = spacePtr->next;
		}
			//we have found a node with the val
 		if(spacePtr->val = in)
		{
			if(spacePtr->next != NULL)
			{
				SpaceList* tempNext = spacePtr->next;
				tempNext->prev = spacePtr->prev;
				SpaceList* tempPrev = spacePtr->prev; 
				tempPrev->next = tempNext;
				delete spacePtr;
			}
    //this is the last node
			else
			{
				SpaceList* tempPrev = spacePtr->prev; 
				tempPrev->next = NULL; 
				delete spacePtr;
			}
		}
	}
}


//****************************************************************************
//this funciton displays the list from head to tail
//****************************************************************************

void LinkedList::display()
{
	SpaceList* spacePtr = head;
	if(spacePtr == NULL)
	{
		Helper::printMessage("Empty list",0);
	}
  while(spacePtr)
	{
		std::cout << spacePtr->val << " -> ";
		spacePtr = spacePtr->next;
	}
}

void LinkedList::displayReverse()
{
	SpaceList* spacePtr = head;

  //traverse to the end of the list 
	while(spacePtr->next != NULL)
	{
  	spacePtr = spacePtr->next;
	}
  //found the end;
  while(spacePtr)
	{
		std::cout << spacePtr->val << " -> ";
		spacePtr = spacePtr->prev;
	}
}


//****************************************************************************
//this funciton displays the head value of the list 
//****************************************************************************

void LinkedList::displayHead()
{
  //adding head to the first array element
	if(head == NULL)
	{
 		Helper::printMessage("Your list is empty!",1);	
	}
	else
	{
		std::cout << "The value of head is: " << head->val << std::endl;
	}
}

//****************************************************************************
//this funciton displays the tail value of the list 
//****************************************************************************

void LinkedList::displayTail()
{
	SpaceList* spacePtr = head;

	//list is empty
  if(head == NULL)
	{
 		Helper::printMessage("Your list is empty!",1);	
	}

	if(spacePtr->next == NULL)
	{
	  displayHead();	
	}

	else
	{
		while(spacePtr->next != NULL)
		{
			spacePtr = spacePtr->next;
		}

		std::cout << "The value of tail is: " << spacePtr->val << std::endl;
	}
}

