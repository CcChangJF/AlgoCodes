
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    int searchStart(vector<int> &nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        if (start < nums.size() && target == nums[start]) {
            return start;
        }
        else {
            return -1;
        }
    }

    int searchEnd(vector<int> &nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        if (end >= 0 && target == nums[end]) {
            return end;
        }
        else {
            return -1;
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = vector<int>(2,0);
        res[0] = -1;
        res[1] = -1;
        if (0 == nums.size()) {
            return res;
        }
        res[0] = searchStart(nums, target);
        res[1] = searchEnd(nums, target);
        return res;
    }
};

int main() {

    return 0;
}