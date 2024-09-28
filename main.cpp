#include "queue.h"

bool Logger::is_print_logs = true;

ostream& operator<<(ostream& os, const Human& human)
{
	os << "Name: " << human.fullName << ", Age: " << human.age;
	return os;
}

istream& operator>>(istream& is, Human& human)
{
	cout << "Enter name: ";
	is >> human.fullName;
	cout << "Enter age: ";
	is >> human.age;
	return is;
}

int main()
{
	/*Queue * human_queue = new Queue(3);

	human_queue->push(new Human("John Doe"));
	human_queue->push(new Human("Jane Doe"));
	human_queue->push(new Human("Alex Smith"));
	human_queue->push(new Human("Michael Johnson"));
	human_queue->push(new Human("Samantha Johnson"));

	human_queue->print_all();

	delete human_queue;*/

	Human human1("John Doe", 25);
	Human human2 = human1++;
	human2++; //+1
	cout << human1 << endl;
	cout << human2 << endl;
	return 0;
}