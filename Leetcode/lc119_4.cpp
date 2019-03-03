#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int sz = A.size();
        vector<vector<int> > rec(sz, vector<int>(2, 0));
        vector<pair<int, int> > maxvec(sz, make_pair(0, 0));
        vector<pair<int, int> > minvec(sz, make_pair(100001, 100001));
        maxvec[sz - 1].first = A[sz - 1];
        maxvec[sz - 1].second = sz - 1;
        minvec[sz - 1].first = A[sz - 1];
        minvec[sz - 1].second = sz - 1;
        for (int i = sz - 2; i > 0; --i) {
            if (A[i] >= maxvec[i + 1].first) {
                maxvec[i].first = A[i];
                maxvec[i].second = i;
            }
            else {
                maxvec[i] = maxvec[i + 1];
            }

            if (A[i] <= minvec[i + 1].first) {
                minvec[i].first = A[i];
                minvec[i].second = i;
            }
            else {
                minvec[i] = minvec[i + 1];
            }
        }
        rec[0][0] = 1;
        rec[0][1] = 1;
        for () {
            if (0 != res[i][0]) {
                if (0 == i & 1) {
                    int dest = 
                }
                res[]
            }
            if (0 != res[i][1]) {

            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);



    return 0;
}