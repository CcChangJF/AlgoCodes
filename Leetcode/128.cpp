
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
        if(pf == qf) {return;}
        if (sz[pf] >= sz[qf]) {
            link[qf] = pf;
            sz[pf] += sz[qf];
        }
        else {
            link[pf] = qf;
            sz[qf] += sz[pf];
        }
        return;
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) { return nums.size();}
        link = unordered_map<int, int>();
        sz = unordered_map<int, int>();
        for (int i = 0; i < nums.size(); ++i) {
            if (0 != link.count(nums[i])) {continue;}
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

    test = vector<int>({100, 101, 102, 103, 200, 1, 3, 2});
    cout << s.longestConsecutive(test) << endl;

    test = vector<int>({1, 2, 0, 1});
    cout << s.longestConsecutive(test) << endl;
    return 0;
}