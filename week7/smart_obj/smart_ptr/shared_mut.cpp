//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_mut.h"

namespace ptr {
shared_mut::shared_mut() {
	_mgr = new mgr();
}

shared_mut::shared_mut(Object* _obj) {
	_mgr = new mgr(_obj);
}

Object* shared_mut::get() const{
	if(_mgr == nullptr) {
		return nullptr;
        }
	return _mgr->ptr;
}

void shared_mut::release() {
	_mgr->count -= 1;
	if(_mgr->count == 0) {
		delete(_mgr);
		_mgr = nullptr;
	}
}

int shared_mut::count() {
	return _mgr->count;
}
	
shared_mut shared_mut::operator+(const shared_mut &shared) {
	int val1 = _mgr->ptr->get();
	int val2 = shared.get()->get();
	int val3 = val1+val2;
	shared_mut n(new Object(val3));
	return n;
}
	
shared_mut shared_mut::operator-(const shared_mut &shared) {
	int val1 = _mgr->ptr->get();
        int val2 = shared.get()->get();
        int val3 = val1-val2;
        shared_mut n(new Object(val3));
        return n;
}

shared_mut shared_mut::operator*(const shared_mut &shared) {
	int val1 = _mgr->ptr->get();
        int val2 = shared.get()->get();
        int val3 = val1*val2;
        shared_mut n(new Object(val3));
        return n;
}

shared_mut shared_mut::operator/(const shared_mut &shared) {
	int val1 = _mgr->ptr->get();
        int val2 = shared.get()->get();
        int val3 = val1/val2;
        shared_mut n(new Object(val3));
        return n;
}

Object* shared_mut::operator->() {
	return _mgr->ptr;
}
	
shared_mut& shared_mut::operator=(const shared_mut &r) {
	int val = r.get()->get();
	shared_mut n(new Object(val));
        return n;
}
	
shared_mut::~shared_mut() {
	release();
}
} // end of namespace ptr
