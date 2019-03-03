
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;


class Solution{
public:
    static bool compare(vector<int> a, vector<int> b) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }
        return true;
    }

    void dfs(vector<vector<int> > &edges, int capacity, 
        int cur, vector<int> &curCap, int sum, int &maxSum) {
        maxSum = max(sum, maxSum);
        for (int i = cur; i < edges.size(); ++i) {
            bool isExceed = false;
            for (int j = edges[i][0]; j < edges[i][1]; ++j) {
                if (curCap[j] + edges[i][2] > capacity) {
                    isExceed = true;
                    break;
                }
            }
            if (!isExceed) {
                for (int j = edges[i][0]; j < edges[i][1]; ++j) {
                    curCap[j] += edges[i][2];
                }
                dfs(edges, capacity, i + 1, curCap,
                    sum + edges[i][2] * (edges[i][1] - edges[i][0]), maxSum);

                for (int j = edges[i][0]; j < edges[i][1]; ++j) {
                    curCap[j] -= edges[i][2];
                }
            }
        }
        return;
    }
    int maxProfit(int capacity, int stations, 
        vector<vector<int> > &edges) {
        sort(edges.begin(), edges.end(), compare);
        int maxSum = 0;
        vector<int> curCap = vector<int>(stations + 1, 0);
        dfs(edges, capacity, 0, curCap, 0, maxSum);
        return maxSum;
    }
};

int main() {
    Solution s;
    int c, m, e;
    cin >> c >> m >> e;
    while (0 != c || 0 != m || 0 != e) {
        vector<vector<int> > edges(e, vector<int>(3, 0));
        for (int i = 0; i < e; ++i) {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        }

        cout << s.maxProfit(c, m, edges) << endl;
        cin >> c >> m >> e;
    }
    return 0;
}