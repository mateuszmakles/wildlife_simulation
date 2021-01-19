#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <string_view>
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
	std::string name;
	bool hasBred;
public:
	Animal(int** tile, Sex g, int xx, int yy, std::string n = "Animal"); // forward declaration

	Sex getGender() const { return gender; }
	int getX() const { return x; }
	int getY() const { return y; }
	std::string_view getName() const { return name; }
	virtual std::string_view printInfo() const { return (gender == Sex::male ? "Animal (male)" : "Animal (female)"); }
	bool canBreed() const { return hasBred == 0; }

	void moveX(int dir) { x+=dir; }
	void moveY(int dir) { y+=dir; }
	void setBreed(bool b) { hasBred = b; }

	void move(int** tile, int columns, int rows); // forward declaration
	bool compare(const Animal& a) const; // forward declaration
	void breed(int** tile, std::vector<Animal>& others); // forward declaration
};

class Predator : public Animal {
	int hunger; // predator dies when it reaches 2
public:
	Predator(int** tile, Sex g, int xx, int yy); // forward declaration
	// I know this constructor is trivial but I wanted to keep consistency with Animal's constructor

	void incrementHunger() { ++hunger; }
	bool isDead() { return (hunger >= 2); }
	std::string_view printInfo() const override { return (gender == Sex::male ? "Predator (male)" : "Predator (female)"); }

	bool eat(int** tile, std::vector<Animal>& animals); // forward declaration
};

#endif