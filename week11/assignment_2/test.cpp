//
// Created by 김혁진 on 2019/11/12.
//

#include "Integer.h"
#include "Float.h"
#include "Complex.h"
#include <iostream>

int main() {
    // 이번 과제는 테스트 코드를 주지 않습니다.
    // 직접 코드를 작성해보면서 확인해보세요
    {
        Number *a = new Integer(13);
        Number *result = a->add(new Float(3.14));

        std::cout << dynamic_cast<Float *>(result)->val() << std::endl; // 16.14
    }
    {
        Number *a = new Integer(3);
        Number *result = a
		->add(new Float(3.14))
		->sub(new Integer(1))
       		->mul(new Integer(7))
		->sub(new Complex(11, 5));

        std::cout << dynamic_cast<Complex *>(result)->to_string() << std::endl; // 24.980000 - 5.000000i
    }
    // 테스트 코드 작성해보고 확인해보세요
    // 채점은 임의의 테스트코드로 진행할 예정입니다

    return 0;
}
