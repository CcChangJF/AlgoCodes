
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
    memset(deletableNodes, 0, maxN * sizeof(int));
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
        if (!mark[i] && 0 == inDegree[i]) {
            // cout << i << endl;
            mark[i] = true;
            deletedSet.push_back(i);
            for (int j = 0; j < revGraph[i].size(); ++j) {
                if (1 == inDegree[revGraph[i][j]]) {
                    ++deletableNodes[i];
                }
            }
        }

        // cout << "print: " << i << " : " << deletableNodes[i] << endl;
    }

    while(remained > 0) {

        if (1 == remained) {
            ans0[total] = 1;
            ans1[total] = deletedSet[0];
            ans2[total] = -1;
            ++total;
            break;
        }

        int bestFirst = -1;
        int bestSec = -1;
        int maxRe = 0;
        for (int first = 0; first < deletedSet.size(); ++first) {
            if (deletableNodes[deletedSet[first]] > maxRe) {
                maxRe = deletableNodes[deletedSet[first]];
                bestFirst = first;
                bestSec = -1;
            }
            for (int sec = first + 1; sec < deletedSet.size(); ++sec) {
                int minEdgeVIndex = (outDegree[first] > outDegree[sec]) ? sec : first;
                int minEdgeV = deletedSet[minEdgeVIndex];
                // cout << "minEdgeV: " << minEdgeV << endl; 
                int mutual = 0;
                for (int j = 0; j < revGraph[minEdgeV].size(); ++j) {
                    int node = revGraph[minEdgeV][j];
                    if (2 == inDegree[node] && hasEdge(graph, node, deletedSet[first], deletedSet[sec])) {
                        ++mutual;
                    }
                }

                int curRe = deletableNodes[deletedSet[first]] + deletableNodes[deletedSet[sec]] + mutual;
                if (maxRe <= curRe) {
                    maxRe = curRe;
                    bestFirst = first;
                    bestSec = sec;
                }
            }
        }
        //cout << bestFirst << " " << bestSec << " " << maxRe << endl;

        int firstV = deletedSet[bestFirst];
        ans1[total] = deletedSet[bestFirst];
        int secV = -1;
        ans2[total] = secV;
        ans0[total] = 1;
        if (-1 != bestSec) {
            secV = deletedSet[bestSec];
            ans0[total] = 2;
            ans2[total] = deletedSet[bestSec];
            deletedSet.erase(deletedSet.begin() + bestSec);
        }
        deletedSet.erase(deletedSet.begin() + bestFirst);

        int curSize = deletedSet.size();
        for (int j = 0; j < revGraph[firstV].size(); ++j) {
            int curNode = revGraph[firstV][j];
            --inDegree[curNode];
            if (0 == inDegree[curNode]) {
                mark[curNode] = true;
                deletedSet.push_back(curNode);
            }
        }
        if (-1 != bestSec) {
            for (int j = 0; j < revGraph[secV].size(); ++j) {
                int curNode = revGraph[secV][j];
                --inDegree[curNode];
                if (0 == inDegree[curNode]) {
                    mark[curNode] = true;
                    deletedSet.push_back(curNode);
                }
            }         
        }
        // cout << "deleted: ";
        // for (int i = 0; i < deletedSet.size(); ++i) {
        //     cout << deletedSet[i] << " ";
        // }
        // cout << endl;
        for (int j = curSize; j < deletedSet.size(); ++j) {
            int node = deletedSet[j];
            for (int k = 0; k < revGraph[node].size(); ++k) {
                // if (node == 2) {
                //     cout <<"k: " << k << " " << revGraph[node][k] << " " << inDegree[revGraph[node][k]] << endl;
                // }
                if (1 == inDegree[revGraph[node][k]]) {
                    ++deletableNodes[node];
                }
            }
        }
        remained -= ans0[total];
        ++total;
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