#include "classes.h"
#include "functions.h" // for getRandomNumber()
#include <iostream>
#include <vector>

Animal::Animal(int** tile, std::vector<Animal>& vect, int xx, int yy)
	: vector{ &vect }, gender { static_cast<Animal::Sex>(getRandomNumber(0, 1)) }, x{ xx }, y{ yy }, hasBred{ 0 } {
	// Adding this animal to the tile it's on (in order to keep track of the amount of animals on this tile)
	++tile[x][y];
	// and announcing its appearance
	std::cout << '(' << x << ',' << y << ")\t" << printInfo() << "spawned!\n";
}
Animal::Animal(int** tile, int xx, int yy)
	: gender{ static_cast<Animal::Sex>(getRandomNumber(0, 1)) }, x{ xx }, y{ yy }, hasBred{ 0 } {
	++tile[x][y];
}

void Animal::move(int** tile, int columns, int rows) {

	int direction;

	// Checking if we can move at all
	if ((x == 0 && x == columns - 1) && (y == 0 && y == rows - 1)) {
		std::cout << '(' << x << ',' << y << ")\t" << printInfo() << "couldn't move\n";
		return; // there's only one tile (no place to move) so we're skipping the rest of the function
	}
	else if (x == 0 && x == columns - 1)
		direction = getRandomNumber(2, 3);
	else if (y == 0 && y == rows - 1)
		direction = getRandomNumber(0, 1);
	else
		direction = getRandomNumber(0, 3);

	std::cout << '(' << x << ',' << y << ")\t" << printInfo() << "has moved to\t(";
	--tile[x][y]; // leaving the current tile

	switch (direction) {
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
	
void Animal::breed(int** tile) {
	if (tile[x][y] > 1) {
		for (auto& animal : *vector) {
			if (animal.getX() == x && animal.getY() == y && compare(animal)) {
				animal.setBreed(1);
				hasBred = 1;
				std::cout << "\tand bred\n";
				vector->push_back(Animal(tile, *vector, x, y));
				return;
			}
		}
	}
}

Predator::Predator(int** tile, std::vector<Predator>& vect, int xx, int yy)
	: Animal{ tile,xx,yy }, pvector{ &vect }, hunger{ 0 } {
	std::cout << '(' << x << ',' << y << ")\t" << printInfo() << "spawned!\n";
}

void Predator::breed(int** tile) {
	if (tile[x][y] > 1) {
		for (auto& predator : *pvector) {
			if (predator.getX() == x && predator.getY() == y && compare(predator)) {
				predator.setBreed(1);
				hasBred = 1;
				std::cout << "\tand bred\n";
				pvector->push_back(Predator(tile, *pvector, x, y));
				return;
			}
		}
	}
}

bool Predator::eat(int** tile, std::vector<Animal>& animals) {
	// Checking if the predator is sharing his tile with potential dinner
	if (tile[x][y] > 1) {
		for (int i = 0; i < animals.size(); ++i) {
			if (animals[i].getX() == x && animals[i].getY() == y) {
				--tile[x][y]; // one animal less on this tile
				hunger = 0; // and reset the predator's hunger
				std::cout << "\tand has eaten an animal\n";
				animals.erase(animals.begin() + i); // this animal has been eaten so let's delete it
				animals.shrink_to_fit();
				return true; // predators can only eat once per turn so let's leave
			}
		}
	}
	return false;
}