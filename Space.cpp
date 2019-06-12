/******************************************************************************
** Author: Chris Nelson 
** Date: 06.06.2019 
** Description:  this is the abstract space class.  This class is meant to 
** be derived from and can not be called as its own object. This class 
** description will serve all of the derived classes 
******************************************************************************/

#include<iostream>
#include"Space.hpp"

/******************************************************************************
** constructor - used by the children
******************************************************************************/
Space::Space()
{

}

/******************************************************************************
** getter used to get the string description of the space
******************************************************************************/
std::string Space::getDescription()
{
	return this->description;
}

/******************************************************************************
** setter used to set the description of the space, takes a string as arg.
******************************************************************************/
void Space::setDescription(std::string in)
{
  this->description = in;
}

/******************************************************************************
** this space links all the spaces together.  depending on the space arrangement
** one can enter another space or NULL as argument.  NULL would mean that there
** is no space connected on that side.
******************************************************************************/
void Space::linkSpaces(Space* inTop, Space* inRight, Space* inBottom, Space* inLeft)
{
	this->top = inTop;
  this->right = inRight;
  this->bottom = inBottom;
  this->left = inLeft;
}

/******************************************************************************
** this are getters for all 4 sides, returns NULL if space is not connected
******************************************************************************/
Space* Space::getTop()
{
	if(this->top != NULL)
	{
  	return this->top;
	}
	else
	{
		return NULL;
	}
}

Space* Space::getRight()
{
	if(this->right != NULL)
	{
	  return this->right;
	}
	else
	{
		return NULL;
	}
}

Space* Space::getBottom()
{
	if(this->bottom != NULL)
	{
  	return this->bottom;
	}
	else
	{
		return NULL;
	}
}

Space* Space::getLeft()
{
	if(this->left != NULL)
	{
  	return this->left;
	}
	else
	{
		return NULL;
	}
}

/******************************************************************************
** this is a debug function used to display the links to console.
******************************************************************************/
void Space::displayLinks()
{
	std::cout << this->description << " is connectected to:" << std::endl;

	//display top connection
	if(this->top != NULL)
	{
		std::cout << "Front: " << top->getDescription() << std::endl;
	}
	else
	{
		std::cout << "Front: Nothing" << std::endl;
	}

	//display right connection
	if(this->right != NULL)
	{
		std::cout << "Right: " << right->getDescription() << std::endl;
	}
	else
	{
		std::cout << "Right: Nothing" << std::endl;
	}

	//display backwards connection
	if(this->bottom != NULL)
	{
		std::cout << "Behind: " << bottom->getDescription() << std::endl;
	}
	else
	{
		std::cout << "Behind: Nothing" << std::endl;
	}

	//display left connection
	if(this->left != NULL)
	{
		std::cout << "Left: " << left->getDescription() << std::endl;
	}
	else
	{
		std::cout << "Left: Nothing" << std::endl;
	}
}

/******************************************************************************
** this function fills the char array of a space to. the char array is specially
** designed to take an 'image' of chars in 50 rows x 180 cols format.  
******************************************************************************/

void Space::fillImage(std::string name)
{
	//stream our images to the strings
  std::ifstream inFile;
	
	inFile.open(name);
	char current;
	for(int i = 0; i < 8506; i++)
	{
		inFile >> std::noskipws >> current;
		image[i] = current;
	}
	inFile.close();

	//fill minimap
	//first we blank it out
	int counter = 6335;
	while(counter < 8506)
	{
		for(int i = 0; i < 20; i++)
		{
			image[counter] = ' ';	
			counter++;
		}
			counter+=161;
	}
		counter = 6519;

	//fill map with verticals
		while(counter < 8506)
	{
		for(int i = 0; i < 5; i++)
		{
			image[counter] = '|';	
			counter+=3;
		}
			counter+=166;
	}

	//fill map with horizontals 
		counter = 6520;
		while(counter < 8506)
	{
		for(int i = 0; i < 4; i++)
		{
			image[counter] = '-';	
			image[counter+1] = '-';	
			counter+=3;
		}
			counter+=350;
	}
}



void Space::fillMiniMap(int in)
{
	this->image[in] = 'X';
	this->image[in+1] = 'X';
}

/******************************************************************************
** this function prints the char array to the screen as an image.   
******************************************************************************/
void Space::printImage()
{
	for(int i = 0; i < 8506; i++)
	{
		std::cout << image[i];
	}
}








