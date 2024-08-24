#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string expression;
    cin >> expression;

    list<char> operators;
    list<int> numbers;
    string number;
    for(char& ch: expression) {
        if(ch == '+' || ch == '-') {
            operators.push_back(ch);
            numbers.push_back(stoi(number));
            number.clear();
        }
        else {
            number += ch;
        }
    }
    numbers.push_back(stoi(number));
    number.clear();
    number.shrink_to_fit();

    auto operators_it = operators.begin();
    auto numbers_it = numbers.begin();
    while(operators_it != operators.end()) {
        if(*operators_it == '+') {
            *(--numbers_it) = *numbers_it + *(++numbers_it);
            numbers_it = numbers.erase(++numbers_it);
            --numbers_it;
            operators_it = operators.erase(operators_it);
        }
        else {
            ++operators_it;
            ++numbers_it;
        }
    }

    operators_it = operators.begin();
    numbers_it = numbers.begin();
    while(operators_it != operators.end()) {
        if(*operators_it == '-') {
            *(--numbers_it) = *numbers_it - *(++numbers_it);
            numbers_it = numbers.erase(++numbers_it);
            --numbers_it;
            operators_it = operators.erase(operators_it);
        }
        else {
            ++operators_it;
            ++numbers_it;
        }
    }

    cout << *numbers.begin() << endl;

    return 0;
}