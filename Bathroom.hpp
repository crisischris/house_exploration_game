#ifndef   BATHROOM_HPP
#define   BATHROOM_HPP

#include<string>
#include"Space.hpp"

class Bathroom : public Space
{

  public:
  Bathroom();
	void setDescription(std::string in);

};
#endif

