//
// Created by Christofer Chaves on 21/9/2022.
//

#include "Link.h"

Link::Link(Array<AlmacenaNum> *info, Link *sig) {
    this->info = info;
    this->sig = sig;
}

Link::~Link() {}

void Link::setInfo(Array<AlmacenaNum>* info) {
    this->info = info;
}

Array<AlmacenaNum>* Link::getInfo() {
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

Link::Link(Array<AlmacenaNum> *info) {
    this->info = info;
    this->sig = nullptr;
}
