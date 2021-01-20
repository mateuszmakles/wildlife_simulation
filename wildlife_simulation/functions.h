#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Forward declarations for global functions

int getRandomNumber(int min, int max);

int validateInt(std::string_view str, int min);

void printWorld(int** tile, int columns, int rows);

void animalPhase(int** tile, std::vector<Animal>& animals, int columns, int rows);

void predatorPhase(int** tile, std::vector<Animal>& animals, std::vector<Predator>& predators, int columns, int rows);

void resetBreed(std::vector<Animal>& animals, std::vector<Predator>& predators);

void simulate(int** tile, std::vector<Animal>& animals, std::vector<Predator>& predators, int columns, int rows, int turn);

#endif