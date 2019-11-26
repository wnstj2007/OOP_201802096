//
// Created by 김혁진 on 2019/11/19.
//

#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

#include <string>
#include <iostream>

class json_object {
protected:
    enum _type {
        // Structure type
        DICT,
        LIST,

        // Data type
        INT,
        STRING
    };

    static int _index;
    static json_object* parse(const char *, int length);
public:
    static json_object* parse(const std::string&);
    virtual _type type() = 0;
    virtual std::string to_string() = 0;
};

#endif // JSON_OBJECT_H
