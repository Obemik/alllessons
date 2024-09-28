#include <iostream>
using namespace std;

class Animal
{
protected:
    string _name;
    string _type;
    int _age;
public:
    Animal()
    {
        _name = "No name";
        _type = "No type";
        _age = -1;
        cout << "Animal created" << endl;
    }
    Animal(string name, string type, int age)
    {
        _name = name;
        _type = type;
        _age = age;
        cout << "Animal created with param" << endl;
    }

    virtual void about()
    {
        cout << "Name: " << _name << endl;
        cout << "Type: " << _type << endl;
        cout << "Age: " << _age << endl;
    }

    virtual ~Animal()
    {
        cout << "Animal destroyed" << endl;
    }
};

class Cat : public Animal
{
public:
    Cat() : Animal()
    {
        cout << "Cat created" << endl;
    }
    Cat(string name, int age) : Animal(name, "Cat", age)
    {
        cout << "Cat created with param" << endl;
    }

    void about() override
    {
        cout << "Name: " << _name << endl;
        cout << "Type: " << _type << endl;
    }

    ~Cat()
    {
        cout << "Cat destroyed" << endl;
    }
};

void print(Animal* animal)
{
    animal->about();
}

int main() {
    Animal* cat = new Cat("Tom", 3);
    Cat* cat2 = new Cat("Alex", 8);
    Animal* animal = new Animal("Dog", "Dog", 5);

    print(cat);
    print(cat2);
    print(animal);

    delete cat;
    return 0;
}