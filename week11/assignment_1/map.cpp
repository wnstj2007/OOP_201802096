#include <map>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int result = 0;
    map<string, int> m;

    // TODO
    // map m에 int값 10, 20, 30, 40을 String key에 맞게 추가하는 코드를 작성하세요.
    // "first": 10
    // "second": 20
    // "third": 30
    // "fourth": 40
	m["first"] = 10;
	m["second"] = 20;
	m["third"] = 30;
	m["fourth"] = 40;

    if (m.size() != 4) {
        cout<<"값을 모두 추가해주세요."<<endl;
        result += 1;
    }

    // TODO
    // m에서 값을 가져오는 코드로 m1~m4를 초기화하여 if문을 통과하게 작성하세요.
    int m1 = m["first"]; // m에서 key값을 넣어 value를 얻어 채우세요
    int m2 = m["second"]; // m에서 key값을 넣어 value를 얻어 채우세요
    int m3 = m["third"]; // m에서 key값을 넣어 value를 얻어 채우세요
    int m4 = m["fourth"]; // m에서 key값을 넣어 value를 얻어 채우세요
    if (m1 != 10 && m2 != 20 && m3 != 30 && m4 != 40) {
        cout<<"값을 순서대로 꺼내주세요."<<endl;
        result += 1;
    }
    // TODO
    // map m에 있는 값 10과 40을 삭제하세요.
    // erase를 통해 key값에 맞는 값을 지울 수 있
	m.erase(m.find("first"));
	m.erase(m.find("fourth"));
    if (m.size() != 2 && (m["first"] == 10 || m["second"] == 40)) {
        cout<<"정해진 값을 삭제해주세요."<<endl;
        result += 1;
    }

    // TODO
    // m에서 key = third, value = 30인 값이  있는지 찾는 코드롤 완성하세요.
    // iterator의 ->first 값은 key, ->second 값은 value
    int check = 0;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
        if (it->first == "third" && it->second == 30) {
            check = 1;
            break;
        }
    }
    if (check == 0) {
        cout<<"값을 찾지 못했습니다."<<endl;
        result += 1;
    }

    if (result == 0) {
        cout<<"map 성공"<<endl;
    } else {
        cout<<"map 실패"<<endl;
    }

    return 0;
}

