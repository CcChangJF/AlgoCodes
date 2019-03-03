#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int maxV = 100003;
const int maxE = 100003;
const int INF = 0x3f3f3f3f;

struct Edge{
        int from;
        int to;
        int cost;
};
int E,V;
Edge edges[maxE];
int dis[maxV];
bool shortestPath(int s) {
    for (int i = 0; i < V; ++i) {
        dis[i] = INF;
    }
    dis[s] = 0;
    bool update = true;
    for (int v = 0; v < V; ++v) {
        update = false;
        for (int i = 0; i < E; ++i) {
            Edge e = edges[i];
            if (INF != dis[e.from] && dis[e.to] > dis[e.from] + e.cost) {
                dis[e.to] = dis[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) { break; }
    }
    return !update; 
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    E = 3;
    V = 3;
    edges[0] = {0, 1, 1};
    edges[1] = {1, 2, 1};
    edges[2] = {2, 0, -2};
    bool neg = shortestPath(0);
    for (int i = 0; i < V; ++i) {
        cout << dis[i] << " ";
    }
    cout << endl;
    cout << "neg circle: " << neg << endl;

    return 0;
}