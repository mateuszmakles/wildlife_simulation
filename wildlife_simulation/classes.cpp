#include "classes.h"

Animal::Animal(int** tile, Sex g, int xx, int yy, std::string n) : gender{ g }, x{ xx }, y{ yy }, name{ n } {
	// Adding this animal to the tile it's on (in order to keep track of the amount of animals on this tile)
	++tile[x][y];
}

Predator::Predator(int** tile, Sex g, int xx, int yy) : Animal{ tile,g,xx,yy,"Predator" } {}