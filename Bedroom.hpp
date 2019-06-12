#ifndef   BEDROOM_HPP
#define   BEDROOM_HPP

#include<string>
#include"Space.hpp"

class Bedroom : public Space
{

  public:
  Bedroom();
	void setDescription(std::string in);

};
#endif

