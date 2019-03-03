
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 1) { return 0;}
        int leftWall = 0;
        int rightWall = 0;
        int totalAmount = 0;
        int start = 0;
        int end = height.size() - 1;
        int level = 0;
        while (start < end) {
            if (leftWall <= rightWall) {
                ++start;
                totalAmount += max(min(leftWall, rightWall) - height[start], 0);
                leftWall = max(leftWall, height[start]);
            }
            else {
                --end;
                totalAmount += max(min(leftWall, rightWall) - height[end], 0);
                rightWall = max(rightWall, height[end]);
            }
        }
        return totalAmount;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 1) { return 0;}
        int totalAmount = 0;
        int start = 0;
        int end = height.size() - 1;
        int level = 0;
        while ( start < end) {
            int low = height[height[start] <= height[end] ? start++ : end--];
            level = max(level, low);
            totalAmount += level - low;
        }
        return totalAmount;
    }
};

int main() {
    Solution s;
    vector<int> nums = vector<int>({0,1,0,2,1,0,1,3,2,1,2,1});
    cout << s.trap(nums) << endl;

    nums = vector<int>({0,1,0,3,1,0,1,2,2,1,2,1});
    cout << s.trap(nums) << endl;

    return 0;
}