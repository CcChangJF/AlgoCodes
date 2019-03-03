
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

using namespace std;

const int N = 50003;
int par[N * 3];
int height[N * 3];


class UnionFind{
    vector<int> par;
    vector<int> rank;
public:
    UnionFind(int n) {
        par = vector<int>(n, 0);
        rank = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }

    int find(int p) {
        if (p == par[p]) { return p; }
        else { return par[p] = find(par[p]); }
    }

    bool same(int n1, int n2) {
        n1 = find(n1);
        n2 = find(n2);
        return (n1 == n2);
    }

    void unite(int n1, int n2) {
        n1 = find(n1);
        n2 = find(n2);
        if (n1 == n2) { return; }
        if (rank[n1] < rank[n2]) {
            par[n1] = n2;
        }
        else {
            par[n2] = n1;
            if (rank[n1] == rank[n2]) { ++rank[n1];}
        }
        return;
    }
};

int main() {
    cin.sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    UnionFind uf = UnionFind(3 * n);
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        int d,x,y;
        // cin >> d >> x >> y;
        scanf("%d%d%d", &d, &x, &y);
        --x;
        --y;
        if (x < 0 || y < 0 || x >= n || y >= n) {
            ++ans;
            continue;
        }
        if (1 == d) {
            if (uf.same(x, y + n) || uf.same(x, y + 2 * n)) {
                ++ans;
                continue;
            }
            else {
                uf.unite(x, y);
                uf.unite(x + n, y + n);
                uf.unite(x + 2 * n, y + 2 * n);
            }
        }
        else {  
            if (uf.same(x, y) || uf.same(x, y + 2 * n)) {
                ++ans;
                continue;
            }
            else {
                uf.unite(x, y + n);
                uf.unite(x + n, y + 2 * n);
                uf.unite(x + 2 * n, y);
            }
        }
    }
    cout << ans << endl;
    return 0;
}