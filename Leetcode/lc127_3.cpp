#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> cnt = vector<int>(10, 0);
        for (int i = 0; i < A.size(); ++i) {
            ++cnt[A[i]];
            if (A[i] != B[i]) {
                ++cnt[B[i]];
            }
        }
        int val = 0;
        for (int i = 1; i < 7; ++i) {
            if (A.size() == cnt[i]) {
                val = i;
                break;
            }
        }
        if (0 == val) { return -1; }
        int cntA = 0, cntB = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (val == A[i] && val != B[i]) { ++cntA;}
            if (val == B[i] && val != A[i]) { ++cntB;}
        }
        return min(cntA, cntB);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution s;
    vector<int> A;
    vector<int> B;

    A = vector<int>({2,1,2,4,2,2});
    B = vector<int>({5,2,2,2,2,2});
    cout << s.minDominoRotations(A, B) << endl;

    A = vector<int>({3,5,1,2,3});
    B = vector<int>({3,6,3,3,4});
    cout << s.minDominoRotations(A, B) << endl;


    return 0;
}