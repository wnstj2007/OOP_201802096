//
// Created by 김혁진 on 2019/11/11.
//

#ifndef FLOAT_H
#define FLOAT_H

#include "Number.h"

class Float : public Number {
private:
    static double parse_string(std::string str);
    double value;
public:
    Float();
    explicit Float(double _value);
    explicit Float(const std::string& str);

    Number* add(Number* num);
    Number* sub(Number* num);
    Number* mul(Number* num);
    Number* div(Number* num);

    void set_val(double val);
    double val() const;
    type types() const;
    std::string to_string() const;
};


#endif // FLOAT_H
