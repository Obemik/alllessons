#include "human.h"

Human::Human()
{
	Logger::debug(_get_object_as_string() + " created default");
}
Human::Human(string name)
{
	Logger::debug("Human created with custom name");
	fullName = name;
}
Human::Human(string name, int age)
{
	Logger::debug("Human created with custom name and age");
	fullName = name;
	this->age = age;
}
Human::Human(const char* name)
{
	Logger::debug("Human created with custom name");
	fullName = name;
}
void Human::printName() const
{
	cout << "Name: " << fullName << endl;
}

string Human::_get_object_as_string() const
{
	stringstream ss;
	ss << "Human object <" << (void**)this << ">";
	return ss.str();
}

Human::~Human()
{
	Logger::error(_get_object_as_string() + " deleted");
}