<<<<<<< HEAD
//
// Created by Christofer Chaves on 21/9/2022.
//

#ifndef PROYECTO_1_LINK_H
#define PROYECTO_1_LINK_H
#include "Array.h"

//template <class T>
class Link
{
private:
    Array<Integer>* info;
    Link * sig;
public:
    Link(Array<Integer>* info, Link* sig);
    Link(Array<Integer>* info);
    ~Link();
    void setInfo(Array<Integer>* info);
    Array<Integer>* getInfo();
    void setSig(Link*);
    Link* getSig();
    string toStringNodo();
};

/*template <class T>
Link<T>::Link(Integer<T>* info, Link *sig) {
    this->info = info;
    this->sig = sig;
}

template <class T>
Link<T>::Link() {

}

template <class T>
void Link<T>::setInfo(Integer<T>) {
    this->info = info;
}

template <class T>
Integer<T> Link<T>::getInfo() {
    return info;
}

template <class T>
void Link<T>::setSig(Link *) {
    this->sig = sig;
}

template <class T>
Link<T> *Link<T>::getSig() {
    return sig;
}

template <class T>
string Link<T>::toStringNodo() {
    return info->toString();
}*/

#endif //PROYECTO_1_LINK_H
=======
//
// Created by Christofer Chaves on 21/9/2022.
//

#ifndef PROYECTO_1_LINK_H
#define PROYECTO_1_LINK_H
#include "Array.h"

//template <class T>
class Link
{
private:
    Array<Integer>* info;
    Link * sig;
public:
    Link(Array<Integer>* info, Link* sig);
    Link(Array<Integer>* info);
    ~Link();
    void setInfo(Array<Integer>* info);
    Array<Integer>* getInfo();
    void setSig(Link*);
    Link* getSig();
    string toStringNodo();
};

/*template <class T>
Link<T>::Link(Integer<T>* info, Link *sig) {
    this->info = info;
    this->sig = sig;
}

template <class T>
Link<T>::Link() {

}

template <class T>
void Link<T>::setInfo(Integer<T>) {
    this->info = info;
}

template <class T>
Integer<T> Link<T>::getInfo() {
    return info;
}

template <class T>
void Link<T>::setSig(Link *) {
    this->sig = sig;
}

template <class T>
Link<T> *Link<T>::getSig() {
    return sig;
}

template <class T>
string Link<T>::toStringNodo() {
    return info->toString();
}*/

#endif //PROYECTO_1_LINK_H
>>>>>>> 31344a19717938d0a7b13d079f50d8f153da8a85
