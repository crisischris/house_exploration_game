/******************************************************************************
** Author: Chris Nelson 
** Date: 06.06.2019 
** Description:  see space class for thourough description
******************************************************************************/

#include<iostream>
#include"Bathroom.hpp"
#include"Space.hpp"
#include"LinkedList.hpp"

Bathroom::Bathroom()
{
	setDescription("Bathroom");
}

/******************************************************************************
** setter used to set the description of the space if default isn't desired
******************************************************************************/
void Bathroom::setDescription(std::string in)
{
  this->description = in;
}
