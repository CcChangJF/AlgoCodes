
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
int total[N], counts[N];
float values[N];

int sequence[N];
int rights[N];

int main() {
    int n,r;
    while(scanf("%d %d", &n, &r), 0 != n || 0 != r) {
        memset(used, 0, sizeof(used));
        memset(sequence, 0, sizeof(sequence));
        memset(rights, 0, sizeof(rights));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &costs[i]); 
            sequence[i] = i;
            values[i] = costs[i];
            total[i] = costs[i];
            counts[i] = 1;
            rights[i] = i;
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
            // printf("%d, %.2f\n", maxIndex, maxVal);
            int par = parent[maxIndex];
            while(par != r && used[par]) { par = parent[par]; }
            used[maxIndex] = true;
            sequence[rights[par]] = maxIndex;
            rights[par] = rights[maxIndex];
            total[par] += total[maxIndex];
            counts[par] += counts[maxIndex];
            values[par] = (float)total[par] / counts[par];
            
        }
        // int t = r;
        // for (int i = 1; i <= n; ++i) {
        //     printf("%d ", t);
        //     t = sequence[t];
        // }
        // printf("\n");

        int ans = 0;
        int p = r;
        for (int i = 1; i <= n; ++i) {
            // printf("%d ", nodes[r][i]);
            ans += i * costs[p];
            p = sequence[p];
        }
        // printf("\n");
        printf("%d\n", ans);
        // for (int i = 0; i <= n; ++i) {
        //     nodes[i].clear();
        // }
    }
    return 0;
}