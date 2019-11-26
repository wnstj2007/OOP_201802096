//
// Created by 김혁진 on 2019/11/19.
//

#ifndef OBJECT_H
#define OBJECT_H

#include "../json_object.h"

template <typename T>
class Object : public json_object {
public:
    virtual T val() = 0;
    virtual void set_val(const T&) = 0;
};

#endif //OBJECT_H
