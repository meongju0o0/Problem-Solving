#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    queue<int> q;

    int num_commands;
    cin >> num_commands;
    cin.ignore();

    for (int i = 0; i < num_commands; i++) {
        string command;
        getline(cin, command);
        if (command.find("push") == 0) {
            int data = stoi(command.substr(5));
            q.push(data);
        }
        else if (command.find("pop") == 0) {
            if (q.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if (command.find("size") == 0) {
            cout << q.size() << endl;
        }
        else if (command.find("empty") == 0) {
            cout << q.empty() << endl;
        }
        else if (command.find("front") == 0) {
            if (q.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << q.front() << endl;
            }
        }
        else if (command.find("back") == 0) {
            if (q.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << q.back() << endl;
            }
        }
    }

    return 0;
}