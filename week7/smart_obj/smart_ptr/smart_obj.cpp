//
// Created by 김혁진 on 14/10/2019.
//

#include "smart_obj.h"

namespace ptr {
smart_obj::smart_obj() {
    std::cout << "Smart pointer Creation" << std::endl;
};

smart_obj::~smart_obj() {
    std::cout << "Smart pointer Deletion" << std::endl;
};
} // end of namespace ptr
