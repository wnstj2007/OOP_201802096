//
// Created by 김혁진 on 14/10/2019.
//

#include "object.h"

Object::Object() {
    val = 0;
    std::cout << "Create Object " << val << std::endl;
}

Object::Object(int _val) {
    val = _val;
    std::cout << "Create Object " << val << std::endl;
}

Object::~Object() {
    std::cout << "Delete Object " << val << std::endl;
}

int Object::get() const {
    return val;
}

Object Object::operator+(const Object &obj) {
    Object l = *this;
    l.val += obj.val;
    return l;
}

Object Object::operator-(const Object &obj) {
    Object l = *this;
    l.val -= obj.val;
    return l;
}

Object Object::operator*(const Object &obj) {
    Object l = *this;
    l.val *= obj.val;
    return l;
}

Object Object::operator/(const Object &obj) {
    Object l = *this;
    l.val /= obj.val;
    return l;
}
