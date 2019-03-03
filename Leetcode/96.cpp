
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (0 == n) { return 0;}
        vector<int> nums = vector<int>(n + 1, 0);
        nums[0] = 1;
        nums[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                nums[i] += nums[j] * nums[i - j - 1];
            }
        }
        return nums[n];
    }
};

int main() {

    return 0;
}