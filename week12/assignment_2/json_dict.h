//
// Created by 김혁진 on 2019/11/19.
//

#ifndef JSON_DICT_H
#define JSON_DICT_H

#include "json_object.h"
#include <vector>

class json_dict : public json_object {
private:
    std::vector<std::pair<json_object*, json_object*> > v;
    void put(json_object* key, json_object* val);
    int find(json_object* key);
public:
    json_dict();
    static json_object* parse(const char *, int length);
    json_object* operator[](json_object* key) const;
    json_object* operator[](const std::string& key) const;
    json_object* operator[](int key) const;

    _type type();
    std::string to_string();
};


#endif // JSON_DICT_H
