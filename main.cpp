#include "logger.h"

class Base
{
protected:
	int value;
public:
	Base()
	{
		Logger::info("Base constructor");
		value = 0;
	}
	Base(int value)
	{
		Logger::info("Base constructor with value");
		this->value = value;
	}

	virtual void get_value()
	{
		cout << "Value from Base: " << value << endl;
	}

	virtual ~Base()
	{
		Logger::info("Base destructor");
	}
};

class LeftChild : public Base
{
protected:
	int number;
public:
	LeftChild()
	{
		Logger::warning("LeftChild constructor");
	}
	LeftChild(int value) : Base(value)
	{
		Logger::warning("LeftChild constructor with value");
		number = 5;
	}

	virtual void get_value()
	{
		cout << "Value from LeftChild: " << value << endl;
	}
	virtual ~LeftChild()
	{
		Logger::warning("LeftChild destructor");
	}
};

class RightChild : public Base
{
protected:
	int number;
public:
	RightChild()
	{
		Logger::warning("RightChild constructor");
	}
	RightChild(int value) : Base(value)
	{
		number = 10;
		Logger::warning("RightChild constructor with value");
	}
	virtual void get_value()
	{
		cout << "Value from RightChild: " << value << endl;
	}
	virtual ~RightChild()
	{
		Logger::warning("RightChild destructor");
	}
};

class Child : public LeftChild, public RightChild
{
public:
	Child()
	{
		Logger::debug("Child constructor");
	}
	Child(int value) : LeftChild(value), RightChild(value)
	{
		Logger::debug("Child constructor with value");
	}
	void get_value() override
	{
		if (this->LeftChild::value > 20)
		{
			cout << "Value from Child(LeftChild): " << LeftChild::number << endl;
		}
		else
		{
			cout << "Value from Child(RightChild): " << RightChild::number << endl;
		}

	}
	virtual ~Child()
	{
		Logger::debug("Child destructor");
	}
};



bool Logger::is_print_logs = true;

int main() {
	Base* base = new Base(10);
	cout << endl;
	Base* left_child = new LeftChild(20);
	cout << endl;
	Base* right_child = new RightChild(30);
	cout << endl;
	LeftChild* child = new Child(10);
	cout << endl;

	base->get_value();
	left_child->get_value();
	right_child->get_value();
	child->get_value();

	cout << endl;
	delete base;
	cout << endl;
	delete left_child;
	cout << endl;
	delete right_child;
	cout << endl;
	delete child;
	cout << endl;
	return 0;
}