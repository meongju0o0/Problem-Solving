#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K;
    cin >> N >> K;

    array<pair<long long, long long>, 3> meal;
    for (int i=0; i<3; i++){
        cin >> meal[i].first >> meal[i].second;
    }

    long long L, R;
    L = meal[0].first;
    R = meal[0].second;

    if (L > R){
        printf("NO");
        return 0;
    }

    long long totalMeals = 3LL * N;

    for (long long j = 2; j <= totalMeals; j++){
        long long day = (j-1) / 3;
        long long idx = (j-1) % 3;

        long long S = meal[idx].first  + day*1440;
        long long E = meal[idx].second + day*1440;

        long long newL = max(S, L);
        long long newR = min(E, R + K);

        if(newL > newR){
            printf("NO");
            return 0;
        }

        L = newL;
        R = newR;
    }

    printf("YES");
    return 0;
}
