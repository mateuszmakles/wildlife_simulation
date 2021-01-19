#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Forward declarations for global functions

int getRandomNumber(int min, int max);

void printWorld(int** tile, int columns, int rows);

void moveAnimals(int** tile, std::vector<Animal*>& animals, int columns, int rows);

#endif