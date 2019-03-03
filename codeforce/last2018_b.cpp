#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 1005;

// struct Node{
//     int x;
//     int y;
//     int cnt;
//     bool operator<(const Node &that) const {
//         if (y == that.y) {
//             return y < that.y;
//         }
//         else {
//             return x < that.x;
//         }
//     }
// };

int x[N];
int y[N];
int a[N];
int b[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    // unordered_map<int, int> ans1;
    // unordered_map<int, int> xy;
    // unordered_map<int, int> ans2;
    map<pair<int, int>, int> ans;
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ++ans[make_pair(x[i] + a[j], y[i] + b[j])];
        }
    }
    int ansx = 0;
    int ansy = 0;
    for (auto p : ans) {
        if (n == p.second) {
            ansx = p.first.first;
            ansy = p.first.second;
            break;
        }
    }
    cout << ansx << " " << ansy << endl;
    // for (auto p : ans2) {
    //     cout << p.first << " " << p.second << endl;
    // }
    return 0;
}