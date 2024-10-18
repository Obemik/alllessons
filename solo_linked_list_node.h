#ifndef SOLO_NODE
#define SOLO_NODE

#include "base_solo_linked_list_node.h"


template <typename T>
class SoloLinkedListNode : public BaseSoloLinkedListNode<T>
{
public:
	SoloLinkedListNode() : BaseSoloLinkedListNode<T>()
	{
	}
	SoloLinkedListNode(T value) : BaseSoloLinkedListNode<T>(value)
	{
	}
	SoloLinkedListNode(T value, SoloLinkedListNode<T>* next) : BaseSoloLinkedListNode<T>(value, next)
	{
	}
	~SoloLinkedListNode()
	{
		if (this->getNext() != nullptr)
		{
			delete this->getNext();
		}
	}
};


#endif // !SOLO_NODE