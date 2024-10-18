
#include "libarary.h"

template <typename T> class Element {
private:
    int _priority;
    T _value;

public:
    Element() = default;
    Element(int priority, T value) : _priority(priority), _value(value) {}
    ~Element() = default;
    int priority() const { return _priority; }
    T value() const { return _value; }
    void set_priority(int priority) { _priority = priority; }
    void set_value(T value) { _value = value; }
    void show() const {
        cout << "priority: " << _priority << " value: " << _value << endl;
    }
};

template <typename T> class priority_queue {
private:
    Element<T>* _container;
    int back_index;
    int _size;

    void extend_memory(int step_extend = 10) {
        _size += step_extend;
        Element<T>* temp = new Element<T>[_size];
        for (int i = 0; i <= back_index; i++) {
            temp[i] = _container[i];
        }
        delete[] _container;
        _container = temp;
    }

    bool compare(const Element<T>& elem_1, const Element<T>& elem_2) const {
        return (elem_1.priority() < elem_2.priority());
    }

public:
    priority_queue() {
        back_index = -1;
        _size = 10;
        _container = new Element<T>[_size];
    }

    priority_queue(int size) : _size(size), back_index(-1) {
        _container = new Element<T>[size];
    }

    ~priority_queue() { delete[] _container; }

    void push(T elem, int priority = 0) {
        if (isFull()) {
            extend_memory();
        }
        Element<T> element(priority, elem);
        back_index++;
        _container[back_index] = element;

        for (int step = 1; step <= back_index; step++) {
            Element<T> key = _container[step];
            int j = step - 1;

            while (key.priority() > _container[j].priority() && j >= 0) {
                _container[j + 1] = _container[j];
                --j;
            }
            _container[j + 1] = key;
        }
    }

    bool pop() {
        if (isEmpty()) {
            return false;
        }
        else {
            back_index--;
            Element<T>* temp = new Element<T>[_size];
            for (size_t i = 0; i <= back_index; i++) {
                temp[i] = _container[i + 1];
            }
            _container = temp;
            return true;
        }
    }

    T front() const { return _container[0].value(); }

    T back() const { return _container[back_index].value(); }

    void output() const {
        for (int i = 0; i <= back_index; i++) {
            _container[i].show();
        }
    }

    int count() const { return back_index + 1; }

    int memory() const { return _size; }

    bool isEmpty() const { return (back_index < 0) ? true : false; }

    bool isFull() const { return (back_index == _size - 1) ? true : false; }
};