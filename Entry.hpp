#ifndef   ENTRY_HPP 
#define  	ENTRY_HPP 

#include<string>
#include"Space.hpp"

class Entry : public Space
{

  public:
	Entry();
	void setDescription(std::string in);

};
#endif

