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
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 3000;
pii spfs[N], aux[N], bottles[N];

int main() {
    int c,l;
    cin >> c >> l;
    for (int i = 0; i < c; ++i) {
        cin >> spfs[i].first >> spfs[i].second;
    }
    for (int i = 0; i < l; ++i) {
        cin >> bottles[i].first >> bottles[i].second;
    }
    sort(spfs, spfs + c);
    sort(bottles, bottles + l);

    /*
        sort the cows and bottles according to the first element(minSPFS)
        for the specific bottle, among all the satisfied cows,
        use greedy algorithm to find the min(maxSPFS) cow
        why?
        case: 
        [(5,9) (6, 10), (1, 12)] [2, 10] // if sort second elem first
        [(5,9) (6, 10), (1, 12)] [10, 11] // if sort first and choose the first staisfied cow
    */
    int b = 0;
    int p = 0;
    int ans = 0;
    priority_queue<int, vector<int>, greater<int> > cows;
    while(b < l) {
        while(p < c && spfs[p].first <= bottles[b].first) {
            cows.push(spfs[p++].second);
        }
        while(!cows.empty() && bottles[b].second > 0) {
            int curMax = cows.top();
            cows.pop();
            if (curMax >= bottles[b].first) {
                ++ans;
                --bottles[b].second;
            }
        }
        ++b;
    }
    cout << ans << endl;
    return 0;
}