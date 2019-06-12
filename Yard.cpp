/******************************************************************************
** Author: Chris Nelson 
** Date: 06.06.2019 
** Description:  see space class for thourough description
******************************************************************************/

#include<iostream>
#include"Yard.hpp"
#include"Space.hpp"
#include"LinkedList.hpp"

Yard::Yard()
{
	setDescription("Yard");
}

/******************************************************************************
** setter used to set the description of the space if default isn't desired
******************************************************************************/
void Yard::setDescription(std::string in)
{
  this->description = in;
}
