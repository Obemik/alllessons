#include "libarary.h"

template <typename T> class queue {
private:
    T* conatiner;
    T* _front;
    T* _back;
    int back_index;
    int _size;
    void extend_memmory(int step_extend = 10) {
        _size += step_extend;
        T* temp = new T[_size];
        for (int i = 0; i < back_index; i++) {
            temp[i] = conatiner[i];
        }
        delete[] conatiner;
        conatiner = temp;
    }

public:
    queue() {
        back_index = -1;
        _size = 10;
        this->conatiner = new T[_size];
    }
    queue(int size) : conatiner() {
        this->_size = size;
        this->conatiner = new T[size];
    }
    ~queue() = default;
    void push(T elem) {
        if (isFull()) {
            extend_memmory();
        }
        back_index++;
        conatiner[back_index] = elem;
        _back = &conatiner[back_index];
        if (back_index == 0) {
            _front = &conatiner[back_index];
        }
    }
    bool pop() {
        if (isEmpty()) {
            return false;
        }
        else {
            // delete _front;
            back_index--;
            T* temp = new T[_size];
            for (size_t i = 0; i <= back_index; i++) {
                temp[i] = conatiner[i + 1];
            }
            conatiner = temp;
            _front = &conatiner[0];
            return true;
        }
    }
    T* front() { return _front; }
    T* back() { return _back; }
    void output() {
        for (size_t i = 0; i <= back_index; i++) {
            if (conatiner[i] == conatiner[0]) {
                cout << "item[" << i << "] = " << conatiner[i] << " <-[front]" << endl;
            }
            else if (conatiner[i] == conatiner[back_index]) {
                cout << "item[" << i << "] = " << conatiner[i] << " <-[back]" << endl;
            }
            else {
                cout << "item[" << i << "] = " << conatiner[i] << endl;
            }
        }
    }
    int count() { return back_index + 1; }
    int memmory() { return _size; }
    bool isEmpty() { return (back_index <= 0) ? true : false; }
    bool isFull() { return (back_index == _size) ? true : false; }
};