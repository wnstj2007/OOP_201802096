#ifndef SMART_PTR_STUDENT_H
#define SMART_PTR_STUDENT_H

#include "human.h"

class student : public human {
private:
    int student_id;
public:
    student();
    explicit student(char* name);
    explicit student(int student_id);
    student(char* name, int student_id);

    int get_student_id();
    int get_id();
};


#endif //SMART_PTR_STUDENT_H
