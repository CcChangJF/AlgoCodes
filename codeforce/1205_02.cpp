
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;


int main() {
    int n,k;
    while (cin >> n >> k) {
        vector<int> nums = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        int totalSub = 0;
        int index = 0;
        int count = 0;
        while (count < k) {
            int curNum = nums[index] - totalSub;
            if (index < n && 0 != curNum) {
                cout << curNum << endl;
                totalSub += curNum;
                ++count;
            }
            else if (index >= n) {
                cout << 0 << endl;
                ++count;
            }
            ++index;
        }
    }

    return 0;
}