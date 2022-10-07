//
// Created by Christofer Chaves on 21/9/2022.
//

#ifndef PROYECTO_1_INTEGER_H
#define PROYECTO_1_INTEGER_H
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class AlmacenaNum {
private:
    //declaracion de atributo long long
    unsigned long long num;
public:
    //Constructores y destructor
    AlmacenaNum();
    AlmacenaNum(long long num);
    ~AlmacenaNum();


    //Metodos set y get
    void setNum(long long num);
    long long getNum() const;

    //tostring
    string toString() const;
};

#endif //PROYECTO_1_INTEGER_H
