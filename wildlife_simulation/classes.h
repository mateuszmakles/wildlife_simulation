#ifndef CLASSES_H
#define CLASSES_H

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
	Animal(Sex g, int xx, int yy) : gender{ g }, x{ xx }, y{ yy } {}
};

class Predator : public Animal {
public:
	Predator(Sex g, int xx, int yy) : Animal{ g,xx,yy } {}
};

#endif