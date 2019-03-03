#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        if (A.size() <= 1) { return 0;}
        vector<int> m = vector<int>(A.size(), 0);
        vector<int> in = vector<int>(A.size(), 0);
        m[A.size() - 1] = A[A.size() - 1];
        in[A.size() - 1] = A.size() - 1;
        for (int i = A.size() - 2; i >= 0; --i) {
            if (m[i + 1] >= A[i]) {
                m[i] = m[i + 1];
                in[i] = in[i + 1];
            }
            else {
                m[i] = A[i];
                in[i] = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < A.size() - 1; ++i) {
            if (A[i] <= m[i + 1]) {
                int end = A.size() - 1;
                while(end > i + ans && m[end] < A[i]) {
                    --end;
                }
                ans = max(ans, end - i);
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution s;
    vector<int> v;
    v = vector<int>({6,0,8,2,1,5});

    cout << s.maxWidthRamp(v) << endl;

    v = vector<int>({9,8,1,0,1,9,4,0,4,1});

    cout << s.maxWidthRamp(v) << endl;

    v = vector<int>({10,10,10,7,1,6,2,1,7});

    cout << s.maxWidthRamp(v) << endl;


    v = vector<int>({2,2,1});

    cout << s.maxWidthRamp(v) << endl;

    return 0;
}