//
// Created by 김혁진 on 2019/10/25.
//

#include "smart_ptr/shared_mut.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace ptr;

typedef ptr::shared_mut shared_ref;
typedef ptr::unique_immut unique_obj;

static std::vector<int(*)()> vec;

void print_error(string& err) {
    cout <<"\n\n\n"<< err << endl;
}

/**
 * Shared ref TEST
 */
int test_shared_plus1() {
    shared_ref a(new Object(11));
    shared_ref b(new Object(7));
    shared_ref c = a + b;

    int result = 1;
    if (a->get() != 11) {
        result = 0;
        string str(__func__, ": Error is a->get() != 11");
        print_error(str);
    }

    if (b->get() != 7) {
        result = 0;
        string str(__func__, ": Error is b->get() != 7");
        print_error(str);
    }

    if (c->get() != 18) {
        result = 0;
        string str(__func__, ": Error is c->get() != 18");
        print_error(str);
    }
    return result;
}

int test_shared_plus2() {
    shared_ref a(new Object(11));
    shared_ref b(new Object(7));
    shared_ref c = a + b;

    int result = 1;
    if (a.count() != 1) {
        result = 0;
        string str(__func__, ": Error is a.count() != 1");
        print_error(str);
    }

    if (b.count() != 1) {
        result = 0;
        string str(__func__, ": Error is b.count() != 1");
        print_error(str);
    }

    if (c.count() != 1) {
        result = 0;
        string str(__func__, ": Error is c.count() != 1");
        print_error(str);
    }
    return result;
}

int test_shared_plus3() {
    shared_ref a(new Object(11));
    shared_ref b = a;
    shared_ref c = a + b;

    int result = 1;
    if (a.count() != 2) {
        result = 0;
        string str(__func__, ": Error is a.count() != 2");
        print_error(str);
    }

    if (b.count() != 2) {
        result = 0;
        string str(__func__, ": Error is b.count() != 2");
        print_error(str);
    }

    if (c.count() != 1) {
        result = 0;
        string str(__func__, ": Error is c.count() != 1");
        print_error(str);
    }
    return result;
}

int test_shared() {
    int result = 1;

    shared_ref a(new Object(11));
    shared_ref b = a;
    {
        shared_ref c = b;
        if (a.count() != 3) {
            result = 0;
            string str(__func__, ": Error is a.count() != 3");
            print_error(str);
        }

        if (b.count() != 3) {
            result = 0;
            string str(__func__, ": Error is b.count() != 3");
            print_error(str);
        }
        if (c.count() != 3) {
            result = 0;
            string str(__func__, ": Error is c.count() != 3");
            print_error(str);
        }
    }

    if (a.count() != 2) {
        result = 0;
        string str(__func__, ": Error is a.count() != 2");
        print_error(str);
    }

    if (b.count() != 2) {
        result = 0;
        string str(__func__, ": Error is b.count() != 2");
        print_error(str);
    }

    return result;
}

int test_shared_base() {
    int result = 1;
    Object * obj = new Object(11);
    shared_ref a(obj);
    shared_ref b = a;

    if (a.get() != obj) {
        result = 0;
        string str(__func__, ": Error is a.get() != obj");
        print_error(str);
    }

    if (a.get() != b.get()) {
        result = 0;
        string str(__func__, ": Error is a.get() != b.get()");
        print_error(str);
    }

    if (a->get() != 11) {
        result = 0;
        string str(__func__, ": Error is a.get() != 11");
        print_error(str);
    }

    if (b->get() != 11) {
        result = 0;
        string str(__func__, ": Error is a.get() != 11");
        print_error(str);
    }

    return result;
}

int test_shared_base2() {
    int result = 1;
    Object * obj = new Object(11);
    shared_ref a(obj);
    shared_ref b = a;
    {
        shared_ref c = b;
        c.release();
        if (a.count() != 2) {
            result = 0;
            string str(__func__, ": Error is a.count() != 2");
            print_error(str);
        }
        if (b.count() != 2) {
            result = 0;
            string str(__func__, ": Error is b.count() != 2");
            print_error(str);
        }
        if (c.count() != 0) {
            result = 0;
            string str(__func__, ": Error is c.count() != 0");
            print_error(str);
        }
        if (c.get() != nullptr) {
            result = 0;
            string str(__func__, ": Error is c.get() != nullptr");
            print_error(str);
        }
        c.release();
        if (a.count() != 2) {
            result = 0;
            string str(__func__, ": Error is a.count() != 2");
            print_error(str);
        }
        if (b.count() != 2) {
            result = 0;
            string str(__func__, ": Error is b.count() != 2");
            print_error(str);
        }
        if (c.count() != 0) {
            result = 0;
            string str(__func__, ": Error is c.count() != 0");
            print_error(str);
        }
        if (c.get() != nullptr) {
            result = 0;
            string str(__func__, ": Error is c.get() != nullptr");
            print_error(str);
        }
    }

    return result;
}

/**
 * Unique obj TEST
 */
int test_unique_plus1() {
    int result = 1;
    unique_obj a(new Object(11));
    unique_obj b(new Object(7));
    if (a->get() != 11) {
        result = 0;
        string str(__func__, ": Error is a->get() != 11");
        print_error(str);
    }

    if (b->get() != 7) {
        result = 0;
        string str(__func__, ": Error is b->get() != 7");
        print_error(str);
    }

    unique_obj c = a + b;

    if (a.get() != nullptr) {
        result = 0;
        string str(__func__, ": Error is a.get() != nullptr");
        print_error(str);
    }

    if (b.get() != nullptr) {
        result = 0;
        string str(__func__, ": Error is b.get() != nullptr");
        print_error(str);
    }

    if (c->get() != 18) {
        result = 0;
        string str(__func__, ": Error is c->get() != 18");
        print_error(str);
    }
    return result;
}

int test_unique_base() {
    int result = 1;
    unique_obj a(new Object(30));
    {
        unique_obj c(new Object(30));
        if (a->get() != c->get()) {
            result = 0;
            string str(__func__, ": Error is a->get() != c->get()");
            print_error(str);
        }
    }
    return result;
}

int test_unique_base2() {
    int result = 1;
    {
        unique_obj c(new Object(30));
        c.release();
        if (c.get() != nullptr) {
            result = 0;
            string str(__func__, ": Error is c.get() != nullptr");
            print_error(str);
        }
        c.release();
        if (c.get() != nullptr) {
            result = 0;
            string str(__func__, ": Error is c.get() != nullptr");
            print_error(str);
        }
    }

    return result;
}

void init() {
    vec.push_back(test_shared_plus1);
    vec.push_back(test_shared_plus2);
    vec.push_back(test_shared_plus3);
    vec.push_back(test_shared);
    vec.push_back(test_shared_base);
    vec.push_back(test_shared_base2);

    vec.push_back(test_unique_base);
    vec.push_back(test_unique_base2);
    vec.push_back(test_unique_plus1);
}

int test_all() {
    int result = 0;
    for (int i = 0; i < vec.size(); ++i) {
        result += (*vec[i])();
    }
    return result;
}

int main() {
    init();
    int result = test_all();
    cout << "Test Result (All is "<< vec.size() << ")\nSuccess : " << result << "\nFail: " << vec.size()-result << endl;
    return 0;
}
