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
	std::cout << '\n' << '\n' << ' ' << ' ' << ' ';
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
	for (int i = 0; i <= 50; ++i) std::cout << '_';
	std::cout << '\n' << '\n';
}

/*void eat(int** tile, std::vector<Predator>& predators, std::vector<Animal>& animals) {
	for (auto& predator : predators) {
		if (tile[predator->getX()][predator->getY()] > 1) {
			for (auto& animal : animals) {
				if (animal->getX() == predator->getX() && animal->getY() == predator->getY()) {
					delete animal; // this animal has been eaten so let's delete it
					static_cast<Predator*>(predator)->resetHunger(); // and reset the predator's hunger
					std::cout << '(' << predator->getX() << ',' << predator->getY() << ") Predator has eaten an animal\n";
					break; // predators can only eat once per turn so let's leave
				}
				else suffer(static_cast<Predator*>(predator));
			}
		}
		else suffer(static_cast<Predator*>(predator));
	}
}

void suffer(Predator* predator) {
	predator->incrementHunger();
	if (predator->isDead()) {
		std::cout << '(' << predator->getX() << ',' << predator->getY() << ") Predator died from hunger\n";
		delete predator;
	}
	else {
		std::cout << '(' << predator->getX() << ',' << predator->getY() << ") Predator is hungry\n";
	}
}*/