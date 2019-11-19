//
// Created by 김혁진 on 2019/11/11.
//

#include "Float.h"
#include "Integer.h"
#include "Complex.h"

double Float::parse_string(std::string str) {
    /**
     * 문자열을 float로 변환하는 함수
     */
    double result = atof(str.c_str());
    return result;
}

Float::Float() {
    /**
     * value를 0으로 저장
     */
	value = 0;
}

Float::Float(double _value) {
    /**
     * 입력받은 double 값(_value)을 value에 저장
     */
	value = _value;
}

Float::Float(const std::string& str) {
    /**
     * Float 의 parse_string 함수를 통해 입력받은 문자열 값을 float 값으로 value에 저장
     */
	value = this->parse_string(str);
}

Number *Float::add(Number * num) {
    /**
     * this->value + num->value // num의 value는 private 이므로 호출 불가능 (단순 개념 설명)
     * this의 값과 parameter로 들어온 num의 value를 더하는 함수
     *
     * 아래의 사항은 add, sub, mul, div 모두 해당됨
     *
     * this와 num 중 더 수의 범위가 큰 타입으로 return 한다.
     * 계산에 사용된 값은 delete한다.
     *
     * 수의 범위
     * INTEGER -> FLOAT -> COMPLEX
     *
     * Integer 값이 들어온 경우 입력으로 들어온 num 값을 Integer 타입으로 캐스팅 후 값 사용
     * 계산한 Float 값을 return 하기 전 num을 delete
     *
     * Float 값이 들어온 경우 입력으로 들어온 num 값을 Float 타입으로 캐스팅 후 값 사용
     * (새로운 객체를 생성해 return 할 경우 this와 Float로 캐스팅한 num 값을 모두 delete)
     * (this나 캐스팅한 num을 return 할 경우 return 하지 않는 값을 delete)
     *
     * Complex 값이 들어온 경우 입력으로 들어온 num 값을 Complex 타입으로 캐스팅 후 값 사용
     * Complex는 값을 return 하기 전 this를 delete 함 (새로운 객체를 생성해 return 하거나 parameter 의 값을 set_val 후 return)
     *
     * 타입 검사는 num->types()를 이용 (if check, else if check)
     * enum 값이 어떠한 type에도 속하지 않으면 nullptr 반환
     *
     * enum 값은 INTEGER, FLOAT, COMPLEX 과 같이 접근 가능
     */
    if (num->types() == INTEGER) {
        Integer *other = dynamic_cast<Integer*>(num);
        this->set_val(other->val()+value);
        delete(other);
        return this;
    } else if (num->types() == FLOAT) {
        Float *other = dynamic_cast<Float*>(num);
        other->set_val(other->val()+value);
        delete(this);
        return other;
    } else if (num->types() == COMPLEX) {
        Complex *other = dynamic_cast<Complex*>(num);
        other->set_val(other->real()+value, other->imag());
        delete(this);
        return other;
    } else {
        return nullptr;
    }

    return nullptr;
}

Number *Float::sub(Number * num) {
    /**
     * this->value - num->value // num의 value는 private 이므로 호출 불가능 (단순 개념 설명임)
     * this의 값과 parameter로 들어온 num의 value를 빼는 함수
     */
    if (num->types() == INTEGER) {
        Integer *other = dynamic_cast<Integer*>(num);
        this->set_val(value-other->val());
        delete(other);
        return this;
    } else if (num->types() == FLOAT) {
        Float *other = dynamic_cast<Float*>(num);
        other->set_val(value-other->val());
        delete(this);
        return other;
    } else if (num->types() == COMPLEX) {
        Complex *other = dynamic_cast<Complex*>(num);
        other->set_val(value-other->real(), -other->imag());
        delete(this);
        return other;
    } else {
        return nullptr;
    }

    return nullptr;
}

Number *Float::mul(Number *num) {
    /**
     * this->value * num->value // num의 value는 private 이므로 호출 불가능 (단순 개념 설명임)
     * this의 값과 parameter로 들어온 num의 value를 곱하는 함수
     */
    if (num->types() == INTEGER) {
        Integer *other = dynamic_cast<Integer*>(num);
        this->set_val(other->val()*value);
        delete(other);
        return this;
    } else if (num->types() == FLOAT) {
        Float *other = dynamic_cast<Float*>(num);
        other->set_val(other->val()*value);
        delete(this);
        return other;
    } else if (num->types() == COMPLEX) {
        Complex *other = dynamic_cast<Complex*>(num);
	other->set_val(other->real()*value,other->imag()*value);
	delete(this);
	return other;
    } else {
        return nullptr;
    }

    return nullptr;
}

Number *Float::div(Number *num) {
    /**
     * this->value / num->value // num의 value는 private 이므로 호출 불가능 (단순 개념 설명임)
     * this의 값과 parameter로 들어온 num의 value를 나누는 함수
     *
     * Type이 COMPLEX 경우 nullptr 를 반환한다.
     * 이 때는 this와 num 모두 delete하지 않는다.
     */
    if (num->types() == INTEGER) {
        Integer *other = dynamic_cast<Integer*>(num);
        other->set_val(value/other->val());
        delete(this);
        return other;
    } else if (num->types() == FLOAT) {
        Float *other = dynamic_cast<Float*>(num);
        other->set_val(value/other->val());
        delete(this);
        return other;
    } else if (num->types() == COMPLEX) {
        return nullptr;
    } else {
        return nullptr;
    }

    return nullptr;
}

void Float::set_val(double val) {
    /**
     * 입력받은 val을 value값으로 저장하는 함수 (value의 setter)
     */
	value = val;
}

double Float::val() const {
    /**
     * value 값을 return하는 함수 (value의 getter)
     */
    return value; // 구현한 거 아님;;
}

Number::type Float::types() const {
    /**
     * Number의 enum 값인 FLOAT 값을 반환
     */
    return FLOAT; // 구현한 거 아님!
}

std::string Float::to_string() const {
    /**
     * float 값의 string
     */
    return std::to_string(value);
}
