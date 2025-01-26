#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string given_str;
    cin >> given_str;

    char prev_korea = '\0';
    char prev_yonsei = '\0';
    for (char& ch: given_str) {
        if (prev_korea == '\0' && ch == 'K') {
            prev_korea = 'K';
        } else if (prev_korea == 'K' && ch == 'O') {
            prev_korea = 'O';
        } else if (prev_korea == 'O' && ch == 'R') {
            prev_korea = 'R';
        } else if (prev_korea == 'R' && ch == 'E') {
            prev_korea = 'E';
        } else if (prev_korea == 'E' && ch == 'A') {
            cout << "KOREA" << '\n';
            break;
        }

        if (prev_yonsei == '\0' && ch == 'Y') {
            prev_yonsei = 'Y';
        } else if (prev_yonsei == 'Y' && ch == 'O') {
            prev_yonsei = 'O';
        } else if (prev_yonsei == 'O' && ch == 'N') {
            prev_yonsei = 'N';
        } else if (prev_yonsei == 'N' && ch == 'S') {
            prev_yonsei = 'S';
        } else if (prev_yonsei == 'S' && ch == 'E') {
            prev_yonsei = 'E';
        } else if (prev_yonsei == 'E' && ch == 'I') {
            cout << "YONSEI" << '\n';
            break;
        }
    }

    return 0;
}