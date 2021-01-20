#ifndef CLASSES_H
#define CLASSES_H

#include <string_view>
#include <vector>

// Forward declarations for classes

class Animal {
	std::vector<Animal>* vector{ 0 }; // points to a vector, which contains our animal
public:
	enum class Sex {
		male,
		female,

		MAX
	};
protected:
	Sex gender;
	int x, y;
	bool hasBred;
public:
	Animal(int** tile, std::vector<Animal>& vect, int xx, int yy); // forward declaration
	Animal(int** tile, int xx, int yy); // forward declaration

	// Access functions
	Sex getGender() const { return gender; }
	int getX() const { return x; }
	int getY() const { return y; }
	virtual std::string_view printInfo() const { return (gender == Sex::male ? "Animal (male)\t" : "Animal (female)\t"); }

	// Manipulating our members
	bool compare(const Animal& a) const { return (gender != a.getGender() && a.canBreed()); }
	bool canBreed() const { return hasBred == 0; }
	void moveX(int dir) { x+=dir; }
	void moveY(int dir) { y+=dir; }
	void setBreed(bool b) { hasBred = b; }

	// Moving and breeding
	void move(int** tile, int columns, int rows); // forward declaration
	virtual void breed(int** tile); // forward declaration
};

// Predator is derived from Animal
class Predator : public Animal {
	std::vector<Predator>* pvector; // points to a vector, which contains our predator
	int hunger; // predator dies when it reaches 2
public:
	Predator(int** tile, std::vector<Predator>& vect, int xx, int yy); // forward declaration

	std::string_view printInfo() const override { return (gender == Sex::male ? "Predator (male) \t" : "Predator (female) \t"); }

	// Food-related functions
	void incrementHunger() { ++hunger; }
	bool isDead() { return (hunger >= 2); }

	// Breeding and eating
	void breed(int** tile) override; // forward declaration
	bool eat(int** tile, std::vector<Animal>& animals); // forward declaration
};

#endif