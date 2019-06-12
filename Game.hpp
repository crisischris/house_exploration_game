#ifndef   GAME_HPP
#define   GAME_HPP

#include<stack>
#include<string>
#include<fstream>
#include"Space.hpp"

class Game 
{

  public:
  static void update();
  

  protected:


  private:
	static void arrivalMessage();
	static void generateFloorPlan(std::stack<Space*>&);
	static void debugPrintList(std::stack<Space*>);
	static void displayState(Space*, int);
	static void roomIsNull(std::string);
	static char* fillImage(char*, std::string, int);
	static void printImage(char*, int);

};
#endif

