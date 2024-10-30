#include <iostream>
#include <vector>

using namespace std;

int get_odd_idx(const vector<int>& items) {
    for(int i = 0; i < items.size(); i++) {
        if(items[i] % 2 == 1) {
            return i;
        }
    }
    return -1;
}

bool is_all_zero(const vector<int>& items) {
    for(const int& item: items) {
        if(item != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> items(n);
    for(int& item: items) {
        cin >> item;
    }

    int cnt = 0;
    while(!is_all_zero(items)) {
        int odd_idx = get_odd_idx(items);
        if(odd_idx == -1) {
            for(int& item: items) {
                item /= 2;
            }
        }
        else {
            items[odd_idx] -= 1;
        }
        cnt++;
    }

    printf("%d", cnt);
}