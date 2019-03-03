
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

int cnta[30];
int cntb[30];

int main() {
    string a,b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); ++i) {
        cnta[a[i] - 'a'] = 1;
    }
    bool flag = true;
    for (int i = 0; i < b.length(); ++i) {
        ++cntb[b[i] - 'a'];
        if (0 == cnta[b[i] - 'a']) { 
            flag = false;
        }
    }
    if (flag) {
        int res = 1;
        int cura[30];
        memcpy(cura, cnta, sizeof(cura));
        int indexb = 0;
        int len = b.length();
        int ans = 0;
        while (indexb < len) {
            ++ans;
            for (int k = 0; k < a.length(); ++k) {
                if (b[indexb] == a[k]) {
                    ++indexb;
                }
            }
        }
        cout << ans << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}