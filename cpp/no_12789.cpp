#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> temp_line;

    int k = 1;
    while(n--) {
        int id;
        cin >> id;

        while(!temp_line.empty() && temp_line.top() == k) {
            temp_line.pop();
            k++;
        }

        if(id == k) {
            k++;
        }
        else {
            temp_line.push(id);
        }
    }

    while(!temp_line.empty()) {
        int id = temp_line.top();
        temp_line.pop();

        if(id == k) {
            k++;
        }
        else {
            break;
        }
    }

    printf("%s", (temp_line.empty() ? "Nice" : "Sad"));

    return 0;
}