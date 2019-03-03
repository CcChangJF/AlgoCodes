
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

const int N = 10003;
pair<int, int> stops[N];
bool myCompare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;
    for (int i = n - 1; i >= 0; --i) {
        int dis,fuel;
        cin >> dis >> fuel;
        stops[i] = make_pair(dis,fuel);
    }
    int l,p;
    cin >> l >> p;
    for (int i = 0; i < n; ++i) {
        stops[i].first = l - stops[i].first;
    }
    stops[n] = make_pair(l, 0);
    sort(stops, stops + n + 1);
    priority_queue<int> pq;
    int curDis = 0;
    int stop = 0;
    int ans = 0;
    while(curDis < l) {
        if (p >= stops[stop].first) {
            pq.push(stops[stop].second);
            curDis = stops[stop].first;
            ++stop;
        }
        else {
            if (pq.empty()) {
                ans = -1;
                break;
            }
            else {
                ++ans;
                p += pq.top();
                pq.pop();
            }
        }
    }
    cout << ans << endl;
    return 0;
}