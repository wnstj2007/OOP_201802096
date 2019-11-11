//
// Created by 김혁진 on 2019/10/28.
//

#include "human.h"

human::human() {
    // TODO: Fill it
    // name 의 default 값을 nullptr로 지정
    name = nullptr;
}

human::human(char name[]) {
    // TODO: Fill it
    // name 의 값을 지정
    this->name = name;
}

char *human::get_name() {
    // TODO: Fill it
    // name 의 값을 반환하게 구현
    return this->name;
}

int human::get_id() {
    // TODO: Fill it
    // 0을 리턴하도록 구현
    return 0;
}
