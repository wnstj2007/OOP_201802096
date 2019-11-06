//
// Created by 김혁진 on 14/10/2019.
//

#ifndef SMART_PTR_SMART_OBJ_H
#define SMART_PTR_SMART_OBJ_H

#include <map>
#include "student.h"

namespace ptr {
class smart_obj {
protected:
    struct mgr {
        mgr() {
            ptr = nullptr;
            count = 0;
        }
        explicit mgr(int student_id) {
            ptr = new student(student_id);
            count = 1;
        }
        explicit mgr(char* name, int student_id) {
            ptr = new student(name, student_id);
            count = 1;
        }
        explicit mgr(student* _ptr) {
            ptr = _ptr;
            count = 1;
        }
        ~mgr() {
            delete(ptr);
            ptr = nullptr;
        }
        student* ptr;
        int count;
    };

    static mgr* const empty_mgr;
    static std::map<student*, mgr*> ptr_map;
public:
    smart_obj();
    ~smart_obj();
}; // end of class smart_obj
} // end of namespace ptr

#endif //SMART_PTR_SMART_OBJ_H
