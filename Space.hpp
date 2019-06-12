#ifndef   SPACE_HPP
#define   SPACE_HPP

#include<string>
#include<fstream>

class Space 
{

  public:

	Space();

  std::string	getDescription();
  virtual void setDescription(std::string) = 0;

	void linkSpaces(Space*, Space*, Space*, Space*);
	void displayLinks();
	void fillImage(std::string);
	void fillMiniMap(int);
	void printImage();

	Space* getTop();
	Space* getRight();
	Space* getBottom();
	Space* getLeft();

  protected:
  Space* top = NULL;
  Space* left = NULL;
  Space* right = NULL;
  Space* bottom = NULL;
	char image[8506];

	std::string description;
  private:


};
#endif

