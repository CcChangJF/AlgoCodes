#include <bits/stdc++.h>

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, long long> pil;
typedef pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

const int maxV = 10003;

struct Edge{
    int to,cost;
};

vector<Edge> graph[maxV];
int dis[maxV];

int V,E;
void dijsktra(int s) {
    for (int i = 0; i < V; ++i) { dis[i] = INF; }
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(dis[s], s));
    while(!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        int v = cur.second;
        if (dis[v] < cur.first) { continue; }
        for (int i = 0; i < graph[v].size(); ++i) {
            Edge e = graph[v][i];
            if (dis[e.to] > dis[v] + e.cost) {
                dis[e.to] = dis[v] + e.cost;
                pq.push(pii(dis[e.to], e.to));
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);



    return 0;
}