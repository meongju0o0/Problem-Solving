#include <iostream>
#include <climits>
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
                printf("%u\n", -(heap.top() - UINT_MAX));
                heap.pop();
            }
        }
        else {
            heap.push(UINT_MAX - item);
        }
    }
    return 0;
}
