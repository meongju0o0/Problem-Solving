#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    queue<int> persons;
    for(int i = 1; i <= n; i++) {
        persons.push(i);
    }

    printf("<");
    for(int i = 1; !persons.empty(); i++) {
        if (i % k == 0) {
            int cur_person = persons.front();
            persons.pop();
            if(!persons.empty()) {
                printf("%d, ", cur_person);
            }
            else {
                printf("%d>", cur_person);
            }
        }
        else {
            int cur_person = persons.front();
            persons.pop();
            persons.push(cur_person);
        }
    }

    return 0;
}