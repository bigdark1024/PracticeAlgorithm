#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct com_str {
    bool operator()(const string& x, const string& y) const {
        return x > y; // key值降序
    }
};

int main() {
    map<int, string> map1;
    map1[1] = "abs";
    map1[6] = "def";
    map1[3] = "acv";
    map1[2] = "bar";
    for (auto it = map1.begin(); it!= map1.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    map<string, int, com_str> map2;
    map2["abs"] = 1;
    map2.insert(make_pair("def", 6));
    map2.insert(make_pair("acv", 3));
    map2.insert(make_pair("bar", 2));
    for (auto it = map2.begin(); it != map2.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    map<int, vector<int>> map3;
    map3[1] = vector<int> (5, 6);
    map3.insert(make_pair(6, vector<int> {6, 5}));
    map3.insert(make_pair(3, vector<int> {7, 4}));
    map3[2] = vector<int> {0, 2, 10, 7};

    vector<pair<int, vector<int>>> vec(map3.begin(), map3.end());
    std::sort(vec.begin(), vec.end(), [](pair<int, vector<int>>& x, pair<int, vector<int>>& y) -> bool {
        if (x.second.size() == y.second.size()) {
            return x.first < y.first;
        }

        return x.second.size() < y.second.size();
    });
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << "KEY:" << it->first << endl;
        if (it->first == 1) {
            vec.erase(it);
            break;
        }
        for (auto vec_it = it->second.begin(); vec_it != it->second.end(); vec_it++) {
            cout << *vec_it << " ";
        }
        cout << endl;
    }

    cout << map3.count(2) << endl;


    return 0;
}
