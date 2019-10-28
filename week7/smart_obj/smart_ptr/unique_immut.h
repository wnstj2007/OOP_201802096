//
// Created by 김혁진 on 14/10/2019.
//

#ifndef SMART_PTR_UNIQUE_IMMUT_H
#define SMART_PTR_UNIQUE_IMMUT_H

#include "smart_obj.h"

namespace ptr {
class unique_immut : public smart_obj {
private:
    mgr* _mgr;
public:
    unique_immut();
    unique_immut(const unique_immut& immut);
    explicit unique_immut(Object* obj);
    ~unique_immut();

    Object* get() const;
    void release();

    unique_immut operator+(unique_immut &unique);
    unique_immut operator-(unique_immut &unique);
    unique_immut operator*(unique_immut &unique);
    unique_immut operator/(unique_immut &unique);
    Object* operator->();

    unique_immut&operator=(unique_immut& r);
}; // end of class unique_immut
} // end of namespace ptr

#endif //SMART_PTR_UNIQUE_IMMUT_H
