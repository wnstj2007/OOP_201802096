//
// Created by 김혁진 on 2019/10/25.
//

#include "shared_ref.h"
#include "weak_pointer.h"
#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;
using namespace ptr;

static std::vector<int(*)()> vec;

void print_error(std::string& err) {
    cout << err << endl;
}

/**
 * Student TEST
 */
int test_student1() {
    human * h = new human("KHZ");
    student * s = new student("HTW");
    human * sh = new student("ABC", 201950219);

    int result = 1;
    if (h->get_name() == nullptr || strcmp(h->get_name(), "KHZ") != 0) {
        result = 0;
        std::string str("test_student1: Error is strcmp(h->get_name(), \"KHZ\") != 0");
        print_error(str);
    }

    if (s->get_name() == nullptr || strcmp(s->get_name(), "HTW") != 0) {
        result = 0;
        std::string str("test_student1: Error is strcmp(s->get_name(), \"HTW\") != 0");
        print_error(str);
    }

    if (sh->get_name() == nullptr || strcmp(sh->get_name(), "ABC") != 0) {
        result = 0;
        std::string str("test_student1: Error is strcmp(sh->get_name(), \"ABC\") != 0");
        print_error(str);
    }

    student* r = (student*)(sh);
    if (r->get_student_id() != 201950219) {
        result = 0;
        std::string str("test_student1: Error is r->get_student_id() != 201950219");
        print_error(str);
    }

    return result;
}

int test_student2() {
    human * h = new human("KHZ");
    student * s = new student("HTW");
    human * sh = new student("ABC", 201950219);

    int result = 1;
    if (h->get_id() != 0) {
        result = 0;
        std::string str("test_student2: Error is h->get_id() != 0");
        print_error(str);
    }

    if (s->get_id() != 1) {
        result = 0;
        std::string str("test_student2: Error is s->get_id() != 0");
        print_error(str);
    }

    if (sh->get_id() != 1) {
        result = 0;
        std::string str("test_student2: Error is sh->get_id() != 0");
        print_error(str);
    }

    return result;
}

/**
 * Shared ref TEST
 */
int test_shared1() {
    shared_ref a(new student(201950219));
    shared_ref b(new student(201950221));

    int result = 1;
    if (a.get() == nullptr || a.get()->get_student_id() != 201950219) {
        result = 0;
        std::string str("test_shared1: Error is a->get_student_id() != 201950219");
        print_error(str);
    }

    if (b.get() == nullptr || b.get()->get_student_id() != 201950221) {
        result = 0;
        std::string str("test_shared1: Error is b->get_student_id() != 201950221");
        print_error(str);
    }

    return result;
}

int test_shared2() {
    shared_ref a(new student(201950219));
    shared_ref b(new student("B"));

    int result = 1;
    if (a.get() == nullptr || a->get_name() != nullptr) {
        result = 0;
        std::string str("test_shared2: Error is a->get_name() != nullptr");
        print_error(str);
    }

    if (a.get() == nullptr || a->get_student_id() != 201950219) {
        result = 0;
        std::string str("test_shared2: Error is a->get_student_id() != 201950219");
        print_error(str);
    }

    if (b.get() == nullptr || strcmp(b->get_name(), "B") != 0) {
        result = 0;
        std::string str("test_shared2: Error is strcmp(b->get_name(), \"B\") != 0");
        print_error(str);
    }

    if (b.get() == nullptr || b->get_student_id() != -1) {
        result = 0;
        std::string str("test_shared2: Error is b->get_student_id() != -1");
        print_error(str);
    }

    return result;
}

int test_shared3() {
    shared_ref a(new student(201950219));
    shared_ref b(new student(201950221));
    shared_ref c = b;

    int result = 1;
    if (a.get() == nullptr || a->get_student_id() != 201950219) {
        result = 0;
        std::string str("test_shared3: Error is a->get_student_id() != 201950219");
        print_error(str);
    }

    if (b.get() == nullptr || b->get_student_id() != 201950221) {
        result = 0;
        std::string str("test_shared3: Error is b->get_student_id() != 201950221");
        print_error(str);
    }

    if (c.get() == nullptr || c->get_student_id() != 201950221) {
        result = 0;
        std::string str("test_shared3: Error is c->get_student_id() != 201950221");
        print_error(str);
    }

    return result;
}

int test_shared4() {
    shared_ref a(new student(201950219));
    shared_ref b(new student(201950221));
    b = a;

    int result = 1;
    if (a.get() == nullptr || a->get_student_id() != 201950219) {
        result = 0;
        std::string str("test_shared4: Error is a->get_student_id() != 201950219");
        print_error(str);
    }
    if (b.get() == nullptr || b->get_student_id() != 201950219) {
        result = 0;
        std::string str("test_shared4: Error is b->get_student_id() != 201950219");
        print_error(str);
    }

    return result;
}

int test_shared5() {
    shared_ref a(new student(201950219));
    shared_ref b(new student(201950221));
    b = a;

    int result = 1;
    if (a.count() != 2) {
        result = 0;
        std::string str("test_shared5: Error is a.count() != 2");
        print_error(str);
    }

    if (b.count() != 2) {
        result = 0;
        std::string str("test_shared5: Error is b.count() != 2");
        print_error(str);
    }

    return result;
}

int test_shared6() {
    shared_ref a(new student(201950219));
    shared_ref b(new student(201950221));
    shared_ref c = b;

    int result = 1;
    if (a.count() != 1) {
        result = 0;
        std::string str("test_shared6: Error is a.count() != 1");
        print_error(str);
    }

    if (b.count() != 2) {
        result = 0;
        std::string str("test_shared6: Error is b.count() != 2");
        print_error(str);
    }

    if (c.count() != 2) {
        result = 0;
        std::string str("test_shared6: Error is c.count() != 2");
        print_error(str);
    }

    return result;
}

int test_shared7() {
    shared_ref a(new student(201950219));
    shared_ref b(new student(201950221));

    int result = 1;
    {
        shared_ref c = b;

        if (c.count() != 2) {
            result = 0;
            std::string str("test_shared7: Error is c.count() != 1");
            print_error(str);
        }
    }

    if (a.count() != 1) {
        result = 0;
        std::string str("test_shared7: Error is a.count() != 1");
        print_error(str);
    }

    if (b.count() != 1) {
        result = 0;
        std::string str("test_shared7: Error is b.count() != 1");
        print_error(str);
    }

    return result;
}

int test_shared8() {
    shared_ref a(new student(201950219));
    shared_ref b(new student(201950221));

    int result = 1;
    shared_ref c = b;
    c.release();
    if (c.count() != 0) {
        result = 0;
        std::string str("test_shared8: Error is c.count() != 0");
        print_error(str);
    }

    if (c.get() != nullptr) {
        result = 0;
        std::string str("test_shared8: Error is c.get() != nullptr");
        print_error(str);
    }

    if (a.count() != 1) {
        result = 0;
        std::string str("test_shared8: Error is a.count() != 1");
        print_error(str);
    }

    if (b.count() != 1) {
        result = 0;
        std::string str("test_shared8: Error is b.count() != 1");
        print_error(str);
    }

    return result;
}

int test_shared9() {
    shared_ref a(new student(201950219));
    shared_ref b(new student(201950221));

    int result = 1;
    shared_ref c = b;
    c.release();
    c.release(); // Double Release Check
    if (c.count() != 0) {
        result = 0;
        std::string str("test_shared9: Error is c.count() != 0");
        print_error(str);
    }
    if (c.get() != nullptr) {
        result = 0;
        std::string str("test_shared9: Error is c.get() != nullptr");
        print_error(str);
    }

    if (a.count() != 1) {
        result = 0;
        std::string str("test_shared9: Error is a.count() != 1");
        print_error(str);
    }

    if (b.count() != 1) {
        result = 0;
        std::string str("test_shared9: Error is b.count() != 1");
        print_error(str);
    }

    return result;
}

/**
 * Weak pointer Test
 */
int test_weak1() {
    shared_ref a(new student(201950219));
    weak_pointer b(a);

    int result = 1;
    if (a.count() != 1) {
        result = 0;
        std::string str("test_weak1: Error is a.count() != 1");
        print_error(str);
    }

    if (a.get() != b.get()) {
        result = 0;
        std::string str("test_weak1: Error is a.get() != b.get()");
        print_error(str);
    }

    return result;
}

int test_weak2() {
    shared_ref a(new student(201950219));
    int result = 1;
    weak_pointer b(a);
    if (b.is_expired()) {
        result = 0;
        std::string str("test_weak2: Error is b.is_expired()");
        print_error(str);
    }
    a.release();
    if (a.get() != nullptr) {
        result = 0;
        std::string str("test_weak2: Error is a.get() != nullptr");
        print_error(str);
    }

    if (!b.is_expired()) {
        result = 0;
        std::string str("test_weak2: Error is !b.is_expired()");
        print_error(str);
    }

    return result;
}

int test_weak3() {
    shared_ref a(new student(201950219));
    weak_pointer b(a);
    a.release();

    int result = 1;

    if (!b.is_expired()) {
        result = 0;
        std::string str("test_weak3: Error is !b.is_expired()");
        print_error(str);
    }

    return result;
}

int test_weak4() {
    shared_ref a(new student(201950219));
    weak_pointer b(a);
    weak_pointer c = b;

    a.release();

    int result = 1;

    if (b.get() != nullptr) {
        result = 0;
        std::string str("test_weak4: Error is b.get() != nullptr");
        print_error(str);
    }

    if (c.get() != nullptr) {
        result = 0;
        std::string str("test_weak4: Error is c.get() != nullptr");
        print_error(str);
    }

    if (!b.is_expired()) {
        result = 0;
        std::string str("test_weak4: Error is !b.is_expired()");
        print_error(str);
    }

    if (!c.is_expired()) {
        result = 0;
        std::string str("test_weak4: Error is !c.is_expired()");
        print_error(str);
    }

    return result;
}

void init() {
    vec.push_back(test_student1);
    vec.push_back(test_student2);

    vec.push_back(test_shared1);
    vec.push_back(test_shared2);
    vec.push_back(test_shared3);
    vec.push_back(test_shared4);
    vec.push_back(test_shared5);
    vec.push_back(test_shared6);
    vec.push_back(test_shared7);
    vec.push_back(test_shared8);
    vec.push_back(test_shared9);

    vec.push_back(test_weak1);
    vec.push_back(test_weak2);
    vec.push_back(test_weak3);
    vec.push_back(test_weak4);
}

int test_all() {
    int result = 0;
    for (int i = 0; i < vec.size(); ++i) {
        int a = (*vec[i])();
        if (a) {
            cout << i << endl;
        }
        result += a;
    }
    return result;
}

int main() {
    init();
    int result = test_all();
    cout << "Test Result (All Test is "<< vec.size() << ")\nSuccess : " << result << "\nFail: " << vec.size()-result << endl;
    return 0;
}