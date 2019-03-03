
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string.h>


using namespace std;


struct Station{
    int start;
    int end;
    int numbers;
    int profit;
    bool operator<(const Station &that) const {
        if (start == that.start) {
            return end < that.end;
        }
        else {
            return start < that.start;
        }
    }
};

Station orders[23];
int stopCaps[8];
int totalProfitAfter[23];
int maxPro;
int c,m,e;

/*
0 2 1
1 2 7
1 3 5
2 3 10
sum     max
0       0
2       2

*/
void dfs(int cur, int sum){
    maxPro = max(sum, maxPro);
    //cout << "dfs: " << cur << ", " << sum << ", " << maxPro << ", " << totalProfitAfter[cur] << endl;
    for (int i = cur; i < e; ++i) {
        if (sum + totalProfitAfter[i] <= maxPro) { return; }
        int j = orders[i].start;
        for (; j < orders[i].end; ++j) {
            if (stopCaps[j] + orders[i].numbers > c) {
                break;
            }
            stopCaps[j] += orders[i].numbers;
        }
        if (j == orders[i].end) {
            dfs(i + 1, sum + orders[i].profit);
        }

        j = j - 1;
        for (; j >= orders[i].start; --j) {
            stopCaps[j] -= orders[i].numbers;
        }
    }
    return;
}

int maxProfit() {
    maxPro = 0;
    sort(orders, orders + e);
    // for (int i = 0; i < e; ++i) {
    //     cout << orders[i].start << " " << orders[i].end << " " << orders[i].numbers << " " << orders[i].profit << endl;
    // }
    totalProfitAfter[e - 1] = orders[e - 1].profit;
    for (int i = e - 2; i >= 0; --i) {
        totalProfitAfter[i] = totalProfitAfter[i + 1] + orders[i].profit;
    }
    // cout << "total: ";
    // for (int i = 0; i < e; ++i) {
    //     cout << totalProfitAfter[i] << " ";
    // }
    // cout << endl;
    dfs(0, 0);
    return maxPro;
}

int main() {
    cin >> c >> m >> e;
    while (0 != c || 0 != m || 0 != e) {
        memset(orders, 0, 23 * sizeof(Station));
        memset(stopCaps, 0, 8 * sizeof(int));
        memset(totalProfitAfter, 0, 23 * sizeof(int));
        for (int i = 0; i < e; ++i) {
            cin >> orders[i].start >> orders[i].end >> orders[i].numbers;
            orders[i].profit = orders[i].numbers * (orders[i].end - orders[i].start);
        }
        cout << maxProfit() << endl;
        cin >> c >> m >> e;
    }
    return 0;
}