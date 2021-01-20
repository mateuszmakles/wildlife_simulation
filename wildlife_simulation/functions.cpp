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

bool validateInt(int input, int min) {

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