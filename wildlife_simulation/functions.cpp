//#include "global.h"
#include "classes.h"
#include <iostream>
#include <random> // for std::mt19937
#include <ctime> // for std::time

int getRandomNumber(int min, int max) {
	// Initialize our mersenne twister with a random seed based on the clock (once at system startup)
	static std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::uniform_int_distribution roll{ min, max }; // we can create a distribution in any function that needs it
	return roll(mersenne); // and then generate a random number from our global generator
}

//void printWorld(const Tiles& tile) {
void printWorld(int** tile, int columns, int rows) {
	std::cout << '\n' << ' ' << ' ';
	for (int i = 0; i < columns; ++i) {
		std::cout << ' ' << i;
	}
	std::cout << '\n' << '\n' << '\n';
	// Printing all tiles (with coordinates on the side (like in chess))
	for (int r = 0; r < rows; ++r) {
		std::cout << r << ' ';
		for (int c = 0; c < columns; ++c) {
			if (tile[c][r] > 0)
				std::cout << ' ' << tile[c][r];
			else
				std::cout << ' ' << 'O';
		}
		std::cout << '\n' << '\n';
	}
}