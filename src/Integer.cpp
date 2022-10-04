
//
// Created by Christofer Chaves on 21/9/2022.
//

#include "Integer.h"

Integer::Integer(){
    this->num = 0;
}

Integer::Integer(long num) {
    this->num = num;
}

Integer::~Integer()= default;

void Integer::setNum(long num) {
    this->num = num;
}

long Integer::getNum() const {
    return num;
}

string Integer::toString() const {
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


