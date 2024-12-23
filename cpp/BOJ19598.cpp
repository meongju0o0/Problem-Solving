#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n;
    cin >> n;

    vector<pair<int, int>> meetings(n);
    for (size_t i = 0; i < n; ++i) {
        int start_time, end_time;
        cin >> start_time >> end_time;
        meetings[i] = {start_time, end_time};
    }

    ranges::sort(meetings.begin(), meetings.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first != b.first ? a.first < b.first : a.second < b.second;
    });

    priority_queue<int, vector<int>, greater<>> classrooms;

    classrooms.push(meetings[0].second);

    for (size_t i = 1; i < n; ++i) {
        if (meetings[i].first >= classrooms.top()) {
            classrooms.pop();
        }
        classrooms.push(meetings[i].second);
    }

    printf("%ld", classrooms.size());

    return 0;
}
