#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<long long> solve(int t, int times[][27]) {
        vector<long long> res(3, 0);
        long long multiple = (long long)1 << (t / 26);
        int divident = t % 26;
        res[0] = multiple * times[0][divident];
        res[1] = multiple * times[1][divident];
        res[2] = multiple * times[2][divident];
        return res;
    }
};

int main() {
    Solution s;

    int T=0;
    int times[3][27] = {{1,1,0},
                        {0,0,1,1,1,1,1,1,1,1,0},
                        {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
    cin >> T;
    while(T--) {
        int t = 0;
        cin >> t;
        vector<long long> res = s.solve(t-1, times);
        cout << res[0] << " " << res[1] << " " << res[2] << endl;
    }

    return 0;
}