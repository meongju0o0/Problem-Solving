#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> mystack;

    int commands;
    cin >> commands;

    while(commands--) {
        int command;
        cin >> command;
        if(command == 1) {
            int x;
            cin >> x;
            mystack.push(x);
        }
        else if(command == 2) {
            if(!mystack.empty()) {
                printf("%d\n", mystack.top());
                mystack.pop();
            }
            else {
                printf("-1\n");
            }
        }
        else if(command == 3) {
            printf("%llu\n", mystack.size());
        }
        else if(command == 4) {
            printf("%d\n", mystack.empty());
        }
        else if(command == 5) {
            if(!mystack.empty()) {
                printf("%d\n", mystack.top());
            }
            else {
                printf("-1\n");
            }
        }
    }

    return 0;
}