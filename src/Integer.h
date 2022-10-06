#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>
#include "Extra.h"

class Integer {
    std::string value;
    char sign;
    Extra* e = new Extra();
public:
    // Constructores
    Integer();
    Integer(const Integer&);
    Integer(const long long&);
    Integer(const std::string&);

    // Operadores aritméticos unitarios
    Integer operator+() const;   // unary +
    Integer operator-() const;   // unary -

    // Operadores aritmeticos binarios
    Integer operator+(const Integer&) const;
    Integer operator-(const Integer&) const;
    Integer operator*(const Integer&) const;
    Integer operator/(const Integer&) const;
    Integer operator%(const Integer&) const;
    Integer operator+(const long long&) const;
    Integer operator-(const long long&) const;
    Integer operator*(const long long&) const;
    Integer operator/(const long long&) const;
    Integer operator%(const long long&) const;
    Integer operator+(const std::string&) const;
    Integer operator-(const std::string&) const;
    Integer operator*(const std::string&) const;
    Integer operator/(const std::string&) const;
    Integer operator%(const std::string&) const;

    // Operadores de asignacion
    Integer& operator+=(const Integer&);
    Integer& operator-=(const Integer&);
    Integer& operator*=(const Integer&);
    Integer& operator/=(const Integer&);
    Integer& operator%=(const Integer&);
    Integer& operator+=(const long long&);
    Integer& operator-=(const long long&);
    Integer& operator*=(const long long&);
    Integer& operator/=(const long long&);
    Integer& operator%=(const long long&);
    Integer& operator+=(const std::string&);
    Integer& operator-=(const std::string&);
    Integer& operator*=(const std::string&);
    Integer& operator/=(const std::string&);
    Integer& operator%=(const std::string&);
    Integer& operator=(const Integer&);
    Integer& operator=(const long long&);
    Integer& operator=(const std::string&);

    // Operadores de incremento y decremento
    Integer& operator++();       // pre-increment
    Integer& operator--();       // pre-decrement
    Integer operator++(int);     // post-increment
    Integer operator--(int);     // post-decrement

    // Operaciones de comparacion
    bool operator<(const Integer&) const;
    bool operator>(const Integer&) const;
    bool operator<=(const Integer&) const;
    bool operator>=(const Integer&) const;
    bool operator==(const Integer&) const;
    bool operator!=(const Integer&) const;
    bool operator<(const long long&) const;
    bool operator>(const long long&) const;
    bool operator<=(const long long&) const;
    bool operator>=(const long long&) const;
    bool operator==(const long long&) const;
    bool operator!=(const long long&) const;
    bool operator<(const std::string&) const;
    bool operator>(const std::string&) const;
    bool operator<=(const std::string&) const;
    bool operator>=(const std::string&) const;
    bool operator==(const std::string&) const;
    bool operator!=(const std::string&) const;

    // Funciones de conversion
    std::string toString() const;
    static long parse(const std::string& sub);

};

#endif
