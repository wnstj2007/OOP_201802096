//
// Created by 김혁진 on 14/10/2019.
//

#ifndef SMART_PTR_SHARED_REF_H
#define SMART_PTR_SHARED_REF_H

#include "smart_obj.h"

namespace ptr {
class shared_ref : public smart_obj {
private:
    mgr* _mgr;
    void increase();
public:
    shared_ref();
    explicit shared_ref(student* student);
    shared_ref(const shared_ref& shared);
    ~shared_ref();

    student* get() const;
    void release();
    int count();

    student* operator->();

    shared_ref&operator=(const shared_ref &r);
}; // end of class shared_ref
} // end of namespace ptr

#endif //SMART_PTR_SHARED_REF_H
