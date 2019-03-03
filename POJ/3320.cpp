
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

const int N = 1000003;
int nums[N];

int main() {
    int n;
    // cin >> n;
    scanf("%d", &n);
    map<int, int> cnt;
    set<int> ideas;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
        ideas.insert(nums[i]);
    }
    int all = ideas.size();
    int end = 0;
    int start = 0;
    int count = 0;
    int res = INF;
    while(end < n) {
        while(end < n && count < all) {
            if (0 == cnt[nums[end]]) { ++count; }
            ++cnt[nums[end++]];
        }
        while(start <= end && count == all) {
            res = min(res, end - start);
            if (--cnt[nums[start++]] == 0) {
                --count;
            }
        }
    }
    cout << res << endl;
    return 0;
}