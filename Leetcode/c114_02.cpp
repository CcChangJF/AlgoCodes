
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        if (A.size() == 0) { return true;}
        if ( A.size() % 2 == 1) { return false;}
        map<int, int> cnt = map<int, int>();
        for (int i = 0; i < A.size(); ++i) {
            ++cnt[A[i]];
        }
        sort(A.begin(), A.end());
        int total = 0;
        for (int i = 0; i < A.size(); ++i) {

            if (0 != cnt.count(A[i] * 2) && 0 != cnt[A[i]] && 0 != cnt[A[i] * 2]) {
                // cout << A[i] << " " << cnt[A[i]] << " " << cnt[A[i] * 2] << endl;
                --cnt[A[i]];
                --cnt[A[i] * 2];
                total += 2;
            }
        }
        return (total == A.size());
    }
};

int main() {
    Solution s;
    vector<int> test;

    test = vector<int>({3,1,3,6});
    cout << s.canReorderDoubled(test) << endl;

    test = vector<int>({2,1,2,6});
    cout << s.canReorderDoubled(test) << endl;

    test = vector<int>({4,-2,2,-4});
    cout << s.canReorderDoubled(test) << endl;

    test = vector<int>({1,2,4,16,8,4});
    cout << s.canReorderDoubled(test) << endl;
    return 0;
}