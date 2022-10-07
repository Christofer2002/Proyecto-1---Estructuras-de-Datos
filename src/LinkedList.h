//
// Created by Christofer Chaves on 21/9/2022.
//

#ifndef PROYECTO_1_LINKEDLIST_H
#define PROYECTO_1_LINKEDLIST_H

#include "Link.h"
#include "Integer.h"
#include <cstring>
#include <cmath>

template<class T>
class LinkedList {

private:
    Link *primero;
    Link *actual;
public:

    LinkedList();//Constructor
    ~LinkedList();//Destructor
    //Metodos
    void add(T *info);
    static Integer factorial(int num);
    static LinkedList addFactorialToLinkedList(int num, int pos);
    static Integer fibonnacci(int num);
    static LinkedList<T> addFibonnacciToLinkedList(int n, int pos);
    static Integer combinatoria(int a, int b);
    static LinkedList<T> addCombinationalToLinkedList(int a, int b, int pos);
    void flipLinkedList();
    string toString();
};

template<class T>
LinkedList<T>::LinkedList() {
    primero = nullptr;
    actual = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList() {
    Link *aux = primero;
    while (aux != nullptr) {
        primero = primero->getSig();
        delete aux;
        aux = primero;
    }
}

template<class T>
void LinkedList<T>::add(T *info) {
    actual = new Link(info, nullptr);
    if (primero == nullptr) {
        primero = actual;
    } else {
        actual->setSig(primero);
        primero = actual;

    }
}

template<class T>
Integer LinkedList<T>::factorial(int num) {
    Integer a = 0, b = 1;
    for (int i = 1; i <= num; i++) {
        a = b;
        b = a * i;
    }
    return b;
}

template<class T>
LinkedList<T> LinkedList<T>::addFactorialToLinkedList(int num, int pos) {
    auto *ll = new LinkedList<Array<AlmacenaNum>>();
    auto *array = new Array<AlmacenaNum>(3);
    AlmacenaNum *integer;
    int postInit = 0, time = 0;
    string sub = factorial(num).toString();
    int tam = round(sub.size() / pos);
    for (int i = 0; i < tam; i++) {
        if(i == tam-1){
            integer = new AlmacenaNum(Integer::parse(sub.substr(postInit, pos)));
            array->add(integer);
            ll->add(array);
            break;
        }
        integer = new AlmacenaNum(Integer::parse(sub.substr(postInit, pos)));
        array->add(integer);
        time += 1;
        if (time == pos) {
            ll->add(array);
            array = new Array<AlmacenaNum>(3);
            time = 0;
        }
        postInit += pos;
    }
    return *ll;
}

template <class T>
Integer LinkedList<T>::fibonnacci(int num) {
    Integer a = 0, b = 1, c = 0;
    for (int i = 2; i <= num; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

template<class T>
LinkedList<T> LinkedList<T>::addFibonnacciToLinkedList(int n, int pos) {
    auto *ll = new LinkedList<Array<AlmacenaNum>>();
    auto *array = new Array<AlmacenaNum>(3);
    AlmacenaNum *integer;
    string sub;
    long long number = 0;
    int postInit = 0, time = 0;
    sub = fibonnacci(n).toString();
    int e = sub.size();
    int tam = round(((sub.size() / pos) / 10.0) * 10.0)+1;
    for (int i = 0; i < tam; ++i) {
        (i != tam) ? number = Integer::parse(sub.substr(postInit, pos)) : number = Integer::parse(
                sub.substr(postInit, pos-1));
        if(i == tam-1){
            integer = new AlmacenaNum(Integer::parse(sub.substr(postInit, pos)));
            array->add(integer);
            ll->add(array);
            break;
        }
        integer = new AlmacenaNum(number);
        array->add(integer);
        time += 1;
        if (time == pos) {
            ll->add(array);
            array = new Array<AlmacenaNum>(3);
            time = 0;
        }
        postInit += pos;
    }
    return *ll;
}

template<class T>
Integer LinkedList<T>::combinatoria(int a, int b) {
    return factorial(a) / (factorial(b) * factorial(a - b));
}

template<class T>
LinkedList<T> LinkedList<T>::addCombinationalToLinkedList(int a, int b, int pos) {
    auto *ll = new LinkedList<Array<AlmacenaNum>>();
    auto *array = new Array<AlmacenaNum>(3);
    AlmacenaNum *integer;
    string sub;
    long long number = 0;
    int postInit = 0, time = 0;
    sub = combinatoria(a, b).toString();
    int tam = round(((sub.size() / pos) / 10.0) * 10.0);
    for (int i = 0; i < tam; ++i) {
        (i != tam) ? number = Integer::parse(sub.substr(postInit, pos)) : number = Integer::parse(
                sub.substr(postInit, pos - 1));
        if(i == tam-1){
            integer = new AlmacenaNum(Integer::parse(sub.substr(postInit, pos)));
            array->add(integer);
            ll->add(array);
            break;
        }else{
            integer = new AlmacenaNum(number);
            array->add(integer);
            time += 1;
            if (time == pos) {
                ll->add(array);
                array = new Array<AlmacenaNum>(3);
                time = 0;
            }
            postInit += pos;
        }
    }
    return *ll;
}

template<class T>
string LinkedList<T>::toString() {
    stringstream ss;
    actual = primero;
    while (actual != nullptr) {
        ss << "|" << actual->getInfo()->toString() << "|-->";
        actual = actual->getSig();
    }
    ss << "NULL";
    return ss.str();
}

template<class T>
void LinkedList<T>::flipLinkedList() {
    Link *prev = nullptr;
    Link *current = primero;
    Link *next;
    while (current != nullptr) {
        next = current->getSig();
        current->setSig(prev);
        prev = current;
        current = next;
    }
    primero = prev;
}




#endif //PROYECTO_1_LINKEDLIST_H
