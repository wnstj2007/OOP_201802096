#include <iostream>
#include "smart_ptr/object.h"
#include "smart_ptr/shared_mut.h"

using namespace ptr;


int main() {
    std::cout << "Shared Mutable Pointer" << std::endl;
    {
        shared_mut p(new Object(3));
        shared_mut q(new Object(5));
        shared_mut r = p + q;

        std::cout << "Hello, Unique_immut! " <<  r->get() << std::endl;
    }
    std::cout << "\n\nUnique Immutable Pointer" << std::endl;
    {
        unique_immut p(new Object(3));
        unique_immut q(new Object(5));
        unique_immut r = p + q;

        std::cout << "Hello, Unique_immut! " <<  r->get() << std::endl;
    }
    return 0;
}