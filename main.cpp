#include <iostream>
using namespace std;


enum class ObjectType
{
	NUMBER,
	TEXT,
	BOOL,
	NONE
};

template <typename T>
struct MyObject
{
private:
	int* _id;
	string _info;
	T* _value;
	ObjectType _type;
	string printEnum()
	{
		switch (this->_type)
		{
		case ObjectType::NUMBER:
			return "Number";
		case ObjectType::TEXT:
			return "Text";
		case ObjectType::BOOL:
			return "Bool";
		case ObjectType::NONE:
			return "None";
		}
	}
public:
	MyObject()
	{
		this->_id = nullptr;
		this->_info = "";
		this->_value = nullptr;
		this->_type = ObjectType::NONE;
	}
	MyObject(int id) : MyObject()
	{
		setId(id);
	}
	MyObject(int id, string info) : MyObject(id)
	{
		setInfo(info);
	}
	MyObject(int id, string info, T value) : MyObject(id, info)
	{
		setValue(value);
	}
	MyObject(int id, string info, T value, ObjectType type) : MyObject(id, info, value)
	{
		setType(type);
	}

	void setId(int id)
	{
		this->_id = (this->_id == nullptr) ? new int(id) : &id;
	}
	void setInfo(string info)
	{
		this->_info = info;
	}
	void setValue(T value)
	{
		this->_value = (this->_value == nullptr) ? new T(value) : &value;
	}
	void setType(ObjectType type)
	{
		this->_type = type;
	}
	int getId()
	{
		return (this->_id == nullptr) ? 0 : *this->_id;
	}
	string getInfo()
	{
		return (this->_info.empty()) ? "No info" : this->_info;
	}
	T getValue()
	{
		return (this->_value == nullptr) ? 0 : *this->_value;
	}
	ObjectType getType()
	{
		return this->_type;
	}

	void print()
	{
		cout << "ID: " << getId() << endl;
		cout << "Info: " << getInfo() << endl;
		cout << "Value: " << getValue() << endl;
		cout << "Type: " << printEnum() << endl;
	}
	~MyObject()
	{
		delete this->_id;
		delete this->_value;
	}
};

struct ObjectHandler
{
	template <typename T1, typename T2>
	static bool compare(MyObject<T1>* obj_1, MyObject<T2>* obj_2)
	{
		return (obj_1->getType() == obj_2->getType());
	}
};

int main() {
	MyObject<string>* obj_1 = new MyObject<string>(0, "text", "Value text", ObjectType::TEXT);
	obj_1->print();
	MyObject<int>* obj_2 = new MyObject<int>(1, "number", 23, ObjectType::NUMBER);
	obj_2->print();
	bool result = ObjectHandler::compare<string, int>(obj_1, obj_2);
	cout << "Result: " << result << endl;
	delete obj_1, obj_2;
	return 0;
}