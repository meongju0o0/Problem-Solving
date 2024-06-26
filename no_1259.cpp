#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

bool is_palindrome(stack<char>& stack, queue<char>& queue) {
    while(!stack.empty()) {
        char last_num = stack.top();
        char first_num = queue.front();
        stack.pop();
        queue.pop();
        if (last_num != first_num) {
            return false;
        }
    }
    return true;
}

int main() {
    while(true) {
        string number;
        cin >> number;

        stack<char> stack;
        queue<char> queue;

        if (number == "0") {
            break;
        }
        for (const char& ch : number) {
            stack.push(ch);
            queue.push(ch);
        }
        if (is_palindrome(stack, queue)) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
    return 0;
}