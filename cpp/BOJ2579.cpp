#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> scores(n);
    for (int &score : scores) {
        cin >> score;
    }

    vector<int> accumulated_scores(n);
    if (n >= 1) {
        accumulated_scores[0] = scores[0];
    }
    if (n >= 2) {
        accumulated_scores[1] = scores[0] + scores[1];
    }
    if (n >= 3) {
        accumulated_scores[2] = max(scores[0] + scores[2], scores[1] + scores[2]);
    }

    for (int i = 3; i < n; i++) {
        accumulated_scores[i] = max(accumulated_scores[i - 2] + scores[i],
                                    accumulated_scores[i - 3] + scores[i - 1] + scores[i]);
    }

    cout << accumulated_scores[n - 1] << endl;

    return 0;
}
