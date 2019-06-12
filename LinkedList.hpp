#ifndef   LINKEDLIST_HPP
#define   LINKEDLIST_HPP

#include"Space.hpp"

class LinkedList
{
  public:
	LinkedList();
	~LinkedList();
  void add(Space*);
  void addTail(Space*);
  void addHead(Space*);
	void remove(int);
	void removeHead();
	void removeTail();
	void displayReverse();
	void display();
	void displayTail();
	void displayHead();


  protected:
  struct SpaceList
  {
 		int val;
		SpaceList* next;
		SpaceList* prev;
		Space* room;
  	SpaceList(Space* &inRoom, SpaceList* inNext = NULL)
		{
			room = inRoom;	
			next = inNext;
		}
	};

	SpaceList* head;

  private:


};
#endif

