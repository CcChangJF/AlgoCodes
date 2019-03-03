
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool hasNextPermutation(vector<int> &nums) {
        int firstDes = -1;
        int swapPos = -1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                firstDes = i;
                break;
            }
        }
        if (-1 == firstDes) {
            return false;
        }
        for (int i = nums.size() - 1; i > firstDes; --i) {
            if (nums[i] > nums[firstDes]) {
                swapPos = i;
                break;
            }
        }
        swap(nums[firstDes], nums[swapPos]);
        reverse(nums.begin() + firstDes + 1, nums.end());
        return true;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res = vector<vector<int> >();
        if (0 == nums.size()) { return res;}
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        }while (hasNextPermutation(nums));
        return res;
    }
};

int main() {

    return 0;
}