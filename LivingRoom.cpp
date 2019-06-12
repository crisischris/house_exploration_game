/******************************************************************************
** Author: Chris Nelson 
** Date: 06.06.2019 
** Description:  see space class for thourough description
******************************************************************************/

#include<iostream>
#include"LivingRoom.hpp"

LivingRoom::LivingRoom()
{
	setDescription("LivingRoom");
}

/******************************************************************************
** setter used to set the description of the space if default isn't desired
******************************************************************************/
void LivingRoom::setDescription(std::string in)
{
  this->description = in;
}
