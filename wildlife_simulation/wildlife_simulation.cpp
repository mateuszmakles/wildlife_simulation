#include "classes.h"
#include "functions.h"
#include <iostream>
#include <vector>

int main() {

	// Variable declarations
	std::vector<Animal> animals;
	std::vector<Predator> predators;
	int columns, rows, numOfAnimals, numOfPredators, maxTurns, turn = 1;

	// Entering world size
	std::cout << "For simplicity, all non-predators will be referred simply to animals.\n";
	std::cout << "Please note that entering too many columns will make printed world look ugly.\n\n";
	// Ensuring the user won't enter garbage
	columns = validateInt("Enter a number of columns: ", 1);
	rows = validateInt("Enter a number of rows:    ", 1);

	// Allocate a dynamic 2D array to represent our tiles...
	int** tile = new int* [columns];
	for (int i = 0; i < columns; ++i) {
		tile[i] = new int[rows];
	}
	// ...and fill it with zeros
	for (int c = 0; c < columns; ++c) {
		for (int r = 0; r < rows; ++r) {
			tile[c][r] = 0;
		}
	}

	// Let's call this function to see how our world looks
	printWorld(tile, columns, rows);

	// Entering a maximum number of turns
	maxTurns = validateInt("Enter the maximum number of turns: ", 1);
	std::cout << '\n';
	
	// Entering the amount of animals
	numOfAnimals = validateInt("How many non-predators to spawn? ", 0);
	numOfPredators = validateInt("How many predators to spawn?     ", 0);
	std::cout << '\n';

	// Putting animals into their respective vectors
	// Non-predators first
	animals.reserve(numOfAnimals);
	for (int i = 0; i < numOfAnimals; ++i) {
		animals.push_back(Animal(tile, animals, getRandomNumber(0, columns - 1), getRandomNumber(0, rows - 1)));
	}

	// And now the predators
	predators.reserve(numOfPredators);
	for (int i = 0; i < numOfPredators; ++i) {
		predators.push_back(Predator(tile, predators, getRandomNumber(0, columns - 1), getRandomNumber(0, rows - 1)));
	}

	// Numbers on tiles indicate how many animals are there
	printWorld(tile, columns, rows);

	// This is the main part:
	do {

		// Our simulation function
		simulate(tile, animals, predators, columns, rows, turn);

		// Print respective messages if some of the end conditions are met
		if (animals.empty())
			std::cout << "No animals left!\n";
		if (predators.empty())
			std::cout << "No predators left!\n";
		if (turn == maxTurns)
			std::cout << "Final turn reached!\n";

		++turn;

	} while (turn <= maxTurns && !animals.empty() && !predators.empty()); // change this if you want to be able to simulate only one type of animal

	// Deallocating our 2D tiles array after simulation ends
	for (int i = 0; i < columns; ++i) {
		delete[] tile[i];
	}
	delete[] tile;

	return 0;
}
