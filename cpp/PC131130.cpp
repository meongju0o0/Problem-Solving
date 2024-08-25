#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc (const int& a, const int& b) {
    return a > b;
}

int get_start_pos(const vector<bool>& visited) {
    for(int i = 0; i < visited.size(); i++) {
        if(!visited[i]) {
            return i;
        }
    }
    return -1;
}

int solution(vector<int> cards) {
    int answer = 0;
    
    vector<bool> visited(cards.size(), false);
    vector<int> box_cnts;
    
    while(true) {
        int cur_pos = get_start_pos(visited);
        if(cur_pos == -1) {
            break;
        }
        else {
            int box_cnt = 0;
            while(!visited[cur_pos]) {
                visited[cur_pos] = true;
                cur_pos = cards[cur_pos] - 1;
                box_cnt++;
            }
            box_cnts.push_back(box_cnt);
        }
    }
    
    if(box_cnts.size() < 2) {
        answer = 0;
    }
    else {
        sort(box_cnts.begin(), box_cnts.end(), desc);
        answer = box_cnts[0] * box_cnts[1];   
    }
    
    return answer;
}