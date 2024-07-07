#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, pair<int, int>> saved_counts; //pair.first: cnt_0 결과, pair.second: cnt_1 결과
unordered_map<int, int> saved_results; //fibonacci 결과들을 저장하는 hash table

vector<int> fibonacci(int n, int cnt_0, int cnt_1) {
    if (n == 0) {
        cnt_0++;
        vector<int> result = {0, cnt_0, cnt_1};
        return result;
    }
    else if (n == 1) {
        cnt_1++;
        vector<int> result = {1, cnt_0, cnt_1};
        return result;
    }
    else {
        auto n1 = saved_counts.find(n-1);
        auto n2 = saved_counts.find(n-2);
        auto result1 = saved_results.find(n-1);
        auto result2 = saved_results.find(n-2);
        if ((n1 != saved_counts.end()) && (n2 != saved_counts.end())) {
            int n1_cnt_0 = (n1->second).first;
            int n2_cnt_0 = (n2->second).first;
            int n1_cnt_1 = (n1->second).second;
            int n2_cnt_1 = (n2->second).second;
            cnt_0 = n1_cnt_0 + n2_cnt_0;
            cnt_1 = n1_cnt_1 + n2_cnt_1;
            saved_results[n] = result1->second + result2->second;
            saved_counts[n] = make_pair(cnt_0, cnt_1);
            vector<int> final_result = {saved_results[n], saved_counts[n].first, saved_counts[n].second};
            return final_result;
        }
        else {
            vector<int> result_n1 = fibonacci(n - 1, cnt_0, cnt_1);
            vector<int> result_n2 = fibonacci(n - 2, cnt_0, cnt_1);
            saved_results[n] = result_n1[0] + result_n2[0];
            saved_counts[n] = make_pair(result_n1[1] + result_n2[1], result_n1[2] + result_n2[2]);
            vector<int> final_result = {saved_results[n], saved_counts[n].first, saved_counts[n].second};
            return final_result;
        }
    }
}

int main() {
    int repeat = 0;
    int n = 0;

    scanf("%d", &repeat);
    for (int i = 0; i < repeat; i++) {
        scanf("%d", &n);
        vector<int> result = fibonacci(n, 0 ,0);
        printf("%d %d\n", result[1], result[2]);
    }
    return 0;
}
