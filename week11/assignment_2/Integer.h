//
// Created by 김혁진 on 2019/11/11.
//

#ifndef INTEGER_H
#define INTEGER_H

#include "Number.h"

class Integer : public Number {
private:
    static int parse_string(const std::string& str);
    int value;
public:
    Integer();
    explicit Integer(int _value);
    explicit Integer(const std::string& str);

    Number* add(Number* num);
    Number* sub(Number* num);
    Number* mul(Number* num);
    Number* div(Number* num);

    void set_val(int val);
    int val() const;
    type types() const;
    std::string to_string() const;
};


#endif // INTEGER_H
