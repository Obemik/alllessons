#ifndef QUEUE_H
#define QUEUE_H

#include "human.h"
#include "const.h"

class Queue
{
	//Fields
	Human* _queue = nullptr;
	size_t* _size = nullptr;
	size_t* _allocated_memory = nullptr;

	//Methods in private
	string _get_object_as_string() const;
public:
	//Constructors
	Queue();
	Queue(size_t allocated_memory);
	Queue(size_t* allocated_memory);

	//Methods
	void allocate_new_memory();
	inline void analyze_memory();
	void push(Human human);
	void push(Human* human);
	void print_all() const;

	//Destructor
	~Queue();
};

#endif // !QUEUE_H