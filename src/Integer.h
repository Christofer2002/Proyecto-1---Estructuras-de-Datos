//
// Created by Christofer Chaves on 21/9/2022.
//

#ifndef PROYECTO_1_INTEGER_H
#define PROYECTO_1_INTEGER_H
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//template <class T>
class Integer {
private:
    unsigned long num;
public:
    Integer();
    Integer(long num);
    ~Integer();
    void setNum(long num);
    long getNum() const;
    string toString() const;
};

#endif //PROYECTO_1_INTEGER_H