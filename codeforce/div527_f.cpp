#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 200005;
vector<int> graph[N];
int n;
int vals[N];
int maxSum = 0;

void dfs(int node, int dep, int &sum, int par) {
    // cout << node << ":" << sum << "\t";
    for (int i = 0; i < graph[node].size(); ++i) {
        int v = graph[node][i];
        if (v != par) {
            sum = sum + vals[v] * (dep + 1);
            if (sum > maxSum) {
                maxSum = sum;
            }
            dfs(v, dep + 1, sum, node);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> vals[i + 1];
    }
    for (int i = 1; i < n; ++i) {
        int u,v;
        cin >> u >> v; 
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum = 0;
        dfs(i, 0, sum, i);
        // cout << maxSum << endl;
    }
    cout << maxSum << endl;
    return 0;
}