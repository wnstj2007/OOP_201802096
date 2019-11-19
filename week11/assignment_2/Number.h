//
// Created by 김혁진 on 2019/11/11.
//

#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include <utility>

class Number {
protected:
    enum type {
        INTEGER,
        FLOAT,
        COMPLEX
    };
public:
    virtual Number* add(Number*) = 0;
    virtual Number* sub(Number*) = 0;
    virtual Number* mul(Number*) = 0;
    virtual Number* div(Number*) = 0;

    virtual type types() const = 0;
    virtual std::string to_string() const = 0;
};

#endif // NUMBER_H
