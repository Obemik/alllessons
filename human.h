#ifndef HUMAN_H
#define HUMAN_H

#include "logger.h"

class Human
{
	string _get_object_as_string() const;
public:
	string fullName;
	int age = 0;
	Human();
	Human(string name);
	Human(string name, int age);
	explicit Human(const char* name);
	void printName() const;
	~Human();

	//opearator incriment(++human)
	Human operator++()
	{
		Logger::debug("Call overloaded operator ++ ");
		this->age += 1; // new state
		return *this; // return new state
	}

	//opearator incriment(human++)
	Human operator++(int)
	{
		Logger::debug("Call overloaded operator ++ ");
		Human human = *this; //old state save
		this->age += 1; // new state
		return human; // return old state
	}

	//opearator decriment(--human)
	Human operator--()
	{
		Logger::debug("Call overloaded operator -- ");
		this->age -= 1; // new state
		return *this; // return new state
	}

	//opearator decriment(human--)
	Human operator--(int)
	{
		Logger::debug("Call overloaded operator -- ");
		Human human = *this;
		this->age -= 1;
		return human;
	}

	Human operator+(Human other_human)
	{
		Logger::debug("Call overloaded operator + ");
		Human human;
		human.fullName = this->fullName + " " + other_human.fullName;
		human.age = (this->age + other_human.age) / 2;
		return human;
	}

	bool operator==(Human other_human)
	{
		Logger::debug("Call overloaded operator == ");
		return this->fullName == other_human.fullName && this->age == other_human.age;
	}
};
#endif