//#include <iostream>
//#include <Windows.h>
//#include <string>
//using namespace std;
//
//class Pet
//{
//private:
//	string _name;
//	string _type;
//	int _age;
//public:
//	Pet()
//	{
//		_name = "NULL";
//		_type = "NULL";
//		_age = 0;
//	}
//	Pet(string name) : Pet()
//	{
//		_name = name;
//	}
//	Pet(string name, string type) : Pet(name)
//	{
//		_type = type;
//	}
//	Pet(string name, string type, int age) : Pet(name, type)
//	{
//		_age = age;
//	}
//
//	Pet(const Pet& pet)
//	{
//		this->_age = pet._age;
//		this->_name = pet._name;
//		this->_type = pet._type;
//	}
//	/*Pet(Pet&& pet)
//	{
//		this->_age = pet._age;
//		this->_name = pet._name;
//		this->_type = pet._type;
//
//		pet._age = 0;
//		pet._name = "NULL";
//		pet._type = "NULL";
//	}
//
//
//	Pet& operator=(Pet&& pet)
//	{
//		pet._age = 0;
//		pet._name = "NULL";
//		pet._type = "NULL";
//		cout << "Move assignment called" << endl;
//		return *this;
//	}*/
//
//	void set_name(string name)
//	{
//		_name = name;
//	}
//
//	void about()
//	{
//		cout << "Name: " << _name << endl;
//		cout << "Type: " << _type << endl;
//		cout << "Age: " << _age << endl;
//	}
//};
//
//int main()
//{
//	cout << "Count of pets->";
//	int count;
//	cin >> count;
//	Pet* pets = new Pet[count];
//	cin.ignore();
//	for (size_t i = 0; i < count; i++)
//	{
//		string name;
//		string type;
//		int age;
//		cout << "Name->";
//		getline(cin, name);
//		cout << "Type->";
//		getline(cin, type);
//		cout << "Age->";
//		cin >> age;
//		pets[i] = Pet(name, type, age);
//		cin.ignore();
//	}
//
//	for (size_t i = 0; i < count; i++)
//	{
//		pets[i].about();
//	}
//
//	delete[] pets;
//	return 0;
//}









//#include <iostream>
//#include <Windows.h>
//#include <string>
//using namespace std;
//
//class Pet
//{
//private:
//	string _name;
//	string _type;
//	int _age;
//public:
//	Pet()
//	{
//		_name = "NULL";
//		_type = "NULL";
//		_age = 0;
//	}
//	Pet(string name) : Pet()
//	{
//		_name = name;
//	}
//	Pet(string name, string type) : Pet(name)
//	{
//		_type = type;
//	}
//	Pet(string name, string type, int age) : Pet(name, type)
//	{
//		_age = age;
//	}
//
//	Pet(const Pet& pet)
//	{
//		this->_age = pet._age;
//		this->_name = pet._name;
//		this->_type = pet._type;
//	}
//	/*Pet(Pet&& pet)
//	{
//		this->_age = pet._age;
//		this->_name = pet._name;
//		this->_type = pet._type;
//
//		pet._age = 0;
//		pet._name = "NULL";
//		pet._type = "NULL";
//	}
//
//
//	Pet& operator=(Pet&& pet)
//	{
//		pet._age = 0;
//		pet._name = "NULL";
//		pet._type = "NULL";
//		cout << "Move assignment called" << endl;
//		return *this;
//	}*/
//
//	void set_name(string name)
//	{
//		_name = name;
//	}
//
//	void about()
//	{
//		cout << "Name: " << _name << endl;
//		cout << "Type: " << _type << endl;
//		cout << "Age: " << _age << endl;
//	}
//};
//
//int main()
//{
//	cout << "Count of pets->";
//	int count;
//	cin >> count;
//	Pet* pets = new Pet[count];
//	cin.ignore();
//	for (size_t i = 0; i < count; i++)
//	{
//		string name;
//		string type;
//		int age;
//		cout << "Name->";
//		getline(cin, name);
//		cout << "Type->";
//		getline(cin, type);
//		cout << "Age->";
//		cin >> age;
//		pets[i] = Pet(name, type, age);
//		cin.ignore();
//	}
//
//	for (size_t i = 0; i < count; i++)
//	{
//		pets[i].about();
//	}
//
//	delete[] pets;
//	return 0;
//}






//#include <iostream>
//#include <Windows.h>
//#include <string>
//using namespace std;
//
//class Pet
//{
//private:
//    string _name;
//    string _type;
//    int _age;
//public:
//    Pet()
//    {
//        _name = "NULL";
//        _type = "NULL";
//        _age = 0;
//    }
//    Pet(string name) : Pet()
//    {
//        _name = name;
//    }
//    Pet(string name, string type) : Pet(name)
//    {
//        _type = type;
//    }
//    Pet(string name, string type, int age) : Pet(name, type)
//    {
//        _age = age;
//    }
//
//    Pet(const Pet& pet)
//    {
//        this->_age = pet._age;
//        this->_name = pet._name;
//        this->_type = pet._type;
//    }
//    /*Pet(Pet&& pet)
//    {
//        this->_age = pet._age;
//        this->_name = pet._name;
//        this->_type = pet._type;
//
//        pet._age = 0;
//        pet._name = "NULL";
//        pet._type = "NULL";
//    }
//
//
//    Pet& operator=(Pet&& pet)
//    {
//        pet._age = 0;
//        pet._name = "NULL";
//        pet._type = "NULL";
//        cout << "Move assignment called" << endl;
//        return *this;
//    }*/
//
//    void set_name(string name)
//    {
//        _name = name;
//    }
//
//    void about()
//    {
//        cout << "Name: " << _name << endl;
//        cout << "Type: " << _type << endl;
//        cout << "Age: " << _age << endl;
//    }
//};
//
//int main()
//{
//    cout << "Count of pets->";
//    int count;
//    cin >> count;
//    Pet* pets = new Pet[count];
//    cin.ignore();
//    for (size_t i = 0; i < count; i++)
//    {
//        string name;
//        string type;
//        int age;
//        cout << "Name->";
//        getline(cin, name);
//        cout << "Type->";
//        getline(cin, type);
//        cout << "Age->";
//        cin >> age;
//        pets[i] = Pet(name, type, age);
//        cin.ignore();
//    }
//
//    for (size_t i = 0; i < count; i++)
//    {
//        pets[i].about();
//    }
//
//    delete[] pets;
//    return 0;
//}










//#include <iostream>
//#include <Windows.h>
//#include <string>
//using namespace std;
//
//class Pet
//{
//private:
//    string _name;
//    string _type;
//    int _age;
//public:
//    Pet()
//    {
//        _name = "NULL";
//        _type = "NULL";
//        _age = 0;
//    }
//    Pet(string name) : Pet()
//    {
//        _name = name;
//    }
//    Pet(string name, string type) : Pet(name)
//    {
//        _type = type;
//    }
//    Pet(string name, string type, int age) : Pet(name, type)
//    {
//        _age = age;
//    }
//
//    Pet(const Pet& pet)
//    {
//        this->_age = pet._age;
//        this->_name = pet._name;
//        this->_type = pet._type;
//    }
//
//    void set_name(string name)
//    {
//        _name = name;
//    }
//
//    void about()
//    {
//        cout << "Name: " << _name << endl;
//        cout << "Type: " << _type << endl;
//        cout << "Age: " << _age << endl;
//    }
//
//    void log()
//    {
//        cout << "Pet: " << _name << " " << _type << " " << _age << endl;
//    }
//};
//
//class PetProvider
//{
//private:
//    Pet* _pets = nullptr;
//    int _count;
//public:
//    PetProvider()
//    {
//        _count = 0;
//        _pets = new Pet[_count + 1];
//    }
//    PetProvider(int count)
//    {
//        _count = count;
//        _pets = new Pet[count];
//    }
//
//    void add_pet(Pet pet)
//    {
//        Pet* temp = new Pet[_count + 1];
//        for (size_t i = 0; i < _count; i++)
//        {
//            temp[i] = _pets[i];
//        }
//        temp[_count] = pet;
//        delete[] _pets;
//        _pets = temp;
//        _count++;
//        cout << "Pet added: ";
//        pet.log();
//        cout << endl;
//    }
//
//    void print_pets()
//    {
//        for (size_t i = 0; i < _count; i++)
//        {
//            _pets[i].about();
//        }
//    }
//
//    ~PetProvider()
//    {
//        delete[] _pets;
//    }
//};
//
//int main()
//{
//    PetProvider provider;
//    provider.add_pet(Pet("Name 1", "Type 1", 12));
//    cout << endl;
//    provider.print_pets();
//    cout << endl;
//    provider.add_pet(Pet("Name 2", "Type 2", 12));
//    provider.print_pets();
//    return 0;
//}