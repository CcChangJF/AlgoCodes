#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int p = 0;
        while(p < A.size() && p < K && A[p] < 0) {
            A[p] = -A[p];
            ++p;
        }
        int total = 0;
        // cout << K << "," << p << ", " << (K - p & 1) << endl;
        for (int i = 0; i < A.size(); ++i) {total += A[i];}
        if ((K - p & 1) == 0) { return total; }
        else { 
            // cout << "total: " << total << ", " << A[p] << endl;
            int m = A[p];
            if (p > 0) { m = min(m, A[p - 1]);}
            return total - (m << 1);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution s;
    vector<int> test;

    test = vector<int>({4,2,3});
    cout << s.largestSumAfterKNegations(test, 1) << endl;

    test = vector<int>({3,-1,0,2});
    cout << s.largestSumAfterKNegations(test, 3) << endl;

    test = vector<int>({2,-3,-1,5,-4});
    cout << s.largestSumAfterKNegations(test, 4) << endl;

    return 0;
}