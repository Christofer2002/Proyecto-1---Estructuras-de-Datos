
#include "Integer.h"

Integer::Integer() {
    value = "0";
    sign = '+';

}

Integer::Integer(const Integer& num) {
    value = num.value;
    sign = num.sign;

}


/*
    Integer to Integer
    -----------------
*/

Integer::Integer(const long long& num) {
    value = std::to_string(num);
    if (num < 0) {
        sign = '-';
        value = value.substr(1);    // remove minus sign from value
    }
    else
        sign = '+';
}


/*
    String to Integer
    ----------------
*/

Integer::Integer(const std::string& num) {
    if (num[0] == '+' or num[0] == '-') {     // check for sign
        std::string magnitude = num.substr(1);
        if (e->is_valid_number(magnitude)) {
            value = magnitude;
            sign = num[0];
        }
        else {
            throw std::invalid_argument("Se esperaba un integer \'" + num + "\'");
        }
    }
    else {      // if no sign is specified
        if (e->is_valid_number(num)) {
            value = num;
            sign = '+';    // positive by default
        }
        else {
            throw std::invalid_argument("Se esperaba un integer \'" + num + "\'");
        }
    }
    e->strip_leading_zeroes(value);
}


/*
    toString
    ---------
    Convierte un entero en una cadena.
*/

std::string Integer::toString() const {
    // prefix with sign if negative
    return this->sign == '-' ? "-" + this->value : this->value;
}

#ifndef INTEGER_ASSIGNMENT_OPERATORS_H
#define INTEGER_ASSIGNMENT_OPERATORS_H



/*
    Integer = Integer
    ---------------
*/

Integer& Integer::operator=(const Integer& num) {
    value = num.value;
    sign = num.sign;

    return *this;
}


/*
    Integer = Integer
    ----------------
*/

Integer& Integer::operator=(const long long& num) {
    Integer temp(num);
    value = temp.value;
    sign = temp.sign;

    return *this;
}


/*
    Integer = String
    ---------------
*/

Integer& Integer::operator=(const std::string& num) {
    Integer temp(num);
    value = temp.value;
    sign = temp.sign;

    return *this;
}

#endif


/*
    ===========================================================================
    Operadores aritm??ticos unarios
    ===========================================================================
*/

#ifndef INTEGER_UNARY_ARITHMETIC_OPERATORS_H
#define INTEGER_UNARY_ARITHMETIC_OPERATORS_H



/*
    +Integer
    -------
    Devuelve el valor de un entero.
     NOTA: Esta funci??n no devuelve el valor absoluto. Para obtener el absoluto
     valor de un entero, utilice la funci??n `abs`.
*/

Integer Integer::operator+() const {
    return *this;
}


/*
    -Integer
    -------
    Devuelve la negativa de un entero.
*/

Integer Integer::operator-() const {
    Integer temp;

    temp.value = value;
    if (value != "0") {
        if (sign == '+')
            temp.sign = '-';
        else
            temp.sign = '+';
    }

    return temp;
}

#endif


/*
    ===========================================================================
        Operadores relacionales
     ================================================== =========================
     Todos los operadores dependen de los operadores '<' y/o '=='.
*/

#ifndef INTEGER_RELATIONAL_OPERATORS_H
#define INTEGER_RELATIONAL_OPERATORS_H



/*
    Integer == Integer
    ----------------
*/

bool Integer::operator==(const Integer& num) const {
    return (sign == num.sign) and (value == num.value);
}


/*
    Integer != Integer
    ----------------
*/

bool Integer::operator!=(const Integer& num) const {
    return !(*this == num);
}


/*
    Integer < Integer
    ---------------
*/

bool Integer::operator<(const Integer& num) const {
    if (sign == num.sign) {
        if (sign == '+') {
            if (value.length() == num.value.length())
                return value < num.value;
            else
                return value.length() < num.value.length();
        }
        else
            return -(*this) > -num;
    }
    else
        return sign == '-';
}


/*
    Integer > Integer
    ---------------
*/

bool Integer::operator>(const Integer& num) const {
    return !((*this < num) or (*this == num));
}


/*
    Integer <= Integer
    ----------------
*/

bool Integer::operator<=(const Integer& num) const {
    return (*this < num) or (*this == num);
}


/*
    Integer >= Integer
    ----------------
*/

bool Integer::operator>=(const Integer& num) const {
    return !(*this < num);
}


/*
    Integer == Integer
    -----------------
*/

bool Integer::operator==(const long long& num) const {
    return *this == Integer(num);
}


/*
    Integer == Integer
    -----------------
*/

bool operator==(const long long& lhs, const Integer& rhs) {
    return Integer(lhs) == rhs;
}


/*
    Integer != Integer
    -----------------
*/

bool Integer::operator!=(const long long& num) const {
    return !(*this == Integer(num));
}


/*
    Integer != Integer
    -----------------
*/

bool operator!=(const long long& lhs, const Integer& rhs) {
    return Integer(lhs) != rhs;
}


/*
    Integer < Integer
    ----------------
*/

bool Integer::operator<(const long long& num) const {
    return *this < Integer(num);
}


/*
    Integer < Integer
    ----------------
*/

bool operator<(const long long& lhs, const Integer& rhs) {
    return Integer(lhs) < rhs;
}


/*
    Integer > Integer
    ----------------
*/

bool Integer::operator>(const long long& num) const {
    return *this > Integer(num);
}


/*
    Integer > Integer
    ----------------
*/

bool operator>(const long long& lhs, const Integer& rhs) {
    return Integer(lhs) > rhs;
}


/*
    Integer <= Integer
    -----------------
*/

bool Integer::operator<=(const long long& num) const {
    return !(*this > Integer(num));
}


/*
    Integer <= Integer
    -----------------
*/

bool operator<=(const long long& lhs, const Integer& rhs) {
    return Integer(lhs) <= rhs;
}


/*
    Integer >= Integer
    -----------------
*/

bool Integer::operator>=(const long long& num) const {
    return !(*this < Integer(num));
}


/*
    Integer >= Integer
    -----------------
*/

bool operator>=(const long long& lhs, const Integer& rhs) {
    return Integer(lhs) >= rhs;
}


/*
    Integer == String
    ----------------
*/

bool Integer::operator==(const std::string& num) const {
    return *this == Integer(num);
}


/*
    String == Integer
    ----------------
*/

bool operator==(const std::string& lhs, const Integer& rhs) {
    return Integer(lhs) == rhs;
}


/*
    Integer != String
    ----------------
*/

bool Integer::operator!=(const std::string& num) const {
    return !(*this == Integer(num));
}


/*
    String != Integer
    ----------------
*/

bool operator!=(const std::string& lhs, const Integer& rhs) {
    return Integer(lhs) != rhs;
}


/*
    Integer < String
    ---------------
*/

bool Integer::operator<(const std::string& num) const {
    return *this < Integer(num);
}


/*
    String < Integer
    ---------------
*/

bool operator<(const std::string& lhs, const Integer& rhs) {
    return Integer(lhs) < rhs;
}


/*
    Integer > String
    ---------------
*/

bool Integer::operator>(const std::string& num) const {
    return *this > Integer(num);
}


/*
    String > Integer
    ---------------
*/

bool operator>(const std::string& lhs, const Integer& rhs) {
    return Integer(lhs) > rhs;
}


/*
    Integer <= String
    ----------------
*/

bool Integer::operator<=(const std::string& num) const {
    return !(*this > Integer(num));
}


/*
    String <= Integer
    ----------------
*/

bool operator<=(const std::string& lhs, const Integer& rhs) {
    return Integer(lhs) <= rhs;
}


/*
    Integer >= String
    ----------------
*/

bool Integer::operator>=(const std::string& num) const {
    return !(*this < Integer(num));
}


/*
    String >= Integer
    ----------------
*/

bool operator>=(const std::string& lhs, const Integer& rhs) {
    return Integer(lhs) >= rhs;
}

#endif  // BIG_INT_RELATIONAL_OPERATORS_HPP


/*
    ===========================================================================
    Funciones matem??ticas para enteros
    ===========================================================================
*/

#ifndef BIG_INT_MATH_FUNCTIONS_HPP
#define BIG_INT_MATH_FUNCTIONS_HPP

#include <string>



/*
    abs
    ---
    Devuelve el valor absoluto de un entero.
*/

Integer abs(const Integer& num) {
    return num < 0 ? -num : num;
}


/*
    big_pow10
    ---------
    Devuelve un entero igual a 10^exp.
     NOTA: el exponente debe ser un n??mero entero no negativo.
*/

Integer big_pow10(size_t exp) {
    return Integer("1" + std::string(exp, '0'));
}


/*
    pow (Integer)
    ------------
   Devuelve un entero igual a base^exp.
*/

Integer pow(const Integer& base, int exp) {
    if (exp < 0) {
        if (base == 0)
            throw std::logic_error("Cannot divide by zero");
        return abs(base) == 1 ? base : 0;
    }
    if (exp == 0) {
        if (base == 0)
            throw std::logic_error("Zero cannot be raised to zero");
        return 1;
    }

    Integer result = base, result_odd = 1;
    while (exp > 1) {
        if (exp % 2)
            result_odd *= result;
        result *= result;
        exp /= 2;
    }

    return result * result_odd;
}


/*
    pow (Integer)
    -------------
    Devuelve un entero igual a base^exp.
*/

Integer pow(const long long& base, int exp) {
    return pow(Integer(base), exp);
}


/*
    pow (String)
    ------------
    Devuelve un entero igual a base^exp.
*/

Integer pow(const std::string& base, int exp) {
    return pow(Integer(base), exp);

}


/*
    sqrt
    ----
    Devuelve la ra??z cuadrada entera positiva de un entero utilizando el m??todo de Newton.
     NOTA: la entrada debe ser no negativa.
*/

Integer sqrt(const Integer& num) {
    if (num < 0)
        throw std::invalid_argument("Cannot compute square root of a negative integer");

    // Optimisations for small inputs:
    if (num == 0)
        return 0;
    else if (num < 4)
        return 1;
    else if (num < 9)
        return 2;
    else if (num < 16)
        return 3;

    Integer sqrt_prev = 0;
// El valor de `sqrt_current` se elige cercano al actual
    // ra??z cuadrada.
    // Dado que la ra??z cuadrada de un n??mero tiene al menos uno menos que la mitad
    // d??gitos como el n??mero,
    // sqrt_current = 10^(half_the_digits_in_num - 1)
    Integer sqrt_current = big_pow10(num.toString().size() / 2 - 1);

    while (abs(sqrt_current - sqrt_prev) > 1) {
        sqrt_prev = sqrt_current;
        sqrt_current = (num / sqrt_prev + sqrt_prev) / 2;
    }

    return sqrt_current;
}

#endif  // BIG_INT_MATH_FUNCTIONS_HPP


/*
    ===========================================================================
    Operadores aritm??ticos binarios
    ===========================================================================
*/

#ifndef BIG_INT_BINARY_ARITHMETIC_OPERATORS_HPP
#define BIG_INT_BINARY_ARITHMETIC_OPERATORS_HPP

#include <climits>
#include <cmath>



const long long FLOOR_SQRT_LLONG_MAX = 3037000499;


/*
    Integer + Integer
    ---------------
    El operando en el RHS de la suma es `num`.
*/

Integer Integer::operator+(const Integer& num) const {
    // si los operandos son de signos opuestos, realiza la resta
    if (this->sign == '+' and num.sign == '-') {
        Integer rhs = num;
        rhs.sign = '+';
        return *this - rhs;
    }
    else if (this->sign == '-' and num.sign == '+') {
        Integer lhs = *this;
        lhs.sign = '+';
        return -(lhs - num);
    }

    // identificar los n??meros como `m??s grande` y `m??s peque??o`
    std::string larger, smaller;
    std::tie(larger, smaller) = e->get_larger_and_smaller(this->value, num.value);

    Integer result;      // el resultado de sum
    result.value = "";  // el valor se borra ya que se agregar??n los d??gitos
    short carry = 0, sum;
    // add the two values
    for (long i = larger.size() - 1; i >= 0; i--) {
        sum = larger[i] - '0' + smaller[i] - '0' + carry;
        result.value = std::to_string(sum % 10) + result.value;
        carry = sum / (short) 10;
    }
    if (carry)
        result.value = std::to_string(carry) + result.value;

    // if the operands are negative, the result is negative
    if (this->sign == '-' and result.value != "0")
        result.sign = '-';

    return result;
}


/*
    Integer - Integer
    ---------------
    El operando en el RHS de la resta es `num`.
*/

Integer Integer::operator-(const Integer& num) const {
    // si los operandos son de signos opuestos, realice la suma
    if (this->sign == '+' and num.sign == '-') {
        Integer rhs = num;
        rhs.sign = '+';
        return *this + rhs;
    }
    else if (this->sign == '-' and num.sign == '+') {
        Integer lhs = *this;
        lhs.sign = '+';
        return -(lhs + num);
    }

    Integer result;      // the resultant difference
    // identificar los n??meros como "m??s grande" y "m??s peque??o"
    std::string larger, smaller;
    if (abs(*this) > abs(num)) {
        larger = this->value;
        smaller = num.value;

        if (this->sign == '-')      // -larger - -smaller = -result
            result.sign = '-';
    }
    else {
        larger = num.value;
        smaller = this->value;

        if (num.sign == '+')        // smaller - larger = -result
            result.sign = '-';
    }
    // pad the smaller number with zeroes
    e->add_leading_zeroes(smaller, larger.size() - smaller.size());

    result.value = "";  // el valor se borra ya que se a??adir??n los d??gitos
    short difference;
    long i, j;
    // subtract the two values
    for (i = larger.size() - 1; i >= 0; i--) {
        difference = larger[i] - smaller[i];
        if (difference < 0) {
            for (j = i - 1; j >= 0; j--) {
                if (larger[j] != '0') {
                    larger[j]--;    // tomar prestado del j-??simo d??gito
                    break;
                }
            }
            j++;
            while (j != i) {
                larger[j] = '9';    // a??adir el pr??stamo y quitar 1
                j++;
            }
            difference += 10;   // a??adir el pr??stamo
        }
        result.value = std::to_string(difference) + result.value;
    }
    e->strip_leading_zeroes(result.value);

    // si el resultado es 0, establece su signo como +
    if (result.value == "0")
        result.sign = '+';

    return result;
}


Integer Integer::operator*(const Integer& num) const {
    if (*this == 0 or num == 0)
        return Integer(0);
    if (*this == 1)
        return num;
    if (num == 1)
        return *this;

    Integer product;
    if (abs(*this) <= FLOOR_SQRT_LLONG_MAX and abs(num) <= FLOOR_SQRT_LLONG_MAX)
        product = std::stoll(this->value) * std::stoll(num.value);
    else {
        // identificar los n??meros como `m??s grande` y `m??s peque??o`
        std::string larger, smaller;
        std::tie(larger, smaller) = e->get_larger_and_smaller(this->value, num.value);

        size_t half_length = larger.size() / 2;
        auto half_length_ceil = (size_t) ceil(larger.size() / 2.0);

        Integer num1_high, num1_low;
        num1_high = larger.substr(0, half_length);
        num1_low = larger.substr(half_length);

        Integer num2_high, num2_low;
        num2_high = smaller.substr(0, half_length);
        num2_low = smaller.substr(half_length);

        e->strip_leading_zeroes(num1_high.value);
        e->strip_leading_zeroes(num1_low.value);
        e->strip_leading_zeroes(num2_high.value);
        e->strip_leading_zeroes(num2_low.value);

        Integer prod_high, prod_mid, prod_low;
        prod_high = num1_high * num2_high;
        prod_low = num1_low * num2_low;
        prod_mid = (num1_high + num1_low) * (num2_high + num2_low)
                   - prod_high - prod_low;

        e->add_trailing_zeroes(prod_high.value, 2 * half_length_ceil);
        e->add_trailing_zeroes(prod_mid.value, half_length_ceil);

        e->strip_leading_zeroes(prod_high.value);
        e->strip_leading_zeroes(prod_mid.value);
        e->strip_leading_zeroes(prod_low.value);

        product = prod_high + prod_mid + prod_low;
    }
    e->strip_leading_zeroes(product.value);

    if (this->sign == num.sign)
        product.sign = '+';
    else
        product.sign = '-';

    return product;
}


/*
    divide
    ------
    Funci??n auxiliar que devuelve el cociente y el resto al dividir el
     dividendo por el divisor, cuando el divisor es de 1 a 10 veces el dividendo.
*/

std::tuple<Integer, Integer> divide(const Integer& dividend, const Integer& divisor) {
    Integer quotient, remainder, temp;

    temp = divisor;
    quotient = 1;
    while (temp < dividend) {
        quotient++;
        temp += divisor;
    }
    if (temp > dividend) {
        quotient--;
        remainder = dividend - (temp - divisor);
    }

    return std::make_tuple(quotient, remainder);
}


/*
    Integer / Integer
    ---------------
Calcula el cociente de dos enteros usando el m??todo de divisi??n larga.
     El operando en el lado derecho de la divisi??n (el divisor) es `num`.
*/

Integer Integer::operator/(const Integer& num) const {
    Integer abs_dividend = abs(*this);
    Integer abs_divisor = abs(num);

    if (num == 0)
        throw std::logic_error("Attempted division by zero");
    if (abs_dividend < abs_divisor)
        return Integer(0);
    if (num == 1)
        return *this;
    if (num == -1)
        return -(*this);

    Integer quotient;
    if (abs_dividend <= LLONG_MAX and abs_divisor <= LLONG_MAX)
        quotient = std::stoll(abs_dividend.value) / std::stoll(abs_divisor.value);
    else if (abs_dividend == abs_divisor)
        quotient = 1;
    else {
        quotient.value = "";    // the value is cleared as digits will be appended
        Integer chunk, chunk_quotient, chunk_remainder;
        size_t chunk_index = 0;
        chunk_remainder.value = abs_dividend.value.substr(chunk_index, abs_divisor.value.size() - 1);
        chunk_index = abs_divisor.value.size() - 1;
        while (chunk_index < abs_dividend.value.size()) {
            chunk.value = chunk_remainder.value.append(1, abs_dividend.value[chunk_index]);
            chunk_index++;
            while (chunk < abs_divisor) {
                quotient.value += "0";
                if (chunk_index < abs_dividend.value.size()) {
                    chunk.value.append(1, abs_dividend.value[chunk_index]);
                    chunk_index++;
                }
                else
                    break;
            }
            if (chunk == abs_divisor) {
                quotient.value += "1";
                chunk_remainder = 0;
            }
            else if (chunk > abs_divisor) {
                e->strip_leading_zeroes(chunk.value);
                std::tie(chunk_quotient, chunk_remainder) = divide(chunk, abs_divisor);
                quotient.value += chunk_quotient.value;
            }
        }
    }
    e->strip_leading_zeroes(quotient.value);

    if (this->sign == num.sign)
        quotient.sign = '+';
    else
        quotient.sign = '-';

    return quotient;
}


/*
    Integer % Integer
    ---------------
Calcula el m??dulo (resto de la divisi??n) de dos enteros.
     El operando en el RHS del m??dulo (el divisor) es `num`.
*/

Integer Integer::operator%(const Integer& num) const {
    Integer abs_dividend = abs(*this);
    Integer abs_divisor = abs(num);

    if (abs_divisor == 0)
        throw std::logic_error("Attempted division by zero");
    if (abs_divisor == 1 or abs_divisor == abs_dividend)
        return Integer(0);

    Integer remainder;
    if (abs_dividend <= LLONG_MAX and abs_divisor <= LLONG_MAX)
        remainder = std::stoll(abs_dividend.value) % std::stoll(abs_divisor.value);
    else if (abs_dividend < abs_divisor)
        remainder = abs_dividend;
    else {
        Integer quotient = abs_dividend / abs_divisor;
        remainder = abs_dividend - quotient * abs_divisor;
    }
    e->strip_leading_zeroes(remainder.value);

// el resto tiene el mismo signo que el dividendo
    remainder.sign = this->sign;
    if (remainder.value == "0")     // except if its zero
        remainder.sign = '+';

    return remainder;
}


/*
    Integer + Integer
    ----------------
*/

Integer Integer::operator+(const long long& num) const {
    return *this + Integer(num);
}


/*
    Integer + Integer
    ----------------
*/

Integer operator+(const long long& lhs, const Integer& rhs) {
    return Integer(lhs) + rhs;
}


/*
    Integer - Integer
    ----------------
*/

Integer Integer::operator-(const long long& num) const {
    return *this - Integer(num);
}


/*
    Integer - Integer
    ----------------
*/

Integer operator-(const long long& lhs, const Integer& rhs) {
    return Integer(lhs) - rhs;
}


/*
    Integer * Integer
    ----------------
*/

Integer Integer::operator*(const long long& num) const {
    return *this * Integer(num);
}


/*
    Integer * Integer
    ----------------
*/

Integer operator*(const long long& lhs, const Integer& rhs) {
    return Integer(lhs) * rhs;
}


/*
    Integer / Integer
    ----------------
*/

Integer Integer::operator/(const long long& num) const {
    return *this / Integer(num);
}


/*
    Integer / Integer
    ----------------
*/

Integer operator/(const long long& lhs, const Integer& rhs) {
    return Integer(lhs) / rhs;
}


/*
    Integer % Integer
    ----------------
*/

Integer Integer::operator%(const long long& num) const {
    return *this % Integer(num);
}


/*
    Integer % Integer
    ----------------
*/

Integer operator%(const long long& lhs, const Integer& rhs) {
    return Integer(lhs) % rhs;
}


/*
    Integer + String
    ---------------
*/

Integer Integer::operator+(const std::string& num) const {
    return *this + Integer(num);
}


/*
    String + Integer
    ---------------
*/

Integer operator+(const std::string& lhs, const Integer& rhs) {
    return Integer(lhs) + rhs;
}


/*
    Integer - String
    ---------------
*/

Integer Integer::operator-(const std::string& num) const {
    return *this - Integer(num);
}


/*
    String - Integer
    ---------------
*/

Integer operator-(const std::string& lhs, const Integer& rhs) {
    return Integer(lhs) - rhs;
}


/*
    Integer * String
    ---------------
*/

Integer Integer::operator*(const std::string& num) const {
    return *this * Integer(num);
}


/*
    String * Integer
    ---------------
*/

Integer operator*(const std::string& lhs, const Integer& rhs) {
    return Integer(lhs) * rhs;
}


/*
    Integer / String
    ---------------
*/

Integer Integer::operator/(const std::string& num) const {
    return *this / Integer(num);
}


/*
    String / Integer
    ---------------
*/

Integer operator/(const std::string& lhs, const Integer& rhs) {
    return Integer(lhs) / rhs;
}


/*
    Integer % String
    ---------------
*/

Integer Integer::operator%(const std::string& num) const {
    return *this % Integer(num);
}


/*
    String % Integer
    ---------------
*/

Integer operator%(const std::string& lhs, const Integer& rhs) {
    return Integer(lhs) % rhs;
}

#endif  // BIG_INT_BINARY_ARITHMETIC_OPERATORS_HPP


/*
    ===========================================================================
    Operadoras de asignaci??n aritm??tica
    ===========================================================================
*/

#ifndef BIG_INT_ARITHMETIC_ASSIGNMENT_OPERATORS_HPP
#define BIG_INT_ARITHMETIC_ASSIGNMENT_OPERATORS_HPP



/*
    Integer += Integer
    ----------------
*/

Integer& Integer::operator+=(const Integer& num) {
    *this = *this + num;

    return *this;
}


/*
    Integer -= Integer
    ----------------
*/

Integer& Integer::operator-=(const Integer& num) {
    *this = *this - num;

    return *this;
}


/*
    Integer *= Integer
    ----------------
*/

Integer& Integer::operator*=(const Integer& num) {
    *this = *this * num;

    return *this;
}


/*
    Integer /= Integer
    ----------------
*/

Integer& Integer::operator/=(const Integer& num) {
    *this = *this / num;

    return *this;
}


/*
    Integer %= Integer
    ----------------
*/

Integer& Integer::operator%=(const Integer& num) {
    *this = *this % num;

    return *this;
}


/*
    Integer += Integer
    -----------------
*/

Integer& Integer::operator+=(const long long& num) {
    *this = *this + Integer(num);

    return *this;
}


/*
    Integer -= Integer
    -----------------
*/

Integer& Integer::operator-=(const long long& num) {
    *this = *this - Integer(num);

    return *this;
}


/*
    Integer *= Integer
    -----------------
*/

Integer& Integer::operator*=(const long long& num) {
    *this = *this * Integer(num);

    return *this;
}


/*
    Integer /= Integer
    -----------------
*/

Integer& Integer::operator/=(const long long& num) {
    *this = *this / Integer(num);

    return *this;
}


/*
    Integer %= Integer
    -----------------
*/

Integer& Integer::operator%=(const long long& num) {
    *this = *this % Integer(num);

    return *this;
}


/*
    Integer += String
    ----------------
*/

Integer& Integer::operator+=(const std::string& num) {
    *this = *this + Integer(num);

    return *this;
}


/*
    Integer -= String
    ----------------
*/

Integer& Integer::operator-=(const std::string& num) {
    *this = *this - Integer(num);

    return *this;
}


/*
    Integer *= String
    ----------------
*/

Integer& Integer::operator*=(const std::string& num) {
    *this = *this * Integer(num);

    return *this;
}


/*
    Integer /= String
    ----------------
*/

Integer& Integer::operator/=(const std::string& num) {
    *this = *this / Integer(num);

    return *this;
}


/*
    Integer %= String
    ----------------
*/

Integer& Integer::operator%=(const std::string& num) {
    *this = *this % Integer(num);

    return *this;
}

#endif  // BIG_INT_ARITHMETIC_ASSIGNMENT_OPERATORS_HPP


/*
    ===========================================================================
    Operadoras de incremento y decremento
    ===========================================================================
*/

#ifndef BIG_INT_INCREMENT_DECREMENT_OPERATORS_HPP
#define BIG_INT_INCREMENT_DECREMENT_OPERATORS_HPP



/*
    Pre-increment
    -------------
    ++Integer
*/

Integer& Integer::operator++() {
    *this += 1;

    return *this;
}


/*
    Pre-decrement
    -------------
    --Integer
*/

Integer& Integer::operator--() {
    *this -= 1;

    return *this;
}


/*
    Post-increment
    --------------
    Integer++
*/

Integer Integer::operator++(int) {
    Integer temp = *this;
    *this += 1;

    return temp;
}


/*
    Post-decrement
    --------------
    Integer--
*/

Integer Integer::operator--(int) {
    Integer temp = *this;
    *this -= 1;

    return temp;
}

//convierte una cadena en larga
long Integer::parse(const std::string &sub) {
    return std::stol(sub);
}

#endif


