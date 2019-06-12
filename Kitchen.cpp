/******************************************************************************
** Author: Chris Nelson 
** Date: 06.06.2019 
** Description:  see space class for thourough description
******************************************************************************/

#include<iostream>
#include"Kitchen.hpp"

Kitchen::Kitchen()
{
	setDescription("Kitchen");
}

/******************************************************************************
** setter used to set the description of the space if default isn't desired
******************************************************************************/
void Kitchen::setDescription(std::string in)
{
  this->description = in;
}
