//
// Created by 김혁진 on 2019/11/19.
//

#ifndef STRING_H
#define STRING_H

#include "Object.h"

class String : public Object<std::string> {
private:
    std::string _val;
public:
    explicit String(const std::string& str);

    std::string val();
    void set_val(const std::string& str);

    static json_object* parse(const char *, int length, char base);

    _type type();
    std::string to_string();
};


#endif //STRING_H
