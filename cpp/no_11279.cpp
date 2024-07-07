#include <iostream>
#include <queue>

using namespace std;

int main() {
    unsigned num_commands;
    unsigned item;

    priority_queue<unsigned> heap;
    scanf("%u", &num_commands);
    for (unsigned i = 0; i < num_commands; i++) {
        scanf("%u", &item);
        if (item == 0) {
            if (heap.size() == 0) {
                printf("0\n");
            }
            else {
                printf("%u\n", heap.top());
                heap.pop();
            }
        }
        else {
            heap.push(item);
        }
    }
    return 0;
}