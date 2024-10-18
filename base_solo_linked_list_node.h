#ifndef BASE_SOLO_NODE
#define BASE_SOLO_NODE

#include "base_node.h"

template <typename T>
class BaseSoloLinkedListNode : public BaseNode<T>, public INext<T>
{
protected:
	BaseSoloLinkedListNode<T>* _next;
	T _value;
public:
	BaseSoloLinkedListNode()
	{
		this->_value = T();
		this->_next = nullptr;
	}
	BaseSoloLinkedListNode(T value)
	{
		this->_value = value;
		this->_next = nullptr;
	}
	BaseSoloLinkedListNode(T value, BaseSoloLinkedListNode<T>* next)
	{
		this->_value = value;
		this->_next = next;
	}

	//Getters and setters
	T getValue() const override
	{
		return this->_value;
	}
	void setValue(T value) override
	{
		this->_value = value;
	}
	BaseSoloLinkedListNode<T>* getNext() const override
	{
		return this->_next;
	}
	void setNext(BaseSoloLinkedListNode<T>* next)
	{
		this->_next = next;
	}

	virtual ~BaseSoloLinkedListNode()
	{
		if (this->_next != nullptr)
		{
			delete this->_next;
		}
	}
};


#endif // !BASE_SOLO_NODE