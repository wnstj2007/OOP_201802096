#include "Integer.h"
#include "../json_object.h"

Integer::Integer(int value) {
	_val = value;
}

int Integer::val() {
	return _val;
}

void Integer::set_val(const int& value) {
	_val = value;
}

json_object* Integer::parse(const char* a, int length) {
	std::string b = "";
	int c=1;
	for(int i = 0; *(a+i)<='9'&&*(a+i)>='0'; i++) {
		b += *(a+i);
		c++;
	}
	_index += c+1;
	return new Integer(atoi(b.c_str()));
}

json_object::_type Integer::type() {
	return INT;	
}

std::string Integer::to_string() {
	return std::to_string(_val);
}
