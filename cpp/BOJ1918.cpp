#include <iostream>
#include <string>
#include <stack>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    const set<char> operators = {'*', '/', '+', '-', '(', ')'};
    stack<char> operator_stack;

    for(const char& ch: str) {
        if(!operators.contains(ch)) {
            cout << ch;
        }
        else if(ch == '(') {
            operator_stack.push(ch);
        }
        else if(ch == ')') {
            while(!operator_stack.empty()) {
                if(operator_stack.top() == '(') {
                    operator_stack.pop();
                    break;
                }
                else {
                    cout << operator_stack.top();
                    operator_stack.pop();
                }
            }
        }
        else if(ch == '*' || ch == '/') {
            while(!operator_stack.empty()) {
                if(operator_stack.top() == '*' || operator_stack.top() == '/') {
                    cout << operator_stack.top();
                    operator_stack.pop();
                }
                else {
                    break;
                }
            }
            operator_stack.push(ch);
        }
        else if(ch == '+' || ch == '-') {
            if(!operator_stack.empty() && operator_stack.top() == '(') {
                operator_stack.push(ch);
            }
            else {
                while(!operator_stack.empty()) {
                    if(operator_stack.top() != '(' && operator_stack.top() != ')') {
                        cout << operator_stack.top();
                    }
                    else if(operator_stack.top() == '(' || operator_stack.top() == ')') {
                        break;
                    }
                    operator_stack.pop();
                }
                operator_stack.push(ch);
            }
        }
    }
    while(!operator_stack.empty()) {
        if(operator_stack.top() != '(' && operator_stack.top() != ')') {
            cout << operator_stack.top();
        }
        operator_stack.pop();
    }

    return 0;
}