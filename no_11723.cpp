#include <iostream>
#include <string>
#include <array>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int item;
    int num_commands;
    string command;
    unordered_map<string, int> command_map = {
            {"add", 1}, {"remove", 2}, {"check", 3}, {"toggle", 4}, {"all", 5}, {"empty", 6}
    };

    array<bool, 21> hash_set;
    hash_set.fill(false);

    cin >> num_commands;
    cin.ignore();

    for(int i = 0; i < num_commands; i++) {
        cin >> command;
        switch(command_map[command]) {
            case 1: //add
                cin >> item;
                hash_set[item] = true;
                break;
            case 2: //remove
                cin >> item;
                hash_set[item] = false;
                break;
            case 3: //check
                cin >> item;
                cout << hash_set[item] << '\n';
                break;
            case 4: //toggle
                cin >> item;
                hash_set[item] = !hash_set[item];
                break;
            case 5: //all
                hash_set.fill(true);
                break;
            case 6: //empty
                hash_set.fill(false);
                break;
        }
        cin.ignore();
    }

    return 0;
}
