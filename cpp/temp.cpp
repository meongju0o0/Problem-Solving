#include <bits/stdc++.h>

using namespace std;

int main(){
    // 1 ~ 1000 정점이 하나의 사이클을
    // 1001 ~ 2000 정점이 하나의 사이클을 이룸
    cout << 2000 << ' ' << 2000 <<'\n';
    for (int i=0; i<1000; i++) cout << 1+i << ' ' << 1+((i+1) % 1000) << '\n';
    for (int i=0; i<1000; i++) cout << 1001+i << ' ' << 1001+((i+1) % 1000) << '\n';
}
