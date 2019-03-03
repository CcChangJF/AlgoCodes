
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

const int E = 50003;
const int N = 20003;

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

    int find(int n1) {
        if (n1 == par[n1]) { return n1;}
        else { return par[n1] = find(par[n1]); }
    }

    bool same(int n1, int n2) {
        n1 = find(n1);
        n2 = find(n2);
        return n1 == n2;
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
            if (rank[n1] == rank[n2]) { ++rank[n1]; }
        }
        return; 
    }
};

struct Edge{
    int from,to,cost;
};

bool myCompare(Edge &e1, Edge &e2) {
    return e1.cost < e2.cost;
}

Edge edges[E];

int kruskal(int n, int r) {
    int res = 0;
    sort(edges, edges + r, myCompare);
    UnionFind uf = UnionFind(n);
    for (int i = 0; i < r; ++i) {
        Edge e = edges[i];
        if (!uf.same(e.from, e.to)) {
            uf.unite(e.from, e.to);
            res += e.cost;
        }
    }
    return res;
}

bool mark[N];

int main() {
    int t;
    int offset = 10001;
    cin >> t;
    while(t--) {
        int n,m,r;
        cin >> n >> m >> r;
        memset(mark, 0, sizeof(mark));
        for (int i = 0; i < r; ++i) {
            int u,v,c;
            scanf("%d%d%d", &u, &v, &c);
            Edge e1 = {u, v + n, -c};
            edges[i] = e1;
        }

        cout << (n + m) * 10000 + kruskal(n + m, r) << endl;
    }
    return 0;
}