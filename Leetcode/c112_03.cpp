
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>

using namespace std;

class Solution {
    static bool myComparator(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        else {
            return a[0] < b[0];
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        if (stones.size() <= 1) { return 0;}
        sort(stones.begin(), stones.end(), myComparator);
        vector<set<int> > x;
        vector<set<int> > y;
        vector<int> res = vector<int>();
        for (int i = 0; i < stones.size(); ++i) {
            bool flag = false;
            for (int j = 0; j < x.size(); ++j) {
                if (x[j].end() != x[j].find(stones[i][0]) || 
                    y[j].end() != y[j].find(stones[i][1])) {
                    x[j].insert(stones[i][0]);
                    y[j].insert(stones[i][1]);
                    ++res[j];
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                set<int> tx = set<int>({stones[i][0]});
                x.push_back(tx);
                set<int> ty = set<int>({stones[i][1]});
                y.push_back(ty);
                res.push_back(1);
            }
        }
        int maxRes = 0;
        for (int i = 0; i < res.size(); ++i) {
            maxRes = max(maxRes, res[i]);
        }
        return maxRes - 1;
    }
};

int main() {

    return 0;
}