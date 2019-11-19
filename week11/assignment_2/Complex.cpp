//
// Created by 김혁진 on 2019/11/11.
//

#include "Complex.h"
#include "Integer.h"
#include "Float.h"

Complex::Complex() {
    /**
     * std 네임 스페이스의 make_pair를 통해 pair 객체 생성 가능
     * real과 imag에 각각 0을 대입
     */
	value = std::make_pair(0,0);
}

Complex::Complex(float _val1, float _val2) {
    /**
     * std 네임 스페이스의 make_pair를 통해 pair 객체 생성 가능
     * real과 imag에 각각 _val1, _val2를 대입
     */
	value = std::make_pair(_val1, _val2);
}

Number *Complex::add(Number * num) {
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
     * 계산한 Complex 값을 return 하기 전 캐스팅된 num을 delete
     *
     * Float 값이 들어온 경우 입력으로 들어온 num 값을 Float 타입으로 캐스팅 후 값 사용
     * 계산한 Complex 값을 return 하기 전 캐스팅된 num을 delete
     *
     * Complex 값이 들어온 경우 입력으로 들어온 num 값을 Complex 타입으로 캐스팅 후 값 사용
     * (새로운 객체를 생성해 return 할 경우 this와 Complex로 캐스팅한 num 값을 모두 delete)
     * (this나 캐스팅한 num을 return 할 경우 return 하지 않는 값을 delete)
     *
     * 타입 검사는 num->types()를 이용 (if check, else if check)
     * enum 값이 어떠한 type에도 속하지 않으면 nullptr 반환
     *
     * enum 값은 INTEGER, FLOAT, COMPLEX 과 같이 접근 가능
     */
    if (num->types() == INTEGER) {
        Integer *other = dynamic_cast<Integer*>(num);
        this->set_val(other->val()+real(), imag());
        delete(other);
        return this;
    } else if (num->types() == FLOAT) {
        Float *other = dynamic_cast<Float*>(num);
        this->set_val(other->val()+real(), imag());
        delete(this);
        return this;
    } else if (num->types() == COMPLEX) {
        Complex *other = dynamic_cast<Complex*>(num);
        other->set_val(other->real()+this->real(), other->imag()+this->imag());
        delete(this);
        return other;
    } else {
        return nullptr;
    }

    return nullptr;
}

Number *Complex::sub(Number * num) {
    /**
     * this->value - num->value // num의 value는 private 이므로 호출 불가능 (단순 개념 설명임)
     * this의 값과 parameter로 들어온 num의 value를 빼는 함수
     */
    if (num->types() == INTEGER) {
        Integer *other = dynamic_cast<Integer*>(num);
        this->set_val(real()-other->val(), imag());
        delete(other);
        return this;
    } else if (num->types() == FLOAT) {
        Float *other = dynamic_cast<Float*>(num);
        this->set_val(real()-other->val(), imag());
        delete(other);
        return this;
    } else if (num->types() == COMPLEX) {
        Complex *other = dynamic_cast<Complex*>(num);
        other->set_val(this->real()-other->real(), this->imag()-other->imag());
        delete(this);
        return other;
    } else {
        return nullptr;
    }

    return nullptr;
}

Number *Complex::mul(Number * num) {
    /**
     * this->value * num->value // num의 value는 private 이므로 호출 불가능 (단순 개념 설명임)
     * this의 값과 parameter로 들어온 num의 value를 곱하는 함수
     *
     * num의 타입이 COMPLEX인 경우
     * this->실수부 * other->실수부 - this->허수부 * other->허수부가 실수에 들어가고
     * this->실수부 * other->허수부 + this->허수부 * other->실수부가 허수에 들어가게 됨
     */
    if (num->types() == INTEGER) {
        Integer *other = dynamic_cast<Integer*>(num);
        this->set_val(other->val()*real(), imag());
        delete(other);
        return this;
    } else if (num->types() == FLOAT) {
        Float *other = dynamic_cast<Float*>(num);
        this->set_val(other->val()*real(), imag());
        delete(other);
        return this;
    } else if (num->types() == COMPLEX) {
        Complex *other = dynamic_cast<Complex*>(num);
        other->set_val(this->real()*other->real(), this->imag()*other->imag());
        delete(this);
        return other;
    } else {
        return nullptr;
    }

    return nullptr;
}

Number *Complex::div(Number * num) {
    /**
     * this->value / num->value // num의 value는 private 이므로 호출 불가능 (단순 개념 설명임)
     * this의 값과 parameter로 들어온 num의 value를 나누는 함수
     *
     * Type이 COMPLEX 경우 nullptr 를 반환한다.
     * 이 때는 this와 num 모두 delete하지 않는다.
     */
    if (num->types() == INTEGER) {
        Integer *other = dynamic_cast<Integer*>(num);
        this->set_val(real()/other->val(), imag());
        delete(other);
        return this;
    } else if (num->types() == FLOAT) {
        Float *other = dynamic_cast<Float*>(num);
        this->set_val(real()/other->val(), imag());
        delete(other);
        return this;
    } else if (num->types() == COMPLEX) {
        return nullptr;
    } else {
        return nullptr;
    }

    return nullptr;
}

double Complex::real() const {
    /**
     * pair의 접근은 std::get<>으로 할 수 있는데 0이면 첫번째, 1이면 두번째 값을 접근
     * 이를 이용해 real 값은 0번째 imag값은 1번째에 있으므로 real, imag값을 얻을 수 있음
     */
    return std::get<0>(value);
}
double Complex::imag() const {
    /**
     * pair의 접근은 std::get<>으로 할 수 있는데 0이면 첫번째, 1이면 두번째 값을 접근
     * 이를 이용해 real 값은 0번째 imag값은 1번째에 있으므로 real, imag값을 얻을 수 있음
     */
    return std::get<1>(value); // real() 을 참고하여 구현할 것!
}

void Complex::set_val(std::pair<double, double> val) {
    /**
     * 입력받은 val을 value값으로 저장하는 함수 (value의 setter)
     */
	value = val;
}

void Complex::set_val(double real, double imag) {
    /**
     * 입력받은 real, imag을 value값으로 저장하는 함수 (value의 setter)
     *
     * 이 때 make_pair함수를 이용
     */
	value = std::make_pair(real,imag);
}

std::pair<double, double> Complex::val() const {
    /**
     * value 값을 return하는 함수 (value의 getter)
     */
    return value; // 구현한거 아님..
}

Number::type Complex::types() const {
    /**
     * Number의 enum 값인 COMPLEX 값을 반환
     */
    return COMPLEX; // 구현한거 아님..!
}

std::string Complex::to_string() const {
    /**
     * Complex 값의 string
     */
    std::string real = std::to_string(std::get<0>(value));
    std::string imag;
    if (std::get<1>(value) >= 0) {
        imag = std::to_string(std::get<1>(value));
        std::string op(" + ");
        real.append(op);
    } else {
        imag = std::to_string(-std::get<1>(value));
        std::string op(" - ");
        real.append(op);
    }
    real.append(imag);
    std::string im("i");
    real.append(im);
    return real;
}
