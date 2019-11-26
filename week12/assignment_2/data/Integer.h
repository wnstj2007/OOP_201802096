//
// Created by 김혁진 on 2019/11/19.
//

#ifndef INTEGER_H
#define INTEGER_H


#include "Object.h"

class Integer : public Object<int> {
private:
    int _val;
public:
    explicit Integer(int value);

    int val();
    void set_val(const int& value);

    static json_object* parse(const char *, int length);
    _type type();
    std::string to_string();
};


#endif //INTEGER_H
