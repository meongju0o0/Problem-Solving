#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool end_time_compare(vector<int>& time1, vector<int>& time2) {
    return time1[1] < time2[1];
}

void prune_times(vector<vector<int>>& times, int cur_end_time) {
    for(int i = 0; i < times.size(); i++) {
        if(times[i][0] < cur_end_time) {
            times.erase(times.begin()+i);
            i--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> times(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> times[i][0] >> times[i][1];
    }

    sort(times.begin(), times.end(), end_time_compare);

    int i = 0;
    while(!times.empty()) {
        prune_times(times, times[0][1]);
        i++;
    }

    cout << i << endl;

    times.clear();
    times.shrink_to_fit();

    return 0;
}