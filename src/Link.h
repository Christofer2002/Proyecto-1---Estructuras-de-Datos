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
    Array<AlmacenaNum>* info;
    Link * sig;
public:
    //Constructores
    Link(Array<AlmacenaNum>* info, Link* sig);
    Link(Array<AlmacenaNum>* info);

    ~Link();//Destructor


    void setSig(Link*);//set
    Link* getSig();//get

    //Metodos
    void setInfo(Array<AlmacenaNum>* info);
    Array<AlmacenaNum>* getInfo();
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
