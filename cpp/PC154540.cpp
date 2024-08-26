#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> get_start_pos(vector<vector<int>>& map) {
    for(int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if(map[i][j]) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

vector<int> solution(vector<string> input) {
    vector<int> answer;
    vector<vector<int>> map(input.size() + 2, vector<int>(input[0].size() + 2, 0));
    
    for(int i = 0; i < input.size(); i++) {
        for(int j = 0; j < input[i].size(); j++) {
            if(input[i][j] == 'X') {
                map[i + 1][j + 1] = 0;
            }
            else {
                map[i + 1][j + 1] = input[i][j] - '0';
            }
        }
    }
    
    while(true) {
        pair<int, int> start_vertex = get_start_pos(map);

        if(start_vertex == make_pair(-1, -1)) {
            break;
        }
        else {
            int days = 0;
            queue<pair<int, int>> candidates;

            candidates.push(start_vertex);
            while(!candidates.empty()) {
                int row_pos = candidates.front().first;
                int col_pos = candidates.front().second;
                candidates.pop();
                if(map[row_pos][col_pos]) {
                    days += map[row_pos][col_pos];
                    map[row_pos][col_pos] = 0;
                    if(map[row_pos - 1][col_pos]) {
                        candidates.emplace(row_pos - 1, col_pos);
                    }
                    if(map[row_pos + 1][col_pos]) {
                        candidates.emplace(row_pos + 1, col_pos);
                    }
                    if(map[row_pos][col_pos - 1]) {
                        candidates.emplace(row_pos, col_pos - 1);
                    }
                    if(map[row_pos][col_pos + 1]) {
                        candidates.emplace(row_pos, col_pos + 1);
                    }
                }
            }
            answer.push_back(days);
        }
    }
        
    if(answer.empty()) {
        return vector<int>(1, -1);
    }
    else {
        sort(answer.begin(), answer.end());
        return answer;        
    }
}