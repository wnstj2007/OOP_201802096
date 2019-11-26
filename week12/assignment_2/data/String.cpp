#include "String.h"
#include "../json_object.h"

String::String(const std::string& str) {
	_val = str;
}

std::string String::val() {
	return _val;
}

void String::set_val(const std::string& str) {
	_val = str;
}

json_object* String::parse(const char* a, int length, char base) {
	std::string b = "";
	int c=1;
	for(int i=1; *(a+i)!=base; i++) {
		b += *(a+i);
		c++;
	}
	c++;
	_index += c+1;
	if(base == '\'')
		return new String('\''+b+'\'');
	else if(base == '\"')
		return new String('\"'+b+'\"');
}

json_object::_type String::type() {
	return STRING;
}

std::string String::to_string() {
	return _val;
}
