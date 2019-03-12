
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
const int INF = 0x3f3f3f3f;
const int N = 1003;
int parent[N], costs[N], used[N];
float values[N];

vector<int> nodes[N];

int main() {
    int n,r;
    while(scanf("%d %d", &n, &r), 0 != n || 0 != r) {
        memset(used, 0, sizeof(used));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &costs[i]); 
            nodes[i] = vector<int>();
            nodes[i].push_back(i);
            values[i] = costs[i];
        }
        int u,v;
        for (int i = 1; i < n; ++i) {
            scanf("%d %d", &u, &v);
            parent[v] = u;
        }
        parent[r] = r;
        int count = n;
        // printf("%d %d\n", n, r);
        while(--count) {
            // printf("cnt = %d\n", count);
            float maxVal = 0;
            int maxIndex = -1;
            for (int i = 1; i <= n; ++i) {
                if (i != r && !used[i] && values[i] > maxVal) {
                    maxVal = values[i];
                    maxIndex = i;
                }
            }
            // printf("%d, %d\n", maxIndex, maxVal);
            int par = parent[maxIndex];
            while(par != r && used[par]) { par = parent[par]; }
            used[maxIndex] = true;
            int oriNumNodes = nodes[par].size();
            for (int i = 0; i < nodes[maxIndex].size(); ++i) {
                nodes[par].push_back(nodes[maxIndex][i]);
            }
            values[par] = (oriNumNodes * values[par] + 
                nodes[maxIndex].size() * values[maxIndex]) / nodes[par].size();
        }
        // for (int i = 1; i <= n; ++i) {
        //     printf("%.2f ", values[i]);
        // }
        // printf("\n");

        int ans = 0;
        for (int i = 0; i < nodes[r].size(); ++i) {
            // printf("%d ", nodes[r][i]);
            ans += (i + 1) * costs[nodes[r][i]];
        }
        // printf("\n");
        printf("%d\n", ans);
        for (int i = 0; i <= n; ++i) {
            nodes[i].clear();
        }
    }
    return 0;
}