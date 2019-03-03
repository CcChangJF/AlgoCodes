
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
        while (index < n && count < k) {
            if (0 != nums[index] - totalSub) {
                cout << nums[index] << endl;
            }
            totalSub += nums[index];
            ++index;
            ++count;
        }
    }

    return 0;
}