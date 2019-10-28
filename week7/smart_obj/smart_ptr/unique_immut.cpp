//
// Created by 김혁진 on 14/10/2019.
//

#include "unique_immut.h"

namespace ptr {
unique_immut::unique_immut() {
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj) {
    _mgr = new mgr(obj);
}

void unique_immut::release() {
	if(_mgr != nullptr) {
		delete _mgr;
		_mgr = nullptr;
	}
}

Object* unique_immut::get() const{
	if(_mgr == nullptr) {
		return nullptr;
	}
	return _mgr->ptr;
}

unique_immut::unique_immut(const unique_immut &immut) {
    if (immut._mgr) {
        int val = immut._mgr->ptr->get();
        _mgr = new mgr(val);
    }
}

unique_immut unique_immut::operator+(unique_immut &unique) {
	int val1 = _mgr->ptr->get();
	int val2 = unique.get()->get();
	int sum = val1+val2;
	this->release();
	unique.release();
	unique_immut n(new Object(sum));
	return n;
}
unique_immut unique_immut::operator-(unique_immut &unique) {
	int val1 = _mgr->ptr->get();
        int val2 = unique.get()->get();
        int sub = val1-val2;
        this->release();
        unique.release();
        unique_immut n(new Object(sub));
        return n;
	
}
unique_immut unique_immut::operator*(unique_immut &unique) {
	int val1 = _mgr->ptr->get();
        int val2 = unique.get()->get();
        int mul = val1*val2;
        this->release();
        unique.release();
        unique_immut n(new Object(mul));
        return n;
}
unique_immut unique_immut::operator/(unique_immut &unique) {
	int val1 = _mgr->ptr->get();
        int val2 = unique.get()->get();
        int div = val1/val2;
        this->release();
        unique.release();
        unique_immut n(new Object(div));
        return n;
}
Object* unique_immut::operator->() {
	return _mgr->ptr;
}

unique_immut& unique_immut::operator=(unique_immut& r) {
	int val = _mgr->ptr->get();
	int rval = r.get()->get();
	if(val == rval) {
		return *this;
	}
	this->~unique_immut();
	return r;
}

unique_immut::~unique_immut() {
    release();
}
} // end of namespace ptr
