/******************************************************************************
** Author: Chris Nelson 
** Date: 06.06.2019 
** Description:  see space class for thourough description
******************************************************************************/

#include<iostream>
#include"Hallway.hpp"
#include"Space.hpp"

Hallway::Hallway()
{
	setDescription("Hallway");
}

/******************************************************************************
** setter used to set the description of the space if default isn't desired
******************************************************************************/
void Hallway::setDescription(std::string in)
{
  this->description = in;
}
