#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 25;
int nums[N];

void dfs(int cur, int n, int m) {
    if (cur == m) {
        for (int i = 0; i < cur; ++i) {
            cout << nums[i] + 1 << " ";
        }
        cout << endl;
    }
    else {
        int start = (0 == cur) ? 0 : nums[cur - 1] + 1;
        for (int i = start; i < n; ++i) {
            nums[cur] = i;
            dfs(cur + 1, n, m);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    dfs(0, n, m);
    return 0;
}