
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

const int N = 100003;
int nums[N];

int main() {
    // vector<int> v = vector<int>({1,2,3});
    // cout << lower_bound(v.begin(), v.end(), 2) - v.begin() << endl;
    int t;
    cin >> t;
    while(t--) {
        int n,s;
        // cin >> n >> s;
        scanf("%d%d", &n, &s);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }
        int end = 0;
        int start = 0;
        int sum = 0;
        int res = INF;
        while(end < n) {
            while(end < n && sum < s) {
                sum += nums[end++];
            }
            while(start <= end && sum >= s) {
                res = min(res, end - start);
                sum -= nums[start++];
            }
        }
        if (INF == res) { res = 0; }
        cout << res << endl;
    }
    return 0;
}