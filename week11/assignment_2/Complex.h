//
// Created by 김혁진 on 2019/11/11.
//

#ifndef COMPLEX_H
#define COMPLEX_H

#include "Number.h"

class Complex : public Number {
private:
    // 0번째 값이 real 값, 1번째 값이 imag 값
    std::pair<double, double> value;
public:
    Complex();
    explicit Complex(float _val1, float _val2);

    Number* add(Number* num);
    Number* sub(Number* num);
    Number* mul(Number* num);
    Number* div(Number* num);

    double real() const;
    double imag() const;
    void set_val(std::pair<double, double> val);
    void set_val(double real, double imag);
    std::pair<double, double> val() const;
    type types() const;
    std::string to_string() const;
};

#endif // COMPLEX_H
