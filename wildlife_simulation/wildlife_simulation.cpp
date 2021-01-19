// wildlife_simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "classes.h"
#include "functions.h"
#include <iostream>
#include <vector>

int main() {

	// Variable declarations
	std::vector<Animal> animals;
	std::vector<Predator> predators;
	int columns, rows, numOfAnimals, numOfPredators, maxTurns, turn = 0;

	// Entering world size
	std::cout << "For simplicity, all non-predators will be referred simply to animals.\n";
	std::cout << "Please note that entering too many columns will make printed world look ugly.\n\n";
	std::cout << "Enter a number of columns: ";
	std::cin >> columns;
	std::cout << "Enter a number of rows:    ";
	std::cin >> rows;

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
	
	// Entering the amount of animals
	std::cout << "How many non-predators to spawn? ";
	std::cin >> numOfAnimals;
	std::cout << "How many predators to spawn?     ";
	std::cin >> numOfPredators;

	// Putting animals into their respective vectors
	// Non-predators first
	animals.reserve(numOfAnimals);
	for (int i = 0; i < numOfAnimals; ++i) {
		animals.push_back(Animal(tile, static_cast<Animal::Sex>(getRandomNumber(0, 1)), getRandomNumber(0, columns - 1), getRandomNumber(0, rows - 1)));
		//animals[i] = Animal(tile, static_cast<Animal::Sex>(getRandomNumber(0, 1)), getRandomNumber(0, columns - 1), getRandomNumber(0, rows - 1));
	}

	// And now the predators
	predators.reserve(numOfPredators);
	for (int i = 0; i < numOfPredators; ++i) {
		predators.push_back(Predator(tile, static_cast<Animal::Sex>(getRandomNumber(0, 1)), getRandomNumber(0, columns - 1), getRandomNumber(0, rows - 1)));
		//predators[i] = Predator(tile, static_cast<Animal::Sex>(getRandomNumber(0, 1)), getRandomNumber(0, columns - 1), getRandomNumber(0, rows - 1));
	}

	// Numbers on tiles indicate how many animals are there
	printWorld(tile, columns, rows);

	// Entering a maximum number of turns
	//std::cout << "Enter the maximum number of turns: ";
	//std::cin >> maxTurns;

	for (int i = 0; i < 5; ++i) {
		for (int i = 0; i < animals.size(); ++i) {
			animals[i].move(tile, columns, rows);

			// If didn't breed yet this turn try to
			if (animals[i].canBreed()) {
				animals[i].breed(tile, animals);
			}
		}
		for (int i = 0; i < predators.size(); ++i) {
			predators[i].move(tile, columns, rows);
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
		printWorld(tile, columns, rows);

		// Resetting breeding
		for (auto& element : animals) {
			element.setBreed(0);
		}
		for (auto& element : predators) {
			element.setBreed(0);
		}
	}

	// Deallocating our 2D tiles array
	for (int i = 0; i < columns; ++i) {
		delete[] tile[i];
	}
	delete[] tile;

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
