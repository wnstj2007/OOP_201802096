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

shared_mut::shared_mut(const shared_mut& shared) {
	_mgr = shared._mgr;
	increase();
}

Object* shared_mut::get() const{
	if(_mgr == nullptr) {
		return nullptr;
        }
	return _mgr->ptr;
}

void shared_mut::release() {
	_mgr->count--;
	if(_mgr->count == 0) {
		delete(_mgr);
		_mgr = nullptr;
	}
	_mgr = new mgr();
}

int shared_mut::count() {
	return _mgr->count;
}

void shared_mut::increase() {
	_mgr->count = this->count()+1;
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
	_mgr = r._mgr;
	return *this;
}
	
shared_mut::~shared_mut() {
	release();
}
} // end of namespace ptr
