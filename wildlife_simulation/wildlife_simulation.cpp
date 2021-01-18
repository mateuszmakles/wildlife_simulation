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
	std::cout << "Enter a number of columns: ";
	std::cin >> global::columns;
	std::cout << "Enter a number of rows: ";
	std::cin >> global::rows;
	int** tile = new int* [global::columns]; // allocate an array of 10 int pointers — these are our rows
	for (int i = 0; i < global::columns; ++i) {
		tile[i] = new int[global::rows]; // these are our columns
	}

	for (int c = 0; c < global::columns; ++c) {
		for (int r = 0; r < global::rows; ++r) {
			tile[c][r] = 0;
		}
	}
	printWorld(tile, global::columns, global::rows);
	
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
		animals[i] = new Animal(tile, static_cast<Animal::Sex>(getRandomNumber(0, 1)), getRandomNumber(0, global::columns - 1), getRandomNumber(0, global::rows - 1));
	}

	// And now the predators
	predators.resize(numPredators);
	for (int i = 0; i < numPredators; ++i) {
		predators[i] = new Predator(tile, static_cast<Animal::Sex>(getRandomNumber(0, 1)), getRandomNumber(0, global::columns - 1), getRandomNumber(0, global::rows - 1));
	}
	printWorld(tile, global::columns, global::rows);

	// Entering a maximum number of turns
	std::cout << "Enter the maximum number of turns: ";
	//std::cin >> maxTurns;

	/*
	std::cout << "\nDices:\n";
	std::cout << getRandomNumber(1, 6) << '\n';
	std::cout << getRandomNumber(1, 10) << '\n';
	std::cout << getRandomNumber(1, 20) << '\n';
	*/
	//for (int i = 0; i < global::columns; ++i)
	//	delete[] tile[i];
	//delete[] tile; // this needs to be done last

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
