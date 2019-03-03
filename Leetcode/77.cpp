//Description



//TestCase
/*

*/

//Wrong case
/*

*/


/*
how to solve


*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    void search(vector<vector<int> > &res, vector<int> &cur, int index, int k, int n) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }
        else {
            for(int i = index + 1; i <= n; ++i) {
                cur.push_back(i);
                search(res, cur, i, k, n);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> cur;
        search(res, cur, 0, k, n);
        return res;
    }
};

int main() {
    Solution s;


    return 0;
}