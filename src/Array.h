//
// Created by ESCINF on 27/09/2022.
//

#ifndef PROYECTO_1_ARRAY_H
#define PROYECTO_1_ARRAY_H
#define CAPACITY 3
#include "AlmacenaNum.h"

using namespace std;

template<class T>
class Array {
private:
    int k{};
    AlmacenaNum *a[CAPACITY]{};
public:
    Array();
    explicit Array(int n);
    T get(int i);
    int getK() const;
    void setK(int k);
    void add(T* v);
    int size();
    string toString();
    ~Array();
};

template <class T>
    Array<T>::Array(int n) {
        for (int i = 0; i < n; i++) {
            a[i] = new T();
        }
        this->k = 0;
    }

    template <class T>
    Array<T>::Array() = default;

    template<class T>
    int Array<T>::getK() const {
        return k;
    }

    template<class T>
    void Array<T>::setK(int k) {
        Array::k = k;
    }

    template <class T>
    int Array<T>::size() { // O(1)
        return k;
    }

    template <class T>
    T Array<T>::get(int i) { // O(1)
        if ((0 <= i) && (i < size())) {
            return (T) a[i];
        }/* else {
            throw new IndexOutOfBoundsException();
        }*/
    }

    template <class T>
    void Array<T>:: add(T* v) { // O(1)
        if(k < CAPACITY)
        {
            a[k] = v;
            k++;
        } /*else {
            throw new IllegalArgumentException();
        }*/
    }

    template <class T>
    string Array<T>::toString() { // O(n)
        stringstream x;
        for (int i = 0; i < CAPACITY; ++i) {
            x << "["<<a[i]->toString()<<"]";
        }
        return x.str();
    }

    template<class T>
    Array<T>::~Array() {
    }


#endif //PROYECTO_1_ARRAY_H
