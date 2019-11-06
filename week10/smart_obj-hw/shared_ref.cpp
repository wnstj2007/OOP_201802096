//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_ref.h"

namespace ptr {
shared_ref::shared_ref() {
    // TODO: Fill it
    // _mgr의 default 값을 빈 mgr으로 설정
}

shared_ref::shared_ref(student* student) {
    // TODO: Fill it
    // ptr_map에 student의 주소가 있으면 _mgr을 빈 mgr으로 설정
    // ptr_map에 student의 주소가 없으면 _mgr을 student의 메모리를 관리하는 mgr으로 설정하고
    // ptr_map에 key를 student의 주소로 하고 value를 mgr로 등록 ==> student의 주소가 shared_ref의 mgr로 관리되는지 확인 가능
}

shared_ref::shared_ref(const shared_ref& shared) {
    // TODO: Fill it
    // shared_ref 의 _mgr을 자신의 _mgr로 설정
    // reference가 증가하였으므로 increase 호출
}

shared_ref::~shared_ref() {
    // TODO: Fill it
    // mgr을 반환하는 release를 호출하게 만듦
}

void shared_ref::release() {
    // TODO: Fill it
    // _mgr이 nullptr일 경우 아무 작업도 하지 않음
    // _mgr이 nullptr가 아닐 경우 _mgr의 count를 감소시키고
    // count가 0인 경우 ptr_map에서 _mgr의 ptr가 key인 value를 nullptr로 설정하고 _mgr을 delete함
    // ==> student 포인터에 대해 mgr 관리가 끝났음을 알려줌
}

student *shared_ref::get() const {
    // TODO: Fill it
    // _mgr이 nullptr일 경우 nullptr 반환하고
    // _mgr이 nullptr가 아닐 경우 _mgr의 ptr을 return 하도록 구현

    return nullptr;
}

void shared_ref::increase() {
    // TODO: Fill it
    // _mgr이 nullptr일 경우 아무런 작업도 하지 않음
    // _mgr이 nullptr가 아닐 경우 _mgr의 count를 증가시킴
}

shared_ref &shared_ref::operator=(const shared_ref &r) {
    // TODO: Fill it
    // r의 주소가 this와 같은 경우 아무런 작업도 하지 않고 *this를 리턴
    // ex: a = a;
    // r의 주소가 this와 다른 경우 현재 _mgr을 release하고 r의 _mgr을 this의 _mgr로 설정. 그 후 increase
    // ex: b = a; -> a의 값을 가리키는 것이 a와 b 두 값이 됨
    return *this;
}

student *shared_ref::operator->() {
    // TODO: Fill it
    // _mgr이 nullptr일 경우 nullptr 반환
    // _mgr이 nullptr가 아닐 경우 _mgr의 ptr을 반환

    return nullptr;
}

int shared_ref::count() {
    // TODO: Fill it
    // _mgr이 nullptr일 경우 0을 반환
    // _mgr이 nullptr가 아닐 경우 _mgr의 count를 반환

    return 0;
}

}
