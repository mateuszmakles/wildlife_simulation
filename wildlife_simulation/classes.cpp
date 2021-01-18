#include "classes.h"

Animal::Animal(int** tile, Sex g, int xx, int yy) : gender{ g }, x{ xx }, y{ yy } {
	// Adding this animal to the tile it's on (in order to keep track of the amount of animals on this tile)
	++tile[x][y];
}

Predator::Predator(int** tile, Sex g, int xx, int yy) : Animal{ tile,g,xx,yy } {}