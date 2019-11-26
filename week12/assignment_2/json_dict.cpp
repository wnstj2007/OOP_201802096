#include "json_list.h"
#include "json_dict.h"
#include "json_object.h"
#include "data/Integer.h"
#include "data/String.h"

json_dict::json_dict() {

}

void json_dict::put(json_object* key, json_object* val) {
	if(v.size() == 0) v.push_back(std::make_pair(key, val));
	else {
	int i = find(key);
	if(i != -1) {
		v[i] = std::make_pair(key, val);
	}
	else
		v.push_back(std::make_pair(key, val));
	}
}

int json_dict::find(json_object* key) {
	int index = -1;
	for(auto it = v.begin(); it != v.end(); it++) {
        	if ((*it).first == key) {
            		break;
        	}
        	index += 1;
    	}
	return index;
}

json_object* json_dict::parse(const char* a, int length) {
	json_dict* b = new json_dict();
	json_object* key = nullptr;
	json_object* value = nullptr;
	std::string c = "";
	int val = 0;
	int i = 1;
	while(*(a+i) != '}') {
		char tmp = *(a+i);
		if(tmp == ':') {
			val = 1;
		}
		else if(tmp == ',') {
			val = 0;
			b->put(key, value);
		}
		else if(tmp == '\'') {
			if(val) {
				value = String::parse((a+i), 0, '\'');
				i = _index;
				continue;
			}
			else {
				key = String::parse((a+i), 0, '\'');
				i = _index;
				continue;
			}
		}
		else if(tmp == '\"') {
			if(val) {
				value = String::parse((a+i), 0, '\"');
				i = _index;
				continue;
			}
			else {
				key = String::parse((a+i), 0, '\"');
				i = _index;
				continue;
			}
		}
		else if(tmp == '[') {
			if(val) {
				value = json_list::parse((a+i), 0);
				i = _index;
				continue;
			}
			else {
				key = json_list::parse((a+i), 0);
				i = _index;
				continue;
			}
		}
		else if(tmp == '{') {
			if(val) {
				value = parse((a+i), 0);
				i = _index;
				continue;
			}
			else {
				key = parse((a+i), 0);
				i = _index;
				continue;
			}
		}
		else if(tmp>='0' && tmp<='9') {
			if(val) {
				value = Integer::parse((a+_index), 0);
				i = _index;
				continue;
			}
			else {
				key = Integer::parse((a+_index), 0);
					i = _index;
				continue;
			}
		}
		i++;
	}
	b->put(key, value);
	return b;
}

json_object* json_dict::operator[](json_object* key) const {
        for(auto it = v.begin(); it != v.end(); it++) {
                if ((*it).first == key) {
                        return (*it).second;
                }
        }

}

json_object* json_dict::operator[](const std::string& key) const {
	
}

json_object* json_dict::operator[](int key) const {

}

json_object::_type json_dict::type() {
	return DICT;
}

std::string json_dict::to_string() {
	std::string a = "{";
	for(auto it = v.begin(); it != v.end(); it++) {
		a += (*it).first->to_string();
		a += ": ";
		a += (*it).second->to_string();
		if(it+1 != v.end()) {
			a += ", ";
		}
        }
	a += "}";
	return a;
}
