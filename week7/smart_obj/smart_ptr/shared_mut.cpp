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
//	return _mgr->count;
}
	
shared_mut shared_mut::operator+(const shared_mut &shared) {
/*	shared_mut t = *this;
	t.ptr += shared.ptr;
	return t;
*/}
	
shared_mut shared_mut::operator-(const shared_mut &shared) {
/*	shared_mut t = *this;
	t.ptr -= shared.ptr;
	return t;
*/}

shared_mut shared_mut::operator*(const shared_mut &shared) {
/*	shared_mut t = *this;
	t.ptr *= shared.ptr;
	return t;
*/}

shared_mut shared_mut::operator/(const shared_mut &shared) {
/*	shared_mut t = *this;
	t.ptr /= shared.ptr;
	return t;
*/}

Object* shared_mut::operator->() {
//	return this->ptr;
}
	
shared_mut& shared_mut::operator=(const shared_mut &r) {
//	shared_mut a = r;
//	return a;
}
	
shared_mut::~shared_mut() {
	release();
}
} // end of namespace ptr
