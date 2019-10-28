//
// Created by 김혁진 on 14/10/2019.
//

#ifndef SMART_PTR_OBJECT_H
#define SMART_PTR_OBJECT_H

#include <iostream>

class Object {
private:
    int val;
public:
    Object();
    explicit Object(int _val);
    ~Object();

    int get() const;

    Object operator+(const Object &obj);
    Object operator-(const Object &obj);
    Object operator*(const Object &obj);
    Object operator/(const Object &obj);
}; // end of class Object

#endif //SMART_PTR_OBJECT_H
