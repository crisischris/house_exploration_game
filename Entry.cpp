/******************************************************************************
** Author: Chris Nelson 
** Date: 
** Description: 
** 
** 
******************************************************************************/


#include<iostream>
#include"Entry.hpp"
#include"Space.hpp"

Entry::Entry()
{
	setDescription("Entry");
}

/******************************************************************************
** setter used to set the description of the space if default isn't desired
******************************************************************************/
void Entry::setDescription(std::string in)
{
  this->description = in;
}
