#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int main() {
    unsigned num_commands;
    int item;

    priority_queue<pair<unsigned, bool>> heap; //true: positive, false: negative
    scanf("%u", &num_commands);
    for (unsigned i = 0; i < num_commands; i++) {
        scanf("%u", &item);
        if (item == 0) {
            if (heap.size() == 0) {
                printf("0\n");
            }
            else {
                pair<unsigned, bool> result = heap.top();
                heap.pop();
                if(result.second) {
                    printf("%d\n", -(result.first - INT_MAX));
                }
                else {
                    printf("%d\n", (result.first - (INT_MAX + 1)));
                }
            }
        }
        else {
            if (item > 0) {
                heap.emplace(INT_MAX-item, true);
            }
            else {
                heap.emplace((INT_MAX+1)+item, false);
            }
        }
    }
    return 0;
}