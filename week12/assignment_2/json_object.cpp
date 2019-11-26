#include "json_object.h"
#include "json_list.h"
#include "json_dict.h"
#include "data/String.h"
#include "data/Integer.h"

int json_object::_index = 0;

json_object* json_object::parse(const char* a, int length) {
	json_object::_index = 0;
	while(_index < length) {
		if(*(a+_index) == '\"') {
			return String::parse((a+_index), 0, '\"');
		}
		else if(*(a+_index) == '\'') {
			return String::parse((a+_index), 0, '\'');
		}
		else if(*(a+_index) == '[') {
			return json_list::parse((a+_index), 0);
		}
		else if(*(a+_index) == '{') {
			return json_dict::parse((a+_index), 0);
		}
		else if(*(a+_index)>='0' && *(a+_index)<='9') {
			return Integer::parse((a+_index), 0);
		}
		_index++;
	}
}

json_object* json_object::parse(const std::string& a) {
	return parse(a.c_str(), a.length());
}
