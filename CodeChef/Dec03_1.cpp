
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

const int maxN = 1000001;
int inDegree[maxN];
int outDegree[maxN];
bool mark[maxN];
int ans0[maxN];
int ans1[maxN];
int ans2[maxN];
int deletableNodes[maxN];

bool hasEdge(vector<vector<int> > &graph, int node, int first, int sec) {
    if (2 != inDegree[node]) { return false;}
    bool hasFirst = false;
    bool hasSec = false;
    for (int i = 0; i < graph[node].size(); ++i) {
        if (!hasFirst && first == graph[node][i]) {
            hasFirst = true;
        }
        else if (!hasSec && sec == graph[node][i]) {
            hasSec = true;
        }
        if (hasFirst && hasSec) {
            return true;
        }
    }
    return false;
}

int newEmptyNode(vector<vector<int> > &revGraph, int v) {
    int cnt = 0;
    for (int i = 0; i < revGraph[v].size(); ++i) {
        if (1 == inDegree[revGraph[v][i]]) {
            ++cnt;
        }
    }
    return cnt;
}

int getPairDel(vector<vector<int> > &graph,
    vector<vector<int> > &revGraph, int v, int w) {
    int node = (outDegree[v] > outDegree[w]) ? w : v;
    int cnt = 0;
    for (int i = 0; i < revGraph[node].size(); ++i) {
        if (hasEdge(graph, revGraph[node][i], v, w)) {
            ++cnt;
        }
    }
    return cnt;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int> > graph(n + 1, vector<int>());
    vector<vector<int> > revGraph(n + 1, vector<int>());
    memset(inDegree, 0, maxN * sizeof(int));
    memset(outDegree, 0, maxN * sizeof(int));
    memset(mark, 0, maxN * sizeof(bool));
    memset(ans0, 0, maxN * sizeof(int));
    memset(ans1, 0, maxN * sizeof(int));
    memset(ans2, 0, maxN * sizeof(int));
 //   memset(deletableNodes, 0, maxN * sizeof(int));
    int u, v;
    for (int i = 0; i < e; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        revGraph[v].push_back(u);
        ++inDegree[u];
        ++outDegree[v];
    }
    int remained = n;
    int total = 0;
    vector<int> deletedSet = vector<int>();
    for (int i = 1; i <= n; ++i) {
        if (0 == inDegree[i]) {
            // cout << i << endl;
            // mark[i] = true;
            deletedSet.push_back(i);
            // for (int j = 0; j < revGraph[i].size(); ++j) {
            //     if (1 == inDegree[revGraph[i][j]]) {
            //         ++deletableNodes[i];
            //     }
            // }
        }
    }

    while(remained > 0) {
        int firstIndex = -1;
        int secIndex = -1;
        // cout << "size: " << deletedSet.size();
        if (1 == deletedSet.size()) {
            firstIndex = 0;
        }
        else if (3 == deletedSet.size()) {
            vector<int> addNode = vector<int>(3, 0);
            for (int i = 0; i < addNode.size(); ++i) {
                addNode[i] = newEmptyNode(revGraph, deletedSet[i]);
            }

            int maxDel = 0;
            for (int i = 0; i < 3; ++i) {
                for (int j = i + 1; j < 3; ++j) {
                    int curDel = getPairDel(
                        graph, revGraph, deletedSet[i], deletedSet[j]);
                    curDel = curDel + addNode[i] + addNode[j];
                    if (maxDel <= curDel) {
                        firstIndex = i;
                        secIndex = j;
                        maxDel = curDel;
                    }
                }
            }
        }
        else {
            firstIndex = 0;
            secIndex = 1;
        }

        int first = deletedSet[firstIndex];
        int sec = -1;
        ans0[total] = 1;
        ans1[total] = first;
        ans2[total] = -1;

        if (-1 != secIndex) {
            ans0[total] = 2;
            sec = deletedSet[secIndex];
            ans2[total] = sec;
            deletedSet.erase(deletedSet.begin() + secIndex);
        }
        deletedSet.erase(deletedSet.begin() + firstIndex);
        // cout << ": " << firstIndex << ", " << first << ". " << secIndex << ", " << sec << endl;
        remained -= ans0[total];
        ++total;
        for (int j = 0; j < revGraph[first].size(); ++j) {
            int node = revGraph[first][j];
            --inDegree[node];
            if (0 == inDegree[node]) {
                deletedSet.push_back(node);
            }
        }
        if (-1 != secIndex) {
            for (int j = 0; j < revGraph[sec].size(); ++j) {
                int node = revGraph[sec][j];
                --inDegree[node];
                if (0 == inDegree[node]) {
                    deletedSet.push_back(node);
                }
            }
        }
    }

    cout << total << endl;
    for (int i = 0; i < total; ++i) {
        cout << ans0[i] << " " << ans1[i];
        if (-1 != ans2[i]) {
            cout << " " << ans2[i];
        }
        cout << endl;
    }
    return 0;
}