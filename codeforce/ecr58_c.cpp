#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
int res[200005];

struct mycompare{
    bool operator()(const pii &a, const pii &b) const {
        if (a.second < b.first) { return true; }
        // if (a.first > b.second) { return false; }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    scanf("%d", &t);
    vector<multiset<pii, mycompare> > sets;
    // multiset<pii, mycompare> tt;
    vector<vector<int> > ans;
    // tt.insert(pii(3,5));
    // if (tt.end() != tt.find(pii(4,7))){
    //     printf("same\n");
    // }
    // else {
    //     printf("not same\n");
    // }
    while (t--) {
        memset(res, 0, sizeof(res));
        sets.clear();
        ans.clear();
        int n;
        scanf("%d", &n);
        int l,r;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &l, &r);
            bool flag = false;
            int lastIndex = -1;
            for (int j = (int)sets.size() - 1; j >= 0; --j) {
                if (sets[j].end() != sets[j].find(pii(l, r))) {
                    // printf("%d same\n", i);
                    // printf("hello\n");
                    if (!flag) {
                        flag = true;
                        lastIndex = j;
                        sets[j].insert(pii(l, r));
                        ans[j].push_back(i);
                    }
                    else {
                        // printf("%d not same\n", i);
                        sets[j].insert(sets[lastIndex].begin(), sets[lastIndex].end());
                        sets.erase(sets.begin() + lastIndex);
                        // sort(sets[j].begin(), sets[j].end());
                        ans[j].insert(ans[j].begin(), ans[lastIndex].begin(), ans[lastIndex].end());
                        ans.erase(ans.begin() + lastIndex);
                        lastIndex = j;
                    } 
                }
            }
            if (!flag) {
                ans.push_back(vector<int>({i}));
                multiset<pii, mycompare> temp;
                temp.insert(pii(l, r));
                sets.push_back(temp);
            }
            // printf("size: %d\n", sets.size());
            // for (int i = 0; i < sets.size(); ++i) {
            //     printf("i = %d \n", i);
            //     for ( auto c : sets[i]) {
            //         printf("[%d, %d] ", c.first, c.second);
            //     }
            //     printf("\n");
            // }
        }
        // printf("size: %d\n", sets.size());
        if (sets.size() <= 1) {
            printf("-1\n");
        }
        else {
            // for (int i = 0; i < ans[0].size(); ++i) {
            //     printf("%d ", ans[0][i]);
            // }
            // printf("\n");
            // for (int i = 1; i < ans.size(); ++i) {
            //     for (int j = 0; j < ans[i].size(); ++j) {
            //         printf("%d ", ans[i][j]);
            //     }
            // }
            // printf("\n");

            for (int i = 0; i < ans[0].size(); ++i) {
                res[ans[0][i]] = 1;
            }
            for (int i = 0; i < n; ++i) {
                printf("%d ", res[i] + 1);
            }
            printf("\n");
        }
    }


    return 0;
}