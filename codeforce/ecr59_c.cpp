#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 200003;
int nums[N];



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    // scanf("%d %d", &n, &k);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        // scanf("%d", &nums[i]);
        cin >> nums[i];
    }
    string str;
    cin >> str;
    ll ans = 0;
    int end = 0;
    while(end < n) {
        char pivot = str[end];
        int start = end + 1;
        while(start < n && str[start] == pivot) { ++start; }
        if (end + 1 == start) { ans += nums[end]; }
        else {
            sort(nums + end, nums + start);
            int last = min(k, start - end);
            for (int i = 0; i < last; ++i) {
                ans += nums[start - 1 - i];
            }
        }
        end = start;
    }
    cout << ans << endl;


    return 0;
}