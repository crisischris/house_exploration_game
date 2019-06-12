/******************************************************************************
** Author: Chris Nelson 
** Date: 06.06.2019 
** Description:  see space class for thourough description
******************************************************************************/

#include<iostream>
#include"SpookySpace.hpp"
#include"Space.hpp"
#include"LinkedList.hpp"

SpookySpace::SpookySpace()
{
	setDescription("Spooky Space");
}

/******************************************************************************
** setter used to set the description of the space if default isn't desired
******************************************************************************/
void SpookySpace::setDescription(std::string in)
{
  this->description = in;
}
