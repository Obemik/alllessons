#include "logger.h"
#include <sstream>

struct Student
{
private:
	//text
	string _name;
	string _surname;
	string _gender;
	string _email;
	string _phone;

	//digits
	int _age;
	int _id;
	float _avg_mark;
	float _avg_attendance;

	string _get_object_as_string() const
	{
		stringstream ss;
		ss << "Student object <" << (void**)this << ">";
		return ss.str();
	}

	void set_default_object()
	{
		_name = "NULL";
		_surname = "NULL";
		_gender = "NULL";
		_email = "NULL";
		_phone = "NULL";

		_age = NULL;
		_id = NULL;
		_avg_mark = NULL;
		_avg_attendance = NULL;
	}
public:
	Student() //Constructor - default
	{
		Logger::log("Call default constructor of " + _get_object_as_string(), Colors::GREEN);
		set_default_object();
	}
	Student(string name) : Student()
	{
		Logger::log("Call constructor with param <NAME> of " + _get_object_as_string(), Colors::GREEN);
		set_name(name);
	}
	Student(string name, string surname) : Student(name)
	{
		Logger::log("Call constructor with param <NAME, SURNAME> of " + _get_object_as_string(), Colors::GREEN);
		set_surname(surname);
	}
	Student(string name, string surname, string gender) : Student(name, surname)
	{
		Logger::log("Call constructor with param <NAME, SURNAME, GENDER> of " + _get_object_as_string(), Colors::GREEN);
		set_gender(gender);
	}
	Student(string name, string surname, string gender, string email) : Student(name, surname, gender)
	{
		Logger::log("Call constructor with param <NAME, SURNAME, GENDER, EMAIL> of " + _get_object_as_string(), Colors::GREEN);
		set_email(email);
	}
	Student(string name, string surname, string gender, string email, string phone) : Student(name, surname, gender, email)
	{
		Logger::log("Call constructor with param <NAME, SURNAME, GENDER, EMAIL, PHONE> of " + _get_object_as_string(), Colors::GREEN);
		set_phone(phone);
	}


	//Setters
	void set_name(string name) { _name = name; }
	void set_surname(string surname) { _surname = surname; }
	void set_gender(string gender) { _gender = gender; }
	void set_email(string email) { _email = email; }
	void set_phone(string phone) { _phone = phone; }

	void set_age(int age) { _age = age; }
	void set_id(int id) { _id = id; }
	void set_avg_mark(int avg_mark) { _avg_mark = avg_mark; }
	void set_avg_attendance(int avg_attendance) { _avg_attendance = avg_attendance; }

	//Getters
	string get_name()const { return _name; }
	string get_surname()const { return _surname; }
	string get_gender() const { return _gender; }
	string get_email()const { return _email; }
	string get_phone() const { return _phone; }

	int get_age() const { return _age; }
	int get_id()const { return _id; }
	int get_avg_mark()const { return _avg_mark; }
	int get_avg_attendance()const { return _avg_attendance; }

	void about()
	{
		cout << "Student info: " << endl;
		cout << "Name: " << get_name() << endl;
		cout << "Surname: " << get_surname() << endl;
		cout << "Gender: " << get_gender() << endl;
		cout << "Email: " << get_email() << endl;
		cout << "Phone: " << get_phone() << endl;
		cout << "Age: " << get_age() << endl;
		cout << "ID: " << get_id() << endl;
		cout << "Average mark: " << get_avg_mark() << endl;
		cout << "Average attendance: " << get_avg_attendance() << endl;
	}


	~Student() //Destructor
	{
		Logger::log("Call destructor of " + _get_object_as_string(), Colors::RED);
	}
};

bool Logger::is_print_logs = true;

int main()
{
	//Create
	Student* student = new Student("Alex", "Bushon", "Male", "alex.b@gmail.com", "+9847474747474");
	cout << endl;

	//Logic
	student->about();

	//Delete
	cout << endl;
	delete student;
	return 0;
}