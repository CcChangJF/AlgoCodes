
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;

class Solution {
public:
    int facs[10];
    Solution() {
        facs[0] = 1;
        facs[1] = 1;
        for (int i = 2; i < 10; ++i) {
            facs[i] = facs[i - 1] * i;
        }
    }
    string getPermutation(int n, int k) {
        if (0 == k) { return "";}
        if (k > facs[n]) {
            k = k % facs[n];
        }
        vector<char> res = vector<char>();
        //set<int> nums = set<int>();
        vector<int> nums = vector<int>();
        for (int i = 0; i < n; ++i) {
            //nums.insert(i + 1);
            nums.push_back(i + 1);
        }
        int index = n;
        while (index > 0) {
            int curDigit = (k - 1) / facs[index - 1];
            //cout << type(nums.end() - nums.begin()) << endl;
            auto curIt = nums.begin() + curDigit;
            res.push_back(*curIt + '0');
            nums.erase(curIt);
            k = k - curDigit * facs[index - 1];
            --index;
        }
        return string(res.begin(), res.end());
    }
};

int main() {
    Solution s;
    cout << s.getPermutation(0, 0) << endl;

    for (int i = 1; i <= 24; ++i) {
        cout << i << " : " << s.getPermutation(4, i) << endl;
    }
    cout << s.getPermutation(4, 25) << endl;
    return 0;
}