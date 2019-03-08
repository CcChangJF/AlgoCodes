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
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums + n);
    int ans = 1;
    for (int i = 0; i < n - 1; ++i) {
        int end = upper_bound(nums, nums + n, nums[i] + 5) - nums;
        // printf("end = %d\n", end);
        if (end - i > ans) {
            ans = end - i;
        }
    }
    printf("%d\n", ans);


    return 0;
}