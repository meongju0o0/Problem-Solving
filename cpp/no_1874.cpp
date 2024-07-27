#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue<int> myqueue;
    for(int i = 0; i < n; i++) {
        int item;
        cin >> item;
        myqueue.push(item);
    }

    string result;
    bool is_available = true;
    stack<int> mystack;
    int num = 0;
    while(!myqueue.empty()) {
        if(mystack.empty()) {
            mystack.push(++num);
            result += "+\n";
        }
        else {
            if(mystack.top() < myqueue.front()) {
                mystack.push(++num);
                result += "+\n";
            }
            else if(mystack.top() == myqueue.front()) {
                mystack.pop();
                myqueue.pop();
                result += "-\n";
            }
            else if(mystack.top() > myqueue.front()) {
                is_available = false;
                break;
            }
        }
    }

    cout << (is_available ? result : "NO");

    return 0;
}