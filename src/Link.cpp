<<<<<<< HEAD
//
// Created by Christofer Chaves on 21/9/2022.
//

#include "Link.h"

Link::Link(Array<Integer> *info, Link *sig) {
    this->info = info;
    this->sig = sig;
}

Link::~Link() {}

void Link::setInfo(Array<Integer>* info) {
    this->info = info;
}

Array<Integer>* Link::getInfo() {
    return info;
}

void Link::setSig(Link * sig) {
    this->sig = sig;
}

Link *Link::getSig() {
    return sig;
}

string Link::toStringNodo() {
    return info->toString();
}

Link::Link(Array<Integer> *info) {
    this->info = info;
    this->sig = nullptr;
}
=======
//
// Created by Christofer Chaves on 21/9/2022.
//

#include "Link.h"

Link::Link(Array<Integer> *info, Link *sig) {
    this->info = info;
    this->sig = sig;
}

Link::~Link() {}

void Link::setInfo(Array<Integer>* info) {
    this->info = info;
}

Array<Integer>* Link::getInfo() {
    return info;
}

void Link::setSig(Link * sig) {
    this->sig = sig;
}

Link *Link::getSig() {
    return sig;
}

string Link::toStringNodo() {
    return info->toString();
}

Link::Link(Array<Integer> *info) {
    this->info = info;
    this->sig = nullptr;
}
>>>>>>> 31344a19717938d0a7b13d079f50d8f153da8a85
