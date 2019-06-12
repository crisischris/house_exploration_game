/******************************************************************************
** Author: Chris Nelson 
** Date: 06.06.2019 
** Description:  this is the game class that has most of the game logic. 
** the public function uptate is all that is needed to call in the main.cpp
** to start the game. 
******************************************************************************/

#include<iostream>
#include<stack>
#include<string>

#include"Helper.hpp"
#include"Space.hpp"
#include"SpookySpace.hpp"
#include"Bedroom.hpp"
#include"LivingRoom.hpp"
#include"Yard.hpp"
#include"Hallway.hpp"
#include"Kitchen.hpp"
#include"Entry.hpp"
#include"Bathroom.hpp"
#include"Game.hpp"

void Game::update()
{
	bool timeIsUp = false;
	bool missionComplete = false;
  const int IMG_SIZE = 10860;
	int counter = 40;

	arrivalMessage();

  int initialChoice =	Helper::menu("Head to Hapton Manner", "Quit");

	while(counter > 0 && !missionComplete)
	{

		//instantiate our space stack 
		std::stack<Space*> list;

		switch(initialChoice)
		{
			case 1:
			{
				//instantiate our photo stack
				std::stack<std::string> photographs;

				//generate our floor plan
				generateFloorPlan(list);

				//initiallize the tour at the front Yard
			  Space* currSpace = list.top();	

				while(!timeIsUp && !missionComplete)
	 			{
					//printMimiMap(miniMap);

					displayState(currSpace, counter);
					currSpace->printImage();
					Helper::newLine(1);
					//Some sort of display that displays the current space user is in, maybe previous space and previous direction?						

					Helper::newLine(1);
					Helper::printMessage("What would you like to do?",2);
					int direction = Helper::menu("Snap a photo", "Count photos", "Move fowards", "Move right", "Move backwards", "Move left");
					switch(direction)
					{
						//user chose to investigate 
						case 1:
						{
							bool alreadyTaken = false;
							std::string currentPhoto = currSpace->getDescription();
							std::stack<std::string> tmpPhotographs = photographs;
							for(int i = 0; i < photographs.size(); i++)
							{
								if(tmpPhotographs.top() ==  currentPhoto)
								{
									alreadyTaken = true;
								}	
								tmpPhotographs.pop();
							}
							if(alreadyTaken)
							{
								std::cout << "You've already taken a great photo of the " << currentPhoto << std::endl;
							}
							else
							{
								photographs.push(currentPhoto);
								Helper::printMessage("Great, you took the photo and put it in your pocket",1);
							}
							
							counter--;
							break;
						}

						//count and display the photographs
						case 2:
						{
							std::stack<std::string> tmpPhotos = photographs;
							int tmpPhotosLength = tmpPhotos.size();

							if(!tmpPhotos.empty())
							{
								Helper::printMessage("Photos taken: ",0);
								for(int i = 0; i < tmpPhotosLength; i++)
								{
									std::cout << tmpPhotos.top() << ", ";
									tmpPhotos.pop();
								}
								Helper::newLine(1);
							}
							else
							{
								Helper::printMessage("You haven't taken any photos!",1);
							}

							counter--;
							break;
						}

						//user chose fowards
						case 3:
						{
							if(currSpace->getTop() != NULL)
							{
								currSpace = currSpace->getTop();
								counter--;
							}
							else
							{
								roomIsNull("forwards");
							}

							break;
						}

						//user chose right
						case 4:
						{
							if(currSpace->getRight() != NULL)
							{
								currSpace = currSpace->getRight();
								counter--;
							}
							else
							{
								roomIsNull("right");
							}

							break;
						}

						//user chose backwards 
						case 5:
						{
							if(currSpace->getBottom() != NULL)
							{
								currSpace = currSpace->getBottom();
								counter--;
							}
							else
							{
								roomIsNull("backwards");
							}

							break;
						}

						//user chose left 
						case 6:
						{
							if(currSpace->getLeft() != NULL)
							{
								currSpace = currSpace->getLeft();
								counter--;
							}
							else
							{
								roomIsNull("left");
							}
							break;
						}
					}		

					if(photographs.size() == 12)
					{
						Helper::printMessage("You did it! Now hurry up and get out of this place",1);
						missionComplete = true;
						//delete our space objects
						if(!list.empty())
						{
							int tempListSize = list.size();
							for(int i = 0; i < tempListSize; i++)
							{
							delete list.top();
							list.pop();
							}
						}
					}

					//time is up!
					if(counter == 0)
					{
						timeIsUp = true;
						Helper::printMessage("Oh no! You've ran out of time.  You're fired!",1);

						//delete our space objects
						if(!list.empty())
						{
							int tempListSize = list.size();
							for(int i = 0; i < tempListSize; i++)
							{
								delete list.top();
								list.pop();
							}
						}
					}
				}
				break;
			}
			case 2:
			{
				//delete our space objects
				Helper::printMessage("You can't quit!  You're fired!",1);
				if(!list.empty())
				{
					int tempListSize = list.size();
					for(int i = 0; i < tempListSize; i++)
					{
						delete list.top();
						list.pop();
					}
				}
				counter = 0;
				break;
			}
		}
	}
}

/******************************************************************************
** this function has all of the text based dialoge.  This is used to clean up
** the code in the main function
******************************************************************************/
void Game::arrivalMessage()
{
	std::string line1 = "Hello and welcome!  I've heard you want to become a real estate agent!";
	std::string line2 = "What did you say your name was again?";
	std::string line2b = "Ah right ";
	std::string line3 = "Being an agent isn't as easy as it sounds, but if you think you're up to it, I can test you out.";
	std::string line4 = "For your first task, I want you to go photograph the old Hampton Manner.  It's been on my to-do list.";
	std::string line5 = "Oh and "; 
  std::string line6 = ", keep an eye out. Sometimes these old houses can be spooky and you don't want to get lost.";
  std::string line7 = "Last thing, you need to get in and out of there in under 40 minutes.";
  std::string line8 = "NOTE: Moving between rooms takes 1 minute.";
  std::string line9 = "      Taking a photograph takes 1 minute.";
  std::string line10 = "      Looking at your photographs takes 1 minute.";
  std::string line11 = "      There are 12 total photographs you need, one for each room.";

	std::cout << line1 << std::endl;
	std::cout << line2 << std::endl;
	std::string name = Helper::getString(0);	
	std::cout << line2b << name << "!" << std::endl;
	std::cout << line3 << std::endl;
	std::cout << line4 << std::endl;
	std::cout << line5 << name << line6 <<std::endl;
	std::cout << line7 << std::endl;
  Helper::newLine(1);
	std::cout << line8 << std::endl;
	std::cout << line9 << std::endl;
	std::cout << line10 << std::endl;
	std::cout << line11 << std::endl;

  Helper::newLine(3);
}


/******************************************************************************
** this function generates are spaces, along with setting a lot of the 
** space data members.  It takes as argument a stack of Space poiters
******************************************************************************/
void Game::generateFloorPlan(std::stack<Space*>& in)
{
	//create our rooms
	Space* entry = new Entry();
	entry->fillImage("entry3.txt");
	entry->fillMiniMap(7790);
	in.push(entry);

	Space* living = new LivingRoom();
	living->fillImage("living.txt");
	living->setDescription("Living room");
	living->fillMiniMap(7793);
	in.push(living);

	Space* kitchen = new Kitchen();
	kitchen->fillImage("kitchen.txt");
	kitchen->fillMiniMap(7787);
	in.push(kitchen);

	Space* hallway1 = new Hallway();
	hallway1->fillImage("hallway2.txt");
	hallway1->fillMiniMap(7428);

	//we need to give the rooms which occur multiple times
	//different descriptions for the end tally
	hallway1->setDescription("Front hallway");
	in.push(hallway1);

	Space* hallway2 = new Hallway();
	hallway2->fillImage("hallway2.txt");
	hallway2->fillMiniMap(7066);

	//we need to give the rooms which occur multiple times
	//different descriptions for the end tally
	hallway2->setDescription("Back hallway");
	in.push(hallway2);

	Space* bed1 = new Bedroom();
	bed1->fillImage("bedroom.txt");
	bed1->fillMiniMap(7431);

	//we need to give the rooms which occur multiple times
	//different descriptions for the end tally
	bed1->setDescription("First bedroom");
	in.push(bed1);

	Space* bed2 = new Bedroom();
	bed2->fillImage("bedroom2.txt");
	bed2->fillMiniMap(7069);

	//we need to give the rooms which occur multiple times
	//different descriptions for the end tally
	bed2->setDescription("Second bedroom");
	in.push(bed2);

	Space* bathroom1 = new Bathroom();
	bathroom1->fillImage("bathroom.txt");
	bathroom1->fillMiniMap(7434);

	//we need to give the rooms which occur multiple times
	//different descriptions for the end tally
	bathroom1->setDescription("First bathroom");
	in.push(bathroom1);

	Space* bathroom2 = new Bathroom();
	bathroom2->fillImage("bathroom2.txt");
	bathroom2->fillMiniMap(7072);

	//we need to give the rooms which occur multiple times
	//different descriptions for the end tally
	bathroom2->setDescription("Second bathroom");
	in.push(bathroom2);

	Space* spooky1 = new SpookySpace();
	spooky1->fillImage("spooky.txt");
	spooky1->fillMiniMap(7425);

	//we need to give the rooms which occur multiple times
	//different descriptions for the end tally
	spooky1->setDescription("Spooky pantry");
	in.push(spooky1);

	Space* spooky2 = new SpookySpace();
	spooky2->fillImage("spooky.txt");
	spooky2->fillMiniMap(6710);

	//we need to give the rooms which occur multiple times
	//different descriptions for the end tally
	spooky2->setDescription("Spooky secret room");
	in.push(spooky2);
	
	//top element
	Space* frontYard = new Yard();
	frontYard->fillImage("yard.txt");
	frontYard->fillMiniMap(8152);
	in.push(frontYard);

  //link our rooms
	frontYard->linkSpaces(entry,NULL,NULL,NULL);
	entry->linkSpaces(hallway1, living, frontYard,kitchen);
	living->linkSpaces(NULL, NULL, NULL, entry);
	kitchen->linkSpaces(spooky1, entry, NULL, NULL);
	hallway1->linkSpaces(hallway2, bed1, entry, spooky1);
	hallway2->linkSpaces(NULL, bed2, hallway1, NULL);
	bed1->linkSpaces(NULL, bathroom1, NULL, hallway1);
	bed2->linkSpaces(NULL, bathroom2, NULL, hallway2);
	bathroom1->linkSpaces(NULL, NULL, NULL, bed1);
	bathroom2->linkSpaces(spooky2, NULL, NULL, bed2);
	spooky1->linkSpaces(NULL, hallway1, kitchen, NULL);
	spooky2->linkSpaces(NULL, NULL, bathroom2, NULL);
}

/******************************************************************************
** this is a debug function that prints a list of space pointers. It takes a
** stack of space pointers as argument
******************************************************************************/
void Game::debugPrintList(std::stack<Space*> list)
{
	int listLength = list.size();

	for(int i = 0; i < listLength; i++)
	{
		list.top()->displayLinks();	
		list.pop();	
		Helper::newLine(1);
	}

}

/******************************************************************************
** this function prints the where the player is currently and the amount of
** time the player has left.  it takes a space pointer and integer 
******************************************************************************/
void Game::displayState(Space* in, int time) 
{
	std::string currentSpace = in->getDescription();

	//print top border
	for(int i = 0; i < 30; i++)
	{
		std::cout << "*";	
	}	
	
	Helper::newLine(1);
	std::cout << "You are in the " << currentSpace << std::endl;
	Helper::newLine(1);
	std::cout << "You have : " << time << " minutes left" << std::endl;
	
}

/******************************************************************************
** this function prints a string to let the user know there is no room.
******************************************************************************/
void Game::roomIsNull(std::string in)
{
	std::cout << "There is no way for you to go " << in << ", try another way" << std::endl; 
}
