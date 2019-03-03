
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

int cnt[30];

int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(cnt, 0, sizeof(cnt));
        string cur;
        cin >> cur;
        for (int i = 0; i < cur.length(); ++i) {
            ++cnt[cur[i] - 'a'];
        }
        int chars = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i]) { ++chars;}
        }
        if (1 == chars) {
            cout << -1 << endl;
        }
        else {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < cnt[i]; ++j) {
                    cout << (char)(i + 'a');
                }
            }
            cout << endl;
        }
    }
    return 0;
}