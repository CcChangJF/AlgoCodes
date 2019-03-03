
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

const int N = 1005;
int axis[N];

int main() {
    int k,n;
    while(cin >> k >> n, k != -1 || n != -1) {
        for (int i = 0; i < n; ++i) {
            cin >> axis[i];
        }
        sort(axis, axis + n);
        int ans = 0;
        int start = 0;
        while (start < n) {
            ++ans;
            int pivot = axis[start++];
            while(start < n && pivot + k >= axis[start]) { ++start; }
            pivot = axis[start - 1];
            while(start < n && pivot + k >= axis[start]) { ++start;}
        }
        cout << ans << endl;
    }
    return 0;
}