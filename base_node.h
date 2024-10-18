#ifndef BASE_NODE
#define BASE_NODE

template <typename T>
class BaseNode abstract
{
public:
	virtual void setValue(T value) = 0;
	virtual T getValue() const = 0;
};

template <typename T>
class INext abstract
{
public:
	virtual INext<T>* getNext() const = 0;
	virtual void setNext(INext<T>* next) = 0;
};

//template <typename T>
//class IPrev abstract
//{
//public:
//	IPrev* _prev = nullptr;
//	IPrev() = default;
//	IPrev(IPrev* prev) : _prev(prev) {}
//	virtual ~IPrev() = default;
//	virtual IPrev* getPrev() = 0;
//	virtual void setPrev(IPrev* next) = 0;
//};

#endif // !BASE_NODE