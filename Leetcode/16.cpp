#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (2 >= nums.size()) {return target;}
        sort(nums.begin(), nums.end());
        int bestSum = nums[0] + nums[1] + nums[2];
        int curSum = 0;
        for (int first = 0; first < nums.size() - 2; ++first) {
            if (0 != first && nums[first] == nums[first - 1]) {
                continue;
            }
            int start = first + 1;
            int end = nums.size() - 1;
            while (start < end) {
                int sum = nums[start] + nums[end] + nums[first];
                if (sum == target) {
                    return target;
                }
                else if (sum < target) {
                    if (abs(bestSum - target) > abs(sum - target)) {
                        bestSum = sum;
                    }
                    ++start;
                }
                else {
                    if (abs(bestSum - target) > abs(sum - target)) {
                        bestSum = sum;
                    }
                    --end;
                }
            }
        }
        return bestSum;
    }
};

int main() {

    return 0;
}