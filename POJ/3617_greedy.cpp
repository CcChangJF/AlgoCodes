
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
#include <bitset>
#include <cmath>
#include <climits>

typedef long long ll;

using namespace std;

const int N = 2005;
char chars[N];
char ans[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> chars[i];
    }
    int start = 0;
    int end = n - 1;
    int cnt = 0;
    while(start <= end) {
        bool left = true;
        for (int i = 0; start + i <= end - i; ++i) {
            if (chars[start + i] < chars[end - i]) { break;}
            else if (chars[start + i] > chars[end - i]) {
                left = false;
                break;
            }
        }
        if (left) { ans[cnt++] = chars[start++]; }
        else { ans[cnt++] = chars[end--]; }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i];
        if (0 == (i + 1) % 80) {
            cout << endl;
        }
    }
    cout << endl;
    return 0;
}