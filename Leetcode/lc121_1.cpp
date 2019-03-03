#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string ans = "";
        if (B <= A) {
            if (2 * B <= A) {
                for (int i = 0; i < (A + B) / 3; ++i) {
                    ans += "aab";
                }
                switch((A + B) % 3) {
                    case 0: break;
                    case 1: ans += "a"; break;
                    case 2: ans += "aa"; break;
                }
            }
            else {
                for (int i = 0; i < (A - B); ++i) { ans += "aab"; }
                for (int i = 0; i < (2 * B - A); ++i) { ans += "ab";}
            }
        }
        else {
            if (2 * A <= B) {
                for (int i = 0; i < (A + B) / 3; ++i) {
                    ans += "bba";
                }
                switch((A + B) % 3) {
                    case 0: break;
                    case 1: ans += "b"; break;
                    case 2: ans += "bb"; break;
                }
            }
            else {
                for (int i = 0; i < (B - A); ++i) { ans += "bba"; }
                for (int i = 0; i < (2 * A - B); ++i) { ans += "ba";}
            }
        }
        return ans;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution s;
    cout << s.strWithout3a3b(4,1) << endl;

    for (int i = 5; i < 9; ++i) {
        for (int j = i / 2; j < 2 * i; ++j) {
            cout << i << " " << j << " : " << s.strWithout3a3b(i, j) << endl;
        }
    }


    return 0;
}