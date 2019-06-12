#ifndef   LIVINGROOM_HPP
#define   LIVINGROOM_HPP

#include<string>
#include"Space.hpp"

class LivingRoom : public Space
{

  public:
	LivingRoom();
	void setDescription(std::string in);

};
#endif

