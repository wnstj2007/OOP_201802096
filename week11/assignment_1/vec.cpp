#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int result = 0;
    vector<int> v;

    // TODO
    // vector v에 int값 10, 20, 30, 40을 순서대로 추가하는 코드를 작성하세요.
    // vector의 push_back 함수를 이용할 수 있음
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
    if (v.size() != 4) {
        cout<<"값을 모두 추가해주세요."<<endl;
        result += 1;
    }

    // TODO
    // v에서 값을 가져오는 코드로 v1~v4를 초기화하여 if문을 통과하게 작성하세요.
    int v1 = v[0]; // v 값을 통해 채우세요
    int v2 = v[1]; // v 값을 통해 채우세요
    int v3 = v[2]; // v 값을 통해 채우세요
    int v4 = v[3]; // v 값을 통해 채우세요
    if (v1 != 10 && v2 != 20 && v3 != 30 && v4 != 40) {
        cout<<"값을 순서대로 넣어주세요."<<endl;
        result += 1;
    }

    // TODO
    // vector v에 있는 값 10과 40을 삭제하세요.
    // vector의 erase함수를 이용!
	v.erase(v.begin());
	v.erase(--v.end());
    if (v.size() != 2 && (v.front() == 10 || v.back() == 40)) {
        cout<<"정해진 값을 삭제해주세요."<<endl;
        result += 1;
    }

    // TODO
    // find를 사용하여 v에서 30이 몇 번째 인덱스에 있는지 찾는 코드롤 완성하세요.
    int index = 0;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        if (*it == 30) {
            break;
        }
        index += 1;
    }
    if (index != 1) {
        cout<<"인덱스가 다릅니다."<<endl;
        result += 1;
    }

    if (result == 0) {
        cout<<"vector 성공"<<endl;
    } else {
        cout<<"vector 실패"<<endl;
    }

    return 0;
}

