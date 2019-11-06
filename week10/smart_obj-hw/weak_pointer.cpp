//
// Created by 김혁진 on 2019/10/28.
//

#include "weak_pointer.h"

namespace ptr {
ptr::weak_pointer::weak_pointer() {
    // TODO: Fill it
    // ptr을 default값으로 nullptr로 설정
}

weak_pointer::weak_pointer(shared_ref &shared) {
    // TODO: Fill it
    // shared의 get으로 student* 값을 ptr의 값으로 설정
}

weak_pointer::weak_pointer(const weak_pointer &weak) {
    // TODO: Fill it
    // weak의 ptr을 ptr값으로 설정
}

int weak_pointer::is_expired() {
    // TODO: Fill it
    // ptr_map에 자신의 ptr 값이 있는지 확인하고
    // ptr_map의 value인 mgr이 해제되었는지 확인
    // ptr_map에서 ptr을 관리하는 mgr이 있으면(nullptr이 아니면) 1 리턴
    // 아닐 경우 0 리턴

    return 0;
}

student *weak_pointer::get() {
    // TODO: Fill it
    // ptr_map에서 ptr을 관리하는 mgr이 있으면(nullptr이 아니면) ptr을 리턴
    // 아닌 경우 nullptr 리턴
    return nullptr;
}

}
