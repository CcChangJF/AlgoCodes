
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

const int maxN = 100002;
const int MOD = 1000000007;
long long res[maxN];

int main() {
    string s;
    while(cin >> s) {
        memset(res, 0, sizeof(res));
        int lenS = s.length();
        int b = -1;
        int a = -1;
        int last = -1;
        for (int i = 0; i < lenS; ++i) {
            res[i + 1] = res[i];
            if ('a' == s[i]) {
                res[i + 1] += 1;
                res[i + 1] = (res[i + 1] + res[last + 1]) % MOD;
                a = i;
            }
            else if ('b' == s[i]) {
                b = i;
                last = a;
            }
        }
        cout << res[lenS] << endl;
    }
    
    return 0;
}