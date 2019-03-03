
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

using namespace std;

const int maxN = 100002;
bool counts[maxN];
int ans[maxN];
// int sec[maxN];


int main() {
    int n,m;
    cin >> n >> m;
    int a, b;
    memset(counts, 0, sizeof(counts));
    vector<vector<int> > graph(maxN, vector<int>());
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        if (a > b) { swap(a, b); }
        graph[a].push_back(b);
    }
    int start = -1;
    int end = -1;
    for (int i = n - 1; i < n; --i) {
        if (n - i != graph[i].size()) {
            vector<int> temp = vector<int>(n - i + 1, 0);
            for (int j = 0; j < graph[i].size(); ++j) {
                ++temp[graph[i][j] - (n - 1)];
            }
            for (int j = 0; j < n - i; ++j) {
                if (0 == temp[j]) {
                    start = i;
                    end = j + n - i;
                }
            }
            if (-1 != start) { break;}
        }
    }
    if (-1 == start) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        if (1 == start) {
            ans[1] = 1;
            for (int i = 2; i < end; ++i) {
                ans[i] = i + 1;
            }
            ans[end] = 2;
            for (int i = end + 1; i <= n; ++i) {
                ans[i] = i;
            }

            cout << ans[1];
            for (int i = 2; i <= n; ++i) {
                cout << " " << ans[i];
            }
            cout << endl;
            for (int i = 1; i < end; ++i) {
                cout << ans[i] << " ";
            }
            cout << "1";
            for (int i = end + 1; i <= n; ++i) {
                cout << ans[i] << endl;
            }
        }
        else {
            for (int i = 1; i <= start; ++i) {
                ans[i]
            }
        }
        
        cout << "1";
        for (int i = 2; i <= n; ++i) {
            cout << " " << i;
        }
        cout << endl;
        for (int i = 1; i <= pivot; ++i) {
            cout << i << " ";
        }
        cout << pivot;
        for (int i = pivot + 2; i <= n; ++i) {
            cout << " " << i;
        }
        cout << endl;
    }

    return 0;
}