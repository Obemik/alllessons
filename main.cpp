#include <iostream>
#include <Windows.h>
using namespace std;


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
enum StateType
{
    NEW,
    OLD
};

template<typename T>
class State
{
private:
    int _id;
    string _info;
    T* _value;
    StateType _type;

public:
    State()
    {
        _id = 0;
        _info = "";
        _value = nullptr;
        _type = NEW;
    }
    State(int id) : State()
    {
        _id = id;
    }
    State(int id, string info) : State(id)
    {
        _info = info;
    }
    State(int id, string info, T* value) : State(id, info)
    {
        _value = value;
    }
    State(int id, string info, T* value, StateType type) : State(id, info, value)
    {
        _type = type;
    }

    void clear_value()
    {
        if (_value != nullptr)
        {
            delete _value;
        }
        _value = nullptr;
    }

    void get_state_information()
    {
        (_type == 0) ? SetConsoleTextAttribute(hConsole, 10) : SetConsoleTextAttribute(hConsole, 14);
        cout << "State information : ";
        cout << ((_type == 0) ? "NEW" : "OLD") << endl;
        cout << "ID: " << _id << endl;
        cout << "Info: " << _info << endl;
        cout << "Value: " << *_value << endl;
        //cout << "Type: " << ((_type == 0)? "NEW" : "OLD") << endl;
        SetConsoleTextAttribute(hConsole, 7);
    }

    void update_value(T* value)
    {
        clear_value();
        _value = value;
    }

    T* get_value()
    {
        return _value;
    }

    ~State()
    {
        clear_value();
    }
};

template<typename T>
class Obs
{
private:
    State<T>* _state;
    State<T>* _old_state;
public:
    Obs()
    {
        _state = _old_state = nullptr;
    }
    Obs(State<T>* state) : Obs()
    {
        if (state != nullptr)
        {
            _state = state;
        }
    }
    Obs(State<T>* state, State<T>* old_state) : Obs(state)
    {
        if (old_state != nullptr)
        {
            _old_state = old_state;
        }
    }
    Obs(T value) : Obs()
    {
        _state = new State<T>(0, "T type of State", new T(value), StateType::NEW);
    }
    Obs(T* value) : Obs()
    {
        _state = new State<T>(0, "T type of State", value, StateType::NEW);
    }

    ~Obs()
    {
        if (_state != nullptr)
        {
            delete _state;
        }
        if (_old_state != nullptr)
        {
            delete _old_state;
        }
    }

    void update_state(T* value, int id, string info)
    {
        if (_state != nullptr)
        {
            if (_old_state != nullptr)
                delete _old_state;
            _old_state = _state;
        }
        _state = new State<T>(id, info, value, StateType::NEW);
    }
    void update_state(T* value)
    {
        if (_state != nullptr)
        {
            if (_old_state != nullptr)
                delete _old_state;
            _old_state = _state;
        }
        _state = new State<T>(1, "Empty", value, StateType::NEW);
    }
    void update_state(T value)
    {
        if (_state != nullptr)
        {
            if (_old_state != nullptr)
                delete _old_state;
            _old_state = _state;
        }
        _state = new State<T>(1, "Empty", new T(value), StateType::NEW);
    }
    void update_state(State<T> new_state)
    {
        if (_state != nullptr)
        {
            if (_old_state != nullptr)
                delete _old_state;
            _old_state = _state;
        }
        _state = new_state;
    }

    void show()
    {
        if (_state != nullptr)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << "Value: " << *_state->get_value() << endl;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Value is empty" << endl;
        }
        SetConsoleTextAttribute(hConsole, 7);
    }

    void states_information()
    {
        if (_old_state != nullptr)
            _old_state->get_state_information();
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Old state is empty" << endl;
            SetConsoleTextAttribute(hConsole, 7);
        }

        if (_state != nullptr)
            _state->get_state_information();
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "State is empty" << endl;
            SetConsoleTextAttribute(hConsole, 7);
        }

    }
};

int main()
{
    Obs <int> number(10);
    number.states_information();
    number.update_state(20);
    number.states_information();
    return 0;
}