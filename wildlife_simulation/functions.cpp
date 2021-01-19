#include "classes.h"
#include <iostream>
#include <random> // for std::mt19937
#include <ctime> // for std::time

int getRandomNumber(int min, int max) {
	// Mersenne Twister for maximum randomness
	static std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::uniform_int_distribution roll{ min, max };
	return roll(mersenne);
}

void printWorld(int** tile, int columns, int rows) {
	// Printing all tiles (with coordinates on the side (like in chess))
	std::cout << '\n' << ' ' << ' ' << ' ';
	for (int c = 0; c < (columns <= 10 ? columns : 10); ++c) {
		std::cout << ' ' << c;
	}
	std::cout << '\n' << '\n' << '\n';

	for (int r = 0; r < rows; ++r) {
		if (r < 10) std::cout << ' ' << r << ' ';
		else std::cout << "   ";
		for (int c = 0; c < columns; ++c) {
			if (tile[c][r] > 0)
				std::cout << ' ' << tile[c][r];
			else
				std::cout << ' ' << static_cast<char>(219);
		}
		std::cout << '\n' << '\n';
	}
}

void moveAnimals(int** tile, std::vector<Animal*>& animals, int columns, int rows) {
	for (auto* element : animals) {
		std::cout << '(' << element->getX() << ',' << element->getY() << ")\t"<<element->getName()<<" has moved to\t(";
		--tile[element->getX()][element->getY()]; // leaving the current tile
		int direction = getRandomNumber(0, 3);
		switch (direction) {
		case 0: // go right
			element->getX() < columns - 1 ? direction = 1 : direction = -1; // if not on the edge go right, else go left
			element->moveX(direction);
			break;
		case 1: // go left
			element->getX() > 0 ? direction = -1 : direction = 1;
			element->moveX(direction);
			break;
		case 2: // go down
			element->getY() < rows - 1 ? direction = 1 : direction = -1;
			element->moveY(direction);
			break;
		case 3: // go up
			element->getY() > 0 ? direction = -1 : direction = 1;
			element->moveY(direction);
		}
		++tile[element->getX()][element->getY()];
		std::cout << element->getX() << ',' << element->getY() << ")\n";
	}
}