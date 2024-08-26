#include <iostream>
#include <string>

using namespace std;

bool solution(string str)
{
    int cnt = 0;
    for(const char& ch: str) {
        if(ch == '(') {
            cnt++;
        }
        else if(ch == ')') {
            if(cnt == 0) {
                return false;
            }
            else {
                cnt--;
            }
        }
    }
    
    if(cnt == 0) {
        return true;
    }
    else {
        return false;
    }
}