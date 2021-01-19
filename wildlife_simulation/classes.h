#ifndef CLASSES_H
#define CLASSES_H

#include <string_view>
#include <vector>

// Forward declarations for classes

class Animal {
	std::vector<Animal>* vector{ 0 };
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

	Sex getGender() const { return gender; }
	int getX() const { return x; }
	int getY() const { return y; }
	virtual std::string_view printInfo() const { return (gender == Sex::male ? "Animal (male)\t" : "Animal (female)\t"); }
	bool compare(const Animal& a) const { return (gender != a.getGender() && a.canBreed()); }
	bool canBreed() const { return hasBred == 0; }

	void moveX(int dir) { x+=dir; }
	void moveY(int dir) { y+=dir; }
	void setBreed(bool b) { hasBred = b; }

	void move(int** tile, int columns, int rows); // forward declaration
	virtual void breed(int** tile); // forward declaration
};

class Predator : public Animal {
	std::vector<Predator>* pvector;
	int hunger; // predator dies when it reaches 2
public:
	Predator(int** tile, std::vector<Predator>& vect, int xx, int yy); // forward declaration
	// I know this constructor is trivial but I wanted to keep consistency with Animal's constructor

	void incrementHunger() { ++hunger; }
	bool isDead() { return (hunger >= 2); }
	std::string_view printInfo() const override { return (gender == Sex::male ? "Predator (male) \t" : "Predator (female) \t"); }

	void breed(int** tile) override; // forward declaration
	bool eat(int** tile, std::vector<Animal>& animals); // forward declaration
};

#endif