#include <iostream>
#include <string>

using namespace std;

bool chk_cand1(const string& str, const string::iterator str_it) {
    // 후보군1이 유효한지 검사하는 함수
    for(ssize_t i = 0; i < 4; i++) {
        if(str_it + i == str.end() || *(str_it + i) == '.') {
            return false;
        }
    }
    return true;
}

bool chk_cand2(const string& str, const string::iterator str_it) {
    // 후보군2가 유효한지 검사하는 함수
    for(ssize_t i = 0; i < 2; i++) {
        if(str_it + i == str.end() || *(str_it + i) == '.') {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    bool is_available = true;
    auto str_it = str.begin();

    while(str_it != str.end()) {
        if(chk_cand1(str, str_it)) {
            // 후보군1(최상의 경우, 'AAAA'로 치환)
            str.replace(str_it, str_it + 4, "AAAA");
            str_it += 4;
        }
        else if(chk_cand2(str, str_it)) {
            // 후보군2(차상의 경우, 'BB'로 치환)
            str.replace(str_it, str_it + 2, "BB");
            str_it += 2;
        }
        else if(*str_it == '.') {
            // 주어진 문자열에서 현재 치환이 불가능한 경우 건너뛰기
            ++str_it;
        }
        else {
            // 위 3가지 조건에 모두 부합하지 않는 경우 치환이 불가능
            // 치환이 불가능하다는 것을 기록하고 반복문 종료
            is_available = false;
            break;
        }
    }

    if(is_available) {
        printf("%s", str.c_str());
    }
    else {
        printf("-1");
    }

    return 0;
}