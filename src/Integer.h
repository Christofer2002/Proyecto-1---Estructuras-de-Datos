#ifndef BIG_INT_HPP
#define BIG_INT_HPP

#include <iostream>
#include "Extra.h"

class Integer {
    std::string value;
    char sign;
    Extra* e = new Extra();

public:
    // Constructors:
    Integer();
    Integer(const Integer&);
    Integer(const long long&);
    Integer(const std::string&);

    // Assignment operators:
    Integer& operator=(const Integer&);
    Integer& operator=(const long long&);
    Integer& operator=(const std::string&);

    // Unary arithmetic operators:
    Integer operator+() const;   // unary +
    Integer operator-() const;   // unary -

    // Binary arithmetic operators:
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

    // Arithmetic-assignment operators:
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

    // Increment and decrement operators:
    Integer& operator++();       // pre-increment
    Integer& operator--();       // pre-decrement
    Integer operator++(int);     // post-increment
    Integer operator--(int);     // post-decrement

    // Relational operators:
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

    // I/O stream operators:
    friend std::istream& operator>>(std::istream&, Integer&);
    friend std::ostream& operator<<(std::ostream&, const Integer&);

    // Conversion functions:
    std::string to_string() const;
    int to_int() const;
    long to_long() const;
    long long to_long_long() const;

    //Extra functions:


};

#endif  // BIG_INT_HPP
