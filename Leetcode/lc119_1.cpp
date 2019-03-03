#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
    static bool mycmp(vector<int> &a, vector<int> &b) {
        int d1 = (a[0] * a[0] + a[1] * a[1]);
        int d2 = (b[0] * b[0] + b[1] * b[1]);
        return d1 < d2;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), mycmp);
        vector<vector<int> > res(K, vector<int>(2,0));
        for (int i = 0; i < K; ++i) {
            res[i] = points[i];
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);



    return 0;
}