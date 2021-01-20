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

int validateInt(std::string_view str, int min) {
	// Checking for valid input
	int input;
	while (true) {
		std::cout << str;
		std::cin >> input;
		if (std::cin.fail() || input < min) {
			std::cerr << "\n\tINVALID INPUT\n\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		std::cin.ignore(32767, '\n');
		return input;
	}
}

void printWorld(int** tile, int columns, int rows) {
	// Printing all tiles (with coordinates on the side like in chess)
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
				std::cout << ' ' << static_cast<char>(219); // ASCII for rectangles (empty tiles)
		}
		std::cout << '\n' << '\n';
	}
	for (int i = 0; i <= 50; ++i) std::cout << '_';
	std::cout << '\n' << '\n';
}

void animalPhase(int** tile, std::vector<Animal>& animals, int columns, int rows) {

	// Move all animals and try to breed
	for (int i = 0; i < animals.size(); ++i) {

		animals[i].move(tile, columns, rows);

		// If didn't breed yet this turn try to
		if (animals[i].canBreed()) {
			animals[i].breed(tile);
		}
	}
}

void predatorPhase(int** tile, std::vector<Animal>& animals, std::vector<Predator>& predators, int columns, int rows) {

	// Move all predators, breed and eat
	for (int i = 0; i < predators.size(); ++i) {

		predators[i].move(tile, columns, rows);

		// If didn't breed yet this turn try to
		if (predators[i].canBreed()) {
			predators[i].breed(tile);
		}

		// The eating part
		if (!predators[i].eat(tile, animals)) {
			predators[i].incrementHunger();
			if (predators[i].isDead()) {
				// this predator died from hunger
				--tile[predators[i].getX()][predators[i].getY()];
				std::cout << "\tand died from hunger\n";
				predators.erase(predators.begin() + i);
				predators.shrink_to_fit();
				--i; // correcting iteration now that's one element is gone
			}
		}
	}
}

void resetBreed(std::vector<Animal>& animals, std::vector<Predator>& predators) {

	// Resetting breeding
	for (auto& element : animals) {
		element.setBreed(0);
	}
	for (auto& element : predators) {
		element.setBreed(0);
	}
}

void simulate(int** tile, std::vector<Animal>& animals, std::vector<Predator>& predators, int columns, int rows, int turn) {

	std::cout << "\tTURN: " << turn << '\n' << '\n';

	animalPhase(tile, animals, columns, rows);

	predatorPhase(tile, animals, predators, columns, rows);

	printWorld(tile, columns, rows); // how our world looks after resolving everything in turn

	resetBreed(animals, predators);

}