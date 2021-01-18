#ifndef CLASSES_H
#define CLASSES_H

#include <vector>

// Forward declarations for classes

class Animal {
public:
	enum class Sex {
		male,
		female,

		MAX
	};
protected:
	Sex gender;
	int x, y;
public:
	Animal(int** tile, Sex g, int xx, int yy) : gender{ g }, x{ xx }, y{ yy } {
		++tile[x][y];
	}
};

class Predator : public Animal {
public:
	Predator(int** tile, Sex g, int xx, int yy) : Animal{ tile,g,xx,yy } {}
};

class Tiles {
	std::vector<std::vector<int>> animalCount;
	std::vector<std::vector<std::vector<Animal*>>> animals;
public:
	Tiles(int rows, int columns) {
		for (int r = 0; r < rows; ++r) {
			for (int c = 0; c < columns; ++c) {
				animalCount[r][c] = 0;
				animals[r][c][0] = nullptr;
			}
		}
	}
};

#endif