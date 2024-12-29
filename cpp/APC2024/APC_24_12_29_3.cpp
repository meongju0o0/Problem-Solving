#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool is_all_p(const string& item) {
    for (char ch: item) {
        if (ch != 'P') {
            return false;
        }
    }
    return true;
}

bool is_all_c(const string& item) {
    for (char ch: item) {
        if (ch != 'C') {
            return false;
        }
    }
    return true;
}

bool is_all_v(const string& item) {
    for (char ch: item) {
        if (ch != 'V') {
            return false;
        }
    }
    return true;
}

bool is_all_s(const string& item) {
    for (char ch: item) {
        if (ch != 'S') {
            return false;
        }
    }
    return true;
}

bool is_all_g(const string& item) {
    for (char ch: item) {
        if (ch != 'G') {
            return false;
        }
    }
    return true;
}

bool is_all_f(const string& item) {
    for (char ch: item) {
        if (ch != 'F') {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> items(n);
    unordered_map<char, long long> costs;

    for (string& item: items) {
        cin >> item;
    }

    long long unit_cost;
    cin >> unit_cost; costs['P'] = unit_cost;
    cin >> unit_cost; costs['C'] = unit_cost;
    cin >> unit_cost; costs['V'] = unit_cost;
    cin >> unit_cost; costs['S'] = unit_cost;
    cin >> unit_cost; costs['G'] = unit_cost;
    cin >> unit_cost; costs['F'] = unit_cost;
    cin >> unit_cost; costs['O'] = unit_cost;

    long long min_cost = 0;
    for (const string& item: items) {
        if (is_all_p(item)) {
            min_cost += static_cast<long long>(item.size()) * min(costs['O'], costs['P']);
        }
        else if (is_all_c(item)) {
            min_cost += static_cast<long long>(item.size()) * min(costs['O'], costs['C']);
        }
        else if (is_all_v(item)) {
            min_cost += static_cast<long long>(item.size()) * min(costs['O'], costs['V']);
        }
        else if (is_all_s(item)) {
            min_cost += static_cast<long long>(item.size()) * min(costs['O'], costs['S']);
        }
        else if (is_all_g(item)) {
            min_cost += static_cast<long long>(item.size()) * min(costs['O'], costs['G']);
        }
        else if (is_all_f(item)) {
            min_cost += static_cast<long long>(item.size()) * min(costs['O'], costs['F']);
        }
        else {
            min_cost += static_cast<long long>(item.size()) * min(costs['O'], costs['O']);
        }
    }

    printf("%lld", min_cost);

    return 0;
}