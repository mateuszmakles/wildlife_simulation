#include "global.h"
#include <iostream>
#include <random> // for std::mt19937
#include <ctime> // for std::time

int getRandomNumber(int min, int max) {
	// Initialize our mersenne twister with a random seed based on the clock (once at system startup)
	static std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::uniform_int_distribution die{ min, max }; // we can create a distribution in any function that needs it
	return die(mersenne); // and then generate a random number from our global generator
}

void printWorld(int** tile) {
	std::cout << '\n' << ' ';
	for (int i = 0; i < global::columns; ++i) {
		std::cout << ' ' << i;
	}
	std::cout << '\n' << '\n';
	// Printing all tiles (with side coordinates)
	for (int r = 0; r < global::rows; ++r) {
		std::cout << r;
		for (int c = 0; c < global::columns; ++c) {
			std::cout << ' ' << tile[r][c];
		}
		std::cout << '\n' << '\n';
	}
}