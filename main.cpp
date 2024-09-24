#include <iostream>
#include <string>
#include <sstream> //for std::stringstream 
#include <Windows.h>

using namespace std;

struct ProjectConsts
{
    static const size_t empty_size = 0;
    static const size_t default_allocated_memory = 25;
};

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

struct Logger
{
    static bool is_print_logs;
    static const unsigned short _debug = 10;
    static const unsigned short _info = 11;
    static const unsigned short _error = 12;
    static const unsigned short _warning = 14;
    static const unsigned short _default = 7;

    static void debug(string message)
    {
        if (is_print_logs)
        {
            SetConsoleTextAttribute(hConsole, _debug);
            cout << "DEBUG: " << message << endl;
            SetConsoleTextAttribute(hConsole, _default);
        }
    }

    static void info(string message)
    {
        if (is_print_logs)
        {

            SetConsoleTextAttribute(hConsole, _info);
            cout << "INFO: " << message << endl;
            SetConsoleTextAttribute(hConsole, _default);
        }
    }
    static void error(string message)
    {
        if (is_print_logs)
        {
            SetConsoleTextAttribute(hConsole, _error);
            cout << "ERROR: " << message << endl;
            SetConsoleTextAttribute(hConsole, _default);
        }
    }
    static void warning(string message)
    {
        if (is_print_logs)
        {
            SetConsoleTextAttribute(hConsole, _warning);
            cout << "WARNING: " << message << endl;
            SetConsoleTextAttribute(hConsole, _default);
        }

    }
};

bool Logger::is_print_logs = false;

class Human
{
    string _get_object_as_string() const
    {
        stringstream ss;
        ss << "Human object <" << (void**)this << ">";
        return ss.str();
    }
public:
    string fullName;
    Human()
    {
        Logger::debug(_get_object_as_string() + " created default");
    }
    Human(string name)
    {
        Logger::debug("Human created with custom name");
        fullName = name;
    }
    inline void printName() const
    {
        cout << "Name: " << fullName << endl;
    }

    ~Human()
    {
        Logger::error(_get_object_as_string() + " deleted");
    }
};

class Queue
{
    Human* _queue = nullptr;
    size_t* _size = nullptr;
    size_t* _allocated_memory = nullptr;

    string _get_object_as_string() const
    {
        stringstream ss;
        ss << "Queue object <" << (void**)this << ">";
        return ss.str();
    }
public:
    Queue()
    {
        _size = new size_t{ ProjectConsts::empty_size };
        _allocated_memory = new size_t{ ProjectConsts::default_allocated_memory };
        _queue = new Human[*_allocated_memory];

        Logger::debug(_get_object_as_string() + " created with default allocated memory");
    }
    Queue(size_t allocated_memory)
    {
        _size = new size_t{ ProjectConsts::empty_size };
        _allocated_memory = new size_t{ allocated_memory };
        _queue = new Human[*_allocated_memory];
        Logger::debug(_get_object_as_string() + " with custom allocated memory");
    }
    Queue(size_t* allocated_memory) : Queue(*allocated_memory)
    {}

    void allocate_new_memory()
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

    inline void analyze_memory()
    {
        Logger::info("Analyzing memory");
        if (*_size == *_allocated_memory)
        {
            Logger::warning("Memory is full, allocating new memory");
            allocate_new_memory();
        }
    }

    void push(Human human)
    {
        Logger::info("Pushing human to queue");
        analyze_memory();
        _queue[*_size] = human;
        (*_size)++;
    }
    void push(Human* human)
    {
        Logger::info("Pushing human to queue");
        analyze_memory();
        _queue[*_size] = *human;
        (*_size)++;
    }

    inline void print_all() const
    {
        Logger::info("Printing all humans in queue");
        for (size_t i = 0; i < *_size; i++)
        {
            _queue[i].printName();
        }
    }

    ~Queue()
    {
        Logger::error("Queue deleted");
        delete[] _queue;
        Logger::error("Size deleted");
        delete _size;
        Logger::error("Allocated_memory deleted");
        delete _allocated_memory;
    }
};

int main()
{
    Logger::is_print_logs = true;
    Queue* human_queue = new Queue(3);

    human_queue->push(new Human("John Doe"));
    human_queue->push(new Human("Jane Doe"));
    human_queue->push(new Human("Alex Smith"));
    human_queue->push(new Human("Michael Johnson"));
    human_queue->push(new Human("Samantha Johnson"));

    human_queue->print_all();

    delete human_queue;
}