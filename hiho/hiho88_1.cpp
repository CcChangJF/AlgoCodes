#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int nums[12];
bool mark[12];

void dfs(int d, int n) {
    if (d == n) {
        for (int i = 0; i < n; ++i) {
            cout << nums[i] + 1 << " ";
        }
        cout << endl;
        return;
    }
    // int start = (0 == d) ? 0 : nums[d - 1] + 1;
    for (int i = 0; i < n; ++i) {
        if (!mark[i]) {
            mark[i] = true;
            if (0 == d || (i + nums[d - 1]) % 2 == 1) {
                nums[d] = i;
                dfs(d + 1, n);
            }
            mark[i] = false;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; 
    cin >> n;
    dfs(0, n);


    return 0;
}