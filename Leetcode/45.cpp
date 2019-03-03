
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) { return 0; }
        int steps = 0;
        int start = 0;
        int end = 0;
        int maxEnd = 0;
        do {
            ++steps;
            end = maxEnd;
            for (int i = start; i <= end; ++i) {
                maxEnd = max(maxEnd, i + nums[i]);
            }
            start = end + 1;
        } while (maxEnd < nums.size() - 1 && end != maxEnd);
        if (end == maxEnd) {return -1;}
        else {
            return steps;
        }
    }
};


class Solution1 {
public:
    int jump(vector<int>& nums) {
        if (0 == nums.size()) {
            return 0;
        }
        int PIVOT = nums.size();
        vector<int> dp = vector<int>(nums.size(), PIVOT);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (PIVOT == dp[i]) {
                continue;
            }
            else {
                for (int j = i + 1; j <= min(i + nums[i], (int)nums.size() - 1); ++j) {
                    dp[j] = min(dp[j], dp[i] + 1);
                }
            }
        }
        if (PIVOT == dp[nums.size() - 1]) {
            return -1;
        }
        else {
            return dp[nums.size() - 1];
        }
    }
};

int main() {

    return 0;
}