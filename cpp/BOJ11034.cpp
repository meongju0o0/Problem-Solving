#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_num_moves(vector<int>& coordinates) {
    int moves = 0;
    while (true) {
        ranges::sort(coordinates.begin(), coordinates.end());

        const int interval1 = coordinates[1] - coordinates[0];
        const int interval2 = coordinates[2] - coordinates[1];

        if (interval1 <= 1 && interval2 <= 1) {
            break;
        }
        else {
            if (interval1 <= interval2) {
                coordinates[0] = coordinates[1] + 1;
            }
            else if (interval1 > interval2) {
                coordinates[2] = coordinates[1] - 1;
            }
            moves++;
        }
    }
    return moves;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> coordinates(3);

    while (!(cin >> coordinates[0] >> coordinates[1] >> coordinates[2]).fail()) {
        cout << get_num_moves(coordinates) << '\n';
    }

    return 0;
}