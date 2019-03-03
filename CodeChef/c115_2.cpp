
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <unordered_map>

using namespace std;

class Solution {
    class node {
    public:
        node(vector<int> &c) {
            vec = c;
        }
        vector<int> vec;
        bool operator<(const node& t) const {
            for (int i = 0; i < vec.size(); ++i) {
                if (vec[i] != t.vec[i]) {
                    return vec[i] < t.vec[i];
                }
            }
            return false;
        }
    };

public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        map<node, int > s;
        vector<vector<int> > record;
        int start = 0;
        while(s.end() == s.find(cells)) {
            // for (int i = 0; i < 8; ++i) {
            //     cout << cells[i] << " ";
            // }
            // cout << endl;

            s.insert(make_pair(node(cells), start++));
            record.push_back(cells);
            vector<int> tmp = cells;
            for (int i = 1; i < 7; ++i) {
                cells[i] = 1 - (tmp[i - 1] ^ tmp[i + 1]);
            }
            cells[0] = 0;
            cells[7] = 0;
            // for (int i = 0; i < 8; ++i) {
            //     cout << cells[i] << " ";
            // }
            // cout << endl;
        }
        if (N < start) {
            return record[N];
        }
        else {
            int tmp = s[cells];
            // cout << N - tmp << " " << start - tmp << endl;
            return record[(N - tmp) % (start - tmp) + tmp];
        }
    }
};


int main() {
    Solution s;
    vector<int> test = vector<int>({1,0,0,1,0,0,1,0});
    test = s.prisonAfterNDays(test, 1000000000);
    for (int i = 0; i < 8; ++i) {
        cout << test[i] << " ";
    }
    cout << endl;
    return 0;
}