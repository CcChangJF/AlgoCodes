#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        int ans = 1;
        int flag = 0;
        //1 >   -1 < 
        int cur = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (A[i] > A[i + 1] && 1 != flag) {
                ++cur;
                if (cur > ans) { ans = cur; }
                flag = 1;
            }
            else if ( A[i] < A[i + 1] && -1 != flag) {
                ++cur;
                if (cur > ans) { ans = cur; }
                flag = -1;
            }
            else {
                cur = 1;
                if (A[i] > A[i + 1]) { ++cur; flag = 1; }
                if (A[i] < A[i + 1]) { ++cur; flag = -1;}

            }
        }
        return ans;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution s;
    vector<int> test;

    test = vector<int>({9,4,2,10,7,8,8,1,9});
    cout << s.maxTurbulenceSize(test) << endl;

    test = vector<int>({4,8,12,16});
    cout << s.maxTurbulenceSize(test) << endl;

    test = vector<int>({9});
    cout << s.maxTurbulenceSize(test) << endl;

    return 0;
}