//
// Created by PC on 10/6/2022.
//

#include "Extra.h"

#ifndef BIG_INT_UTILITY_FUNCTIONS_HPP
#define BIG_INT_UTILITY_FUNCTIONS_HPP

#include <tuple>

bool Extra::is_valid_number(const std::string& num) {
    for (char digit : num)
        if (digit < '0' or digit > '9')
            return false;

    return true;
}


/*
    strip_leading_zeroes
    --------------------
         Elimina los ceros iniciales de un número representado como una cadena.
*/

void Extra::strip_leading_zeroes(std::string& num) {
    size_t i;
    for (i = 0; i < num.size(); i++)
        if (num[i] != '0')
            break;

    if (i == num.size())
        num = "0";
    else
        num = num.substr(i);
}


/*
    add_leading_zeroes
    ------------------
    Agrega un número determinado de ceros iniciales a un número entero representado por una cadena `num`.
*/

void Extra::add_leading_zeroes(std::string& num, size_t num_zeroes) {
    num = std::string(num_zeroes, '0') + num;
}


/*
    add_trailing_zeroes
    -------------------
    Agrega un número determinado de ceros finales a un entero `num` representado por una cadena.
*/

void Extra::add_trailing_zeroes(std::string& num, size_t num_zeroes) {
    num += std::string(num_zeroes, '0');
}


/*
    get_larger_and_smaller
    ----------------------
    Identifica los números enteros representados por cadenas dados como "más grande" y "más pequeño".
     rellenando el número más pequeño con ceros a la izquierda para que tenga la misma longitud que
     el número mayor.
*/

std::tuple<std::string, std::string> Extra::get_larger_and_smaller(const std::string& num1,
                                                            const std::string& num2) {
    std::string larger, smaller;
    if (num1.size() > num2.size() or
        (num1.size() == num2.size() and num1 > num2)) {
        larger = num1;
        smaller = num2;
    }
    else {
        larger = num2;
        smaller = num1;
    }

    // pad the smaller number with zeroes
    add_leading_zeroes(smaller, larger.size() - smaller.size());

    return std::make_tuple(larger, smaller);
}

#endif  // BIG_INT_UTILITY_FUNCTIONS_HPP