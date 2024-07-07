#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;

    unordered_map<string, int> pokemon_name_dict;
    unordered_map<int, string> pokemon_id_dict;
    for(int i = 1; i <= m; i++) {
        string pokemon_name;
        cin >> pokemon_name;
        pokemon_name_dict[pokemon_name] = i;
        pokemon_id_dict[i] = pokemon_name;
    }

    string result;
    for(int i = 1; i <= n; i++) {
        string find;
        cin >> find;
        try {
            int id = stoi(find);
            result += pokemon_id_dict[id] + "\n";
        }
        catch(exception& e) {
            result += to_string(pokemon_name_dict[find]) + "\n";
        }
    }
    cout << result;

    return 0;
}