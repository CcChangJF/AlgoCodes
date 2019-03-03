
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
public:
    unordered_map<int, int> link;
    unordered_map<int, int> sz;

    int find(int p) {
        while (p != link[p]) {
            p = link[p];
        }
        return p;
    }

    void unionNode(int p, int q) {
        int pf = find(p);
        int qf = find(q);
        if (pf >= qf) {
            link[q] = p;
            sz[p] += sz[q];
        }
        else {
            link[p] = q;
            sz[q] += sz[p];
        }
        return;
    }

    int longestConsecutive(vector<int>& nums) {
        link = unordered_map<int, int>();
        sz = unordered_map<int, int>();
        for (int i = 0; i < nums.size(); ++i) {
            link[nums[i]] = nums[i];
            sz[nums[i]] = 1;
            if (0 != link.count(nums[i] - 1)) {
                unionNode(nums[i], nums[i] - 1);
            }
            if (0 != link.count(nums[i] + 1)) {
                unionNode(nums[i], nums[i] + 1);
            }
        }
        int maxLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (sz[nums[i]] > maxLen) {
                maxLen = sz[nums[i]];
            }
        }
        return maxLen;
    }
};

int main() {
    Solution s;
    vector<int> test;

    test = vector<int>({100, 4, 200, 1, 3, 2});
    cout << s.longestConsecutive(test) << endl;
    return 0;
}