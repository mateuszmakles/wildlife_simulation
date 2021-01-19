#include "classes.h"
#include "functions.h"
#include <iostream>
#include <vector>

Animal::Animal(int** tile, Sex g, int xx, int yy, std::string n) : gender{ g }, x{ xx }, y{ yy }, name{ n } {
	// Adding this animal to the tile it's on (in order to keep track of the amount of animals on this tile)
	++tile[x][y];
}

void Animal::move(int** tile, int columns, int rows) {
	std::cout << '(' << x << ',' << y << ")\t" << name << " has moved to\t(";
	--tile[x][y]; // leaving the current tile
	switch (getRandomNumber(0, 3)) {
	case 0: // go right
		x < columns - 1 ? ++x : --x; // if not on the edge go right, else go left
		break;
	case 1: // go left
		x > 0 ? --x : ++x;
		break;
	case 2: // go down
		y < rows - 1 ? ++y : --y;
		break;
	case 3: // go up
		y > 0 ? --y : ++y;
	}
	++tile[x][y];
	std::cout << x << ',' << y << ")\n";
}

Predator::Predator(int** tile, Sex g, int xx, int yy) : Animal{ tile,g,xx,yy,"Predator" }, hunger{ 0 } {}

bool Predator::eat(int** tile, std::vector<Animal>& animals) {
	if (tile[x][y] > 1) {
		for (auto& animal : animals) {
			if (animal.getX() == x && animal.getY() == y) {
				//delete animal; // this animal has been eaten so let's delete it
				hunger = 0; // and reset the predator's hunger
				std::cout << '(' << x << ',' << y << ")\tPredator has eaten an animal\n";
				return true; // predators can only eat once per turn so let's leave
			}
			else return false;
		}
	}
	else return false;
}