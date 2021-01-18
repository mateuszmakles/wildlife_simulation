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
	Animal(int** tile, Sex g, int xx, int yy); // forward declaration

	int getX() const { return x; }
	int getY() const { return y; }

	void moveX(int xx) { x+=xx; }
	void moveY(int yy) { y+=yy; }
};

class Predator : public Animal {
public:
	Predator(int** tile, Sex g, int xx, int yy); // forward declaration
	// I know this constructor is trivial but I wanted to keep consistency with Animal's constructor
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