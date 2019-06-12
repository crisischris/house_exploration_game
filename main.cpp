/******************************************************************************
** Author: Chris Nelson 
** Date: 06.06.2019 
** Description:  this main function simply calls our game update loop
******************************************************************************/

#include"Helper.hpp"
#include"Game.hpp"

int main()
{
	//game splash screen
	Helper::splashScreen("   SO YOU WANT TO BE A REAL ESTATE AGENT?   ",3);

	//start the game!
  Game::update();

  return 0;
}
