
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
const int N = 2503;

pii spfs[N];
pii bottles[N];
pii aux[N];

bool mycmp(pii &a, pii &b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    else {
        return a.first <= b.first;
    }
}

int main() {
    int n,l;
    scanf("%d %d", &n, &l);
    int low, high;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &low, &high);
        spfs[i].first = low;
        spfs[i].second = high;
    }
    for (int i = 0; i < l; ++i) {
        scanf("%d %d", &low, &high);
        aux[i].first = low;
        aux[i].second = high;
    }
    sort(spfs, spfs + n, mycmp);
    sort(aux, aux + l);

    bottles[0] = aux[0];
    int cnt = 1;
    for (int i = 1; i < l; ++i) {
        if (aux[i].first == aux[i - 1].first) {
            bottles[cnt - 1].second += aux[i].second;
        }
        else {
            bottles[cnt++] = aux[i];
        }
    }
    int ans = 0;
    int p = 0;
    int q = 0;
    priority_queue<int, vector<int>, greater<int> > cows;
    while(p < cnt) {
        if (0 >= bottles[p].second) { ++p; continue;}
        for (; q < n; ++q) {
            if (spfs[q].first <= bottles[p].first && bottles[p].first <= spfs[q].second) {
                cows.push(spfs[q].second);
            }
            if (spfs[q].first > bottles[p].first) { break; }
        }

        while(!cows.empty() && bottles[p].second > 0 && cows.top() >= bottles[p].first) {
            ++ans;
            cows.pop();
            --bottles[p].second;
        }
        ++p;
        while(!cows.empty() && cows.top() < bottles[p].first) { cows.pop(); }
    }
    cout << ans << endl;
    return 0;
}