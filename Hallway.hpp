#ifndef   HALLWAY_HPP
#define   HALLWAY_HPP 

#include<string>
#include"Space.hpp"

class Hallway : public Space
{

  public:
	Hallway();
	void setDescription(std::string in);

};
#endif

