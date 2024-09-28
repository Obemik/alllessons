#include "queue.h"

Queue::Queue()
{
	_size = new size_t{ ProjectConsts::empty_size };
	_allocated_memory = new size_t{ ProjectConsts::default_allocated_memory };
	_queue = new Human[*_allocated_memory];

	Logger::debug(_get_object_as_string() + " created with default allocated memory");
}
Queue::Queue(size_t allocated_memory)
{
	_size = new size_t{ ProjectConsts::empty_size };
	_allocated_memory = new size_t{ allocated_memory };
	_queue = new Human[*_allocated_memory];
	Logger::debug(_get_object_as_string() + " with custom allocated memory");
}
Queue::Queue(size_t* allocated_memory) : Queue(*allocated_memory)
{}

void Queue::allocate_new_memory()
{
	Human* new_queue = new Human[(*_allocated_memory) * 2];
	for (size_t i = 0; i < *_size; i++)
	{
		new_queue[i] = _queue[i];
	}
	Logger::warning("Copying old memory queue to new memory queue");
	delete[] _queue;
	_queue = new_queue;
	*_allocated_memory *= 2;
	Logger::info("New memory allocated");
}

inline void Queue::analyze_memory()
{
	Logger::info("Analyzing memory");
	if (*_size == *_allocated_memory)
	{
		Logger::warning("Memory is full, allocating new memory");
		allocate_new_memory();
	}
}

void Queue::push(Human human)
{
	Logger::info("Pushing human to queue");
	analyze_memory();
	_queue[*_size] = human;
	(*_size)++;
}
void Queue::push(Human* human)
{
	push(*human);
}

void Queue::print_all() const
{
	Logger::info("Printing all humans in queue");
	for (size_t i = 0; i < *_size; i++)
	{
		_queue[i].printName();
	}
}

string Queue::_get_object_as_string() const
{
	stringstream ss;
	ss << "Queue object <" << (void**)this << ">";
	return ss.str();
}

Queue::~Queue()
{
	Logger::error("Queue deleted");
	delete[] _queue;
	Logger::error("Size deleted");
	delete _size;
	Logger::error("Allocated_memory deleted");
	delete _allocated_memory;
}