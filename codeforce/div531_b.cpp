#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 5003;
int nums[N];
int colors[N];
// int cnt[N];
bool visited[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        ++cnt[nums[i]];
    }
    int color = 0;
    int pivot = 0;
    for (auto pair : cnt) {
        if (pair.second > k) {
            cout << "NO" << endl;
            return 0;
        }
        else {
            if (pair.second > color) {
                pivot = pair.first;
                color = pair.second;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        colors[i] = cnt[nums[i]]--;
    }
    if (color != k) {
        for (int i = 0; i < n; ++i) {
            if (pivot == nums[i]) { continue; }
            colors[i] = k--;
            if (color == k) { break; }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << colors[i] << " ";
    }
    cout << endl;

    return 0;
}