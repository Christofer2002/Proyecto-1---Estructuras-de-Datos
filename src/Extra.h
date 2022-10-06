//
// Created by PC on 10/6/2022.
//

#ifndef PROYECTO_1_EXTRA_H
#define PROYECTO_1_EXTRA_H

#include <iostream>
#include <tuple>

class Extra {

public:
     bool is_valid_number(const std::string& num);
     void strip_leading_zeroes(std::string& num);
     void add_leading_zeroes(std::string& num, size_t num_zeroes);
     void add_trailing_zeroes(std::string& num, size_t num_zeroes);
     std::tuple<std::string, std::string> get_larger_and_smaller(const std::string& num1,
                                                                const std::string& num2);


};


#endif //PROYECTO_1_EXTRA_H
