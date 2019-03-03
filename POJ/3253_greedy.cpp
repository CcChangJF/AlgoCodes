
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

const int N = 20003;
int nums[N];


int main() {
    int n;
    priority_queue<int, vector<int>, greater<int> > pq;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        pq.push(nums[i]);
    }
    ll ans = 0;
    while(pq.size() > 1) {
        int t = pq.top();
        pq.pop();
        t += pq.top();
        pq.pop();
        pq.push(t);
        ans += t;
    }
    cout << ans << endl;
    return 0;
}