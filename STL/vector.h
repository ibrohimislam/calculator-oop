#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <math.h>

/**
 * Class vector
 *
 * Kelas vector yang diimplementasi berdasarkan STL C++
 * 
 * @class     vector vector.h "STL/vector.h"
 * @package   STL
 * @brief     Kelas vector yang diimplementasi berdasarkan STL C++
 * @author    Ibrohim Kholilul Islam
 * @version   0.1
 * @date      Maret 2015
 * @warning   -
 * 
 */

template <class T>
class  vector {
public:
    vector();
    vector(unsigned int size);
    vector(unsigned int size, const T & initial);
    vector(const vector<T>& v);
    ~vector();

    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    void push_back(const T& value);
    void pop_back();

    void reserve(unsigned int capacity);
    void resize(unsigned int size);

    T & operator[](unsigned int index) const;
    vector<T> & operator = (const vector<T> &);
    void clear();
private:
    unsigned int _size;
    unsigned int _capacity;
    unsigned int Log;
    T* buffer;
};


template<class T>
vector<T>::vector(): _capacity(0), _size(0), buffer(0), Log(0) {
    // bergeming
}

template<class T>
vector<T>::vector(const vector<T> & v): _size(v._size), Log(v.Log),_capacity(v._capacity) {
    buffer = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        buffer[i] = v.buffer[i];
}

template<class T>
vector<T>::vector(unsigned int size): _size(size), Log(ceil(log((double) size) / log(2.0))), _capacity(1 << Log) {
    buffer = new T[_capacity];
}

template <class T>
bool vector<T>::empty() const {
    return _size == 0;
}

template<class T>
vector<T>::vector(unsigned int size, const T& initial) {
    _size = size;
    Log = ceil(log((double) size) / log(2.0));
    _capacity = 1 << Log;
    buffer = new T [_capacity];
    for (unsigned int i = 0; i < size; i++)
        buffer[i] = initial;
}

template<class T>
vector<T>& vector<T>::operator=(const vector<T> & v) {
    delete[] buffer;
    _size = v._size;
    Log = v.Log;
    _capacity = v._capacity;
    buffer = new T [_capacity];
    for (unsigned int i = 0; i < _size; i++)
        buffer[i] = v.buffer[i];
    return *this;
}

template<class T>
void vector<T>::push_back(const T & v) {
    if (_size >= _capacity) {
        reserve(1 << Log);
        Log++;
    }
    buffer [_size++] = v;
}

template<class T>
void vector<T>::pop_back() {
    _size--;
}

template<class T>
void vector<T>::reserve(unsigned int capacity) {
    T * newBuffer = new T[capacity];

    for (unsigned int i = 0; i < _size; i++)
        newBuffer[i] = buffer[i];

    _capacity = capacity;
    delete[] buffer;
    buffer = newBuffer;
}

template<class T>
unsigned int vector<T>::size() const {
    return _size;
}

template<class T>
void vector<T>::resize(unsigned int size) {
    Log = ceil(log((double) size) / log(2.0));
    reserve(1 << Log);
    _size = size;
}

template<class T>
T& vector<T>::operator[](unsigned int index) const{
    return buffer[index];
}

template<class T>
unsigned int vector<T>::capacity()const {
    return _capacity;
}

template<class T>
vector<T>::~vector() {
    delete[] buffer;
}

template <class T>
void vector<T>::clear() {
    _capacity = 0;
    _size = 0;
    buffer = 0;
    Log = 0;
}
#endif