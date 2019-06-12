#ifndef   KITCHEN_HPP 
#define   KITCHEN_HPP

#include<string>
#include"Space.hpp"

class Kitchen : public Space
{

  public:
	Kitchen();
	void setDescription(std::string in);

};
#endif

