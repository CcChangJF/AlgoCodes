
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



int main() {
    int n;
    long long s;
    cin >> n >> s;
    long long total = 0;
    int cur;
    int minLevel = INT_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> cur;
        total += cur;
        minLevel = min(minLevel, cur);
    }
    if (s > total) { cout << -1 << endl;}
    else if (s == total) { cout << 0 << endl;}
    else {
        cout << min((int)((total - s) / n), minLevel) << endl;
    }
    return 0;
}