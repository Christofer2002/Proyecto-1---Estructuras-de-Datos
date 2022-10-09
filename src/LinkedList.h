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
    //Metodos de la lista
    void add(T *info);
    static Integer factorial(int num);
    static LinkedList addFactorialToLinkedList(int num, int pos);
    static Integer fibonnacci(int num);
    static LinkedList<T> addFibonnacciToLinkedList(int n, int pos);
    static Integer combinatoria(int a, int b);
    static LinkedList<T> addCombinationalToLinkedList(int a, int b, int pos);
    //Da vuelta a la lista
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
    //Obtiene el factorial de 1000 y lo parsea a una hilera de caracteres
    string sub = factorial(num).toString();
    //Divide el tamaño total entre el numero que se quiere insertar en cada posicion del Array
    int tam = round(sub.size() / pos);
    for (int i = 0; i < tam; i++) {
        if(i == tam-1){
            //Convierte los numeros que se quiere insertar en cada posicion en numeros tipo long long
            integer = new AlmacenaNum(Integer::parse(sub.substr(postInit, pos)));
            //En cada posicion del Array inserta los numeros y despues el Array en cada nodo de la lista
            array->add(integer);
            ll->add(array);
            break;
        }else{
        integer = new AlmacenaNum(Integer::parse(sub.substr(postInit, pos)));
        array->add(integer);
        //Si la variable time es igual a la cantidad de numeros que se quieren insertar, entonces en cada Array tendrá sus numeros correspondiente y se inserta a la lista
        time += 1;
        if (time == pos) {
            ll->add(array);
            array = new Array<AlmacenaNum>(3);
            time = 0;
        }
        //Se suma la cantidad de numeros que se quieren insertar a postInit para que inserte los siguientes numeros al siguiente Array
        postInit += pos;
        }
    }
    return *ll;
}

template <class T>
Integer LinkedList<T>::fibonnacci(int num) {
    // se encarga de calcular la sucesion de fibonacci segun su formula.
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
    //Obtiene el fibonacci de 1000 y lo parsea a una hilera de caracteres
    sub = fibonnacci(n).toString();
    //obtiene el de el array
    int e = sub.size();
    //Divide el tamaño total entre el numero que se quiere insertar realiza la operacion correspondiante en cada posicion del Array
    int tam = round(((sub.size() / pos) / 10.0) * 10.0)+1;
    //realiza un recorrido en el array obiene la posicion  y si es el que se deaea lo agrega tanto en el array como en la linkedList.
    for (int i = 0; i < tam; ++i) {
        (i != tam) ? number = Integer::parse(sub.substr(postInit, pos)) : number = Integer::parse(
                sub.substr(postInit, pos-1));
        if(i == tam-1){
            //Convierte los numeros que se quiere insertar en cada posicion en numeros tipo long long
            integer = new AlmacenaNum(Integer::parse(sub.substr(postInit, pos)));
            array->add(integer);
            ll->add(array);
            break;
        }else{
            //Si la variable time es igual a los numeros que se quieren insertar, entonces en cada Array tendrá sus numeros correspondiente y se inserta a la lista
        integer = new AlmacenaNum(number);
        array->add(integer);
        time += 1;

        if (time == pos) {
            ll->add(array);
            array = new Array<AlmacenaNum>(3);
            time = 0;
        }
            //Se suma la cantidad de numeros que se quieren insertar a postInit para que inserte los siguientes numeros al siguiente Array
        postInit += pos;
        }
    }
    return *ll;
}

template<class T>
//realiza la operacion correspondiente a la combinatoria
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
    //realiza un parseo de la combinaria la comvierte a string
    sub = combinatoria(a, b).toString();
    //Divide el tamaño total entre el numero que se quiere insertar realizando la operacion correspondiante en cada posicion del Array
    int tam = round(((sub.size() / pos) / 10.0) * 10.0);
    for (int i = 0; i < tam; ++i) {
        (i != tam) ? number = Integer::parse(sub.substr(postInit, pos)) : number = Integer::parse(
                sub.substr(postInit, pos - 1));
        if(i == tam-1){
            //realiza un parseo que convierte los numeros a tipo long long
            integer = new AlmacenaNum(Integer::parse(sub.substr(postInit, pos)));
            //En cada posicion del Array inserta los numeros y despues el Array en cada nodo de la lista
            array->add(integer);
            ll->add(array);
            break;
        }else{
            //Convierte los numeros que se quiere insertar en cada posicion en numeros tipo long long
            integer = new AlmacenaNum(number);
            array->add(integer);
            //Si la variable time es igual a los numeros que se quieren insertar, entonces en cada Array tendrá sus numeros correspondiente y se inserta a la lista
            time += 1;
            if (time == pos) {
                ll->add(array);
                array = new Array<AlmacenaNum>(3);
                time = 0;
            }
            //Se suma la cantidad de numeros que se quieren insertar a postInit para que inserte los siguientes numeros al siguiente Array
            postInit += pos;
        }
    }
    return *ll;
}

//imprime la linkedlist
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


// hace que la lista se voltee
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
