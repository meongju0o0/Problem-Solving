#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool end_time_compare(vector<int>& time1, vector<int>& time2) {
    if (time1[1] != time2[1]) {
        return time1[1] < time2[1];
    }
    else {
        return time1[0] < time2[0];
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

    int cur_end_time = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(times[i][0] >= cur_end_time) {
            cur_end_time = times[i][1];
            cnt++;
        }
    }

    cout << cnt << endl;

    times.clear();
    times.shrink_to_fit();

    return 0;
}