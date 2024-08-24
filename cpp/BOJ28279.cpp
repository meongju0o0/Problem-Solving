#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> mydeq;

    int num_commands;
    cin >> num_commands;

    while(num_commands--) {
        int command;
        cin >> command;
        if(command == 1) {
            int x;
            cin >> x;
            mydeq.push_front(x);
        }
        else if(command == 2) {
            int x;
            cin >> x;
            mydeq.push_back(x);
        }
        else if(command == 3) {
            if(mydeq.empty()) {
                printf("-1\n");
            }
            else {
                printf("%d\n", mydeq.front());
                mydeq.pop_front();
            }
        }
        else if(command == 4) {
            if(mydeq.empty()) {
                printf("-1\n");
            }
            else {
                printf("%d\n", mydeq.back());
                mydeq.pop_back();
            }
        }
        else if(command == 5) {
            printf("%lu\n", mydeq.size());
        }
        else if(command == 6) {
            printf("%d\n", mydeq.empty());
        }
        else if(command == 7) {
            if(mydeq.empty()) {
                printf("-1\n");
            }
            else {
                printf("%d\n", mydeq.front());
            }
        }
        else if(command == 8) {
            if(mydeq.empty()) {
                printf("-1\n");
            }
            else {
                printf("%d\n", mydeq.back());
            }
        }
    }

    return 0;
}