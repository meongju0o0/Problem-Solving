#include <iostream>
#include <vector>
#include <map>

struct cmp {
    bool operator() (const int& a, const int& b) const {
        return a > b;
    }
};

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_cases;
    cin >> num_cases;

    for(int i = 0; i < num_cases; i++) {
        int n, m;
        cin >> n >> m;

        map<int, int, cmp> importance_cnt;
        vector<tuple<int, int>> printer_queue;
        for(int j = 0; j < n; j++) {
            int importance;
            cin >> importance;
            importance_cnt[importance]++;
            printer_queue.emplace_back(j, importance);
        }

        int cnt = 0;
        for(pair<const int, int>& doc_importance: importance_cnt) {
            while(doc_importance.second != 0) {
                int cur_document = get<0>(printer_queue[0]);
                int cur_importance = get<1>(printer_queue[0]);
                if(cur_importance != doc_importance.first) {
                    printer_queue.emplace_back(cur_document, cur_importance);
                    printer_queue.erase(printer_queue.begin());
                }
                else {
                    cnt++;
                    printer_queue.erase(printer_queue.begin());
                    doc_importance.second--;
                    if(cur_document == m) {
                        cout << cnt << endl;
                    }
                }
            }
        }
    }

    return 0;
}