// wildlife_simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "global.h"
#include "classes.h"
#include "functions.h"
#include <iostream>
#include <random> // for std::mt19937
#include <ctime> // for std::time
#include <vector>

int main() {
	std::vector<Animal*> animals;
	std::vector<Predator*> predators;
	int maxTurns;
	// Entering world size
	std::cout << "Please note that entering too many columns will look ugly.\n";
	std::cout << "Enter a number of rows: ";
	std::cin >> global::rows;
	std::cout << "Enter a number of columns: ";
	std::cin >> global::columns;
	int** global::tile = new int* [global::rows]; // allocate an array of 10 int pointers — these are our rows
	for (int i = 0; i < global::rows; ++i)
		global::tile[i] = new int[global::columns]; // these are our columns
	//std::vector<std::vector<int>> tile{};

	// assign "0" to each tile
	for (int r = 0; r < global::rows; ++r) {
		for (int c = 0; c < global::columns; ++c) {
			tile[r][c] = 0;
		}
	}
	printWorld(tile);
	
	// Entering the amount of animals
	int numAnimals, numPredators;
	std::cout << "How many non-predators to spawn? ";
	std::cin >> numAnimals;
	std::cout << "How many predators to spawn? ";
	std::cin >> numPredators;

	// Putting animals into their respective vectors
	// Non-predators first
	animals.resize(numAnimals);
	for (int i = 0; i < numAnimals; ++i) {
		animals[i] = new Animal(static_cast<Animal::Sex>(getRandomNumber(0, 1)), getRandomNumber(0, global::columns), getRandomNumber(0, global::rows));
	}

	// And now the predators
	predators.resize(numPredators);
	for (int i = 0; i < numPredators; ++i) {
		predators[i] = new Predator(static_cast<Animal::Sex>(getRandomNumber(0, 1)), getRandomNumber(0, global::columns), getRandomNumber(0, global::rows));
	}

	// Entering a maximum number of turns
	std::cout << "Enter the maximum number of turns: ";
	std::cin >> maxTurns;

	/*
	std::cout << "\nDices:\n";
	std::cout << getRandomNumber(1, 6) << '\n';
	std::cout << getRandomNumber(1, 10) << '\n';
	std::cout << getRandomNumber(1, 20) << '\n';
	*/
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
