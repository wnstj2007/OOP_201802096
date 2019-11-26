#include "json_list.h"
#include "json_dict.h"
#include "data/String.h"
#include "data/Integer.h"

json_list::json_list() {
	
}

json_object* json_list::parse(const char* a, int length) {
	json_list* list = new json_list();
	int i = 1;
	while(*(a+i)!=']') {
		char t = *(a+i);
		if(t == '\'') {
			list->v.push_back(String::parse((a+i), 0 , '\''));
			i = _index;
                        continue;
		}
		else if(t == '\"') {
			list->v.push_back(String::parse((a+i), 0 , '\"'));
			i = _index;
                        continue;
		}
		else if(t == '[') {
			list->v.push_back(parse((a+i), 0));
			i = _index;
                        continue;
		}
		else if(t == '{') {
			list->v.push_back(json_dict::parse((a+i), 0));
			i = _index;
                        continue;
		}
		else if(t>='0' && t<='9') {
			list->v.push_back(Integer::parse((a+i), 0));
			i = _index;
                        continue;
		}
		i++;
	}
	return list;
}

json_object* json_list::operator[](int key) const {
	return this->v[key];
}

json_object::_type json_list::type() {
	return LIST;
}

std::string json_list::to_string() {
	std::string a = "";
	for(auto it = v.begin(); it != v.end(); it++) {
		a += (*it)->to_string();
        }
	return a;
}
