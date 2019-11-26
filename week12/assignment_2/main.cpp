#include <iostream>
#include "json_object.h"
#include "json_list.h"
#include "json_dict.h"
#include "data/String.h"
#include "data/Integer.h"

int main() {
    {
        std::string str("{'a':'b'}");
        json_object *obj = json_object::parse(str);
        std::string tostr = obj->to_string();
        std::cout << tostr << std::endl;
    }

    {
        std::string str("'a'");
        json_object *obj = json_object::parse(str);
        std::string tostr = obj->to_string();
        std::cout << tostr << std::endl;
    }

    {
        std::string str("1");
        json_object *obj = json_object::parse(str);
        std::string tostr = obj->to_string();
        std::cout << tostr << std::endl;
    }

    {
        std::string str("{'a': 'b', 1: 2, 'b': [1,2,'3','abcdefg', '1,2,\"3\",4', [[[]], [[]],],], 'c': {'a': 'b', 'b': [1, 2, 3, 4, 5]}}");
        json_object* obj = json_object::parse(str);
        std::string tostr = obj->to_string();
        std::cout << tostr << std::endl;
        json_object* obj2 = json_object::parse(tostr);
        std::string tostr2 = obj2->to_string();
        std::cout << tostr2 << std::endl;
    }

    {
        std::string str("{1:2, 1:3, 1:4}");
        json_object* obj = json_object::parse(str);
	std::cout << "1:4" << std::endl;
        std::string tostr = obj->to_string();
        std::cout << tostr << std::endl;
    }

    {
        std::string str("{'a': 'b', 'a': 123, 'a': 'This Assignment is easy'}");
        json_object* obj = json_object::parse(str);
        std::string tostr = obj->to_string();
        std::cout << tostr << std::endl;
    }

    {
        std::string str("[1, 2, 3, 4, 5]");
        json_list* obj = dynamic_cast<json_list*>(json_object::parse(str));
	std::cout << "list []" << std::endl;
        for (int i = 0; i < 5; ++i) {
            std::cout << (*obj)[i]->to_string() << ", ";
        }
        std::cout << std::endl;
        std::string tostr = obj->to_string();
        std::cout << tostr << std::endl;
    }

    {
        std::string str("{'a': 'b', 'b': 'c', 'c': [1, 2, 3, [4], '5',], 1:3}");
        json_dict* dict = dynamic_cast<json_dict*>(json_object::parse(str));
        std::string key("a");
        while (true) {
            std::cout << key << ": ";
            json_object* obj = (*dict)[key];
            if (obj == nullptr) {
                break;
            }
            std::cout << obj->to_string() << ", ";
            if (obj->type() == 3) { // STRING
                key = dynamic_cast<String*>(obj)->val();
            } else {
                break;
            }
        }
        json_object* obj = (*dict)[1];
        std::cout << 1 << ": ";
        if (obj->type() == 2) { // INT
            std::cout << dynamic_cast<Integer*>(obj)->val();
        }
        // dict public + []
        std::cout << std::endl;
        std::string tostr = dict->to_string();
        std::cout << tostr << std::endl;
    }

    /**
        result

        {'a': 'b'}
        'a'
        1
        {'a': 'b', 1: 2, 'b': [1, 2, '3', 'abcdefg', '1,2,"3",4', [[[]], [[]]]], 'c': {'a': 'b', 'b': [1, 2, 3, 4, 5]}}
        {'a': 'b', 1: 2, 'b': [1, 2, '3', 'abcdefg', '1,2,"3",4', [[[]], [[]]]], 'c': {'a': 'b', 'b': [1, 2, 3, 4, 5]}}
        {1: 4}
        {'a': 'This Assignment is easy'}
        1, 2, 3, 4, 5,
        [1, 2, 3, 4, 5]
        a: 'b', b: 'c', c: [1, 2, 3, [4], '5'], 1: 3
        {'a': 'b', 'b': 'c', 'c': [1, 2, 3, [4], '5'], 1: 3}
     */
    return 0;
}
