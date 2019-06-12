/******************************************************************************
** Author: Chris Nelson 
** Date: 06.06.2019 
** Description:  see space class for thourough description
******************************************************************************/

#include<iostream>
#include"Bedroom.hpp"
#include"Space.hpp"
#include"LinkedList.hpp"

Bedroom::Bedroom()
{
	setDescription("Bedroom");
}

/******************************************************************************
** setter used to set the description of the space if default isn't desired
******************************************************************************/
void Bedroom::setDescription(std::string in)
{
  this->description = in;
}
