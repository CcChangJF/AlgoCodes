
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


// 根据位置来剪枝,如果是往前交换，则只用交换一次，如果是向后交换，则需要交换很多次
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (0 == nums.size()) { return 1;}
        for (int i = 0; i < nums.size(); ++i) {
            while (0 < nums[i] && nums[i] < nums.size() && nums[i] != nums[nums[i] - 1]) {
                if (i > nums[i] - 1) {
                    swap(nums[i], nums[nums[i] - 1]);
                    break;
                }
                else {
                    swap(nums[i], nums[nums[i] - 1]);
                }
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums[nums.size() - 1] + 1;
    }
};

int main() {
    Solution1 s;
    vector<int> test = vector<int>({3,4,2,2,9,5,1,13,-1,-1,-4,3,15,-10,6,10});
    s.firstMissingPositive(test);
    for (int i = 0; i < test.size(); ++i) {
        cout << test[i] << " ";
    }
    cout << endl;
    return 0;
}