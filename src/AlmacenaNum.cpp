
//
// Created by Christofer Chaves on 21/9/2022.
//

#include "AlmacenaNum.h"

AlmacenaNum::AlmacenaNum(){
    this->num = 0;
}

AlmacenaNum::AlmacenaNum(long long num) {
    this->num = num;
}

AlmacenaNum::~AlmacenaNum()= default;

void AlmacenaNum::setNum(long long num) {
    this->num = num;
}

long long AlmacenaNum::getNum() const {
    return num;
}

string AlmacenaNum::toString() const {
    stringstream ss;
    string s = to_string(num);
    if(s.size() == 2){
        ss << "0" <<num<<"";
    }else if(s.size() == 1){
        ss << "00" <<num<<"";
    }else{
        ss << "" <<num<<"";
    }
    return ss.str();
}


