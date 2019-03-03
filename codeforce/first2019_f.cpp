#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 100003;
unordered_map<int, int> sets[N];
const int offset = 7000;
int g[50000000];

int gcd(int a, int b) {
    int t = 1;
    while(0 != t) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

//set_intersection( ms1.begin(), ms1.end(), ms2.begin(), ms2.end(), v.begin() );
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    // cin >> n >> q;
    scanf("%d%d", &n, &q);
    map<pii, int> m;
    // vector<multiset<int> > sets(n + 1, multiset<int>());
    for (int i = 0; i < q; ++i) {
        // cout << sets[i].size() << endl;
        int type,x,y,z;
        // cin >> t;
        scanf("%d", &type);
        // cout << "t: " << t << endl;
        if (1 == type || 4 == type) {
            // cin >> x >> y;
            scanf("%d%d", &x, &y);
            // cout << x << "," << y << endl;
            if (1 == type) {
                unordered_map<int, int> t;
                t.insert(make_pair(y, 1));
                sets[x] = t;
            }
            else {
                int ans = 0;
                if (0 != sets[x].count(y)) {
                    ans = sets[x][y];
                }
                printf("%d", ans);
                // cout << (sets[x].count(y) & 1);
            }
        }
        else {
            // cin >> x >> y >> z;
            scanf("%d%d%d", &x, &y, &z);
            if (2 == type) {
                // multiset<int> t(sets[y].size() + sets[z].size());
                // vector<int> t(sets[y].size() + sets[z].size(), 0);
                // set_union(sets[y].begin(), sets[y].end(), sets[z].begin(), sets[z].end(), t.begin());
                // sets[x] = multiset<int>(t.begin(), t.end());
                // multiset<int> t;
                // for (auto f : sets[y]) {
                //     t.insert(f);
                // }
                // for (auto s : sets[z]) {
                //     t.insert(s);
                // }
                unordered_map<int, int> t(sets[y].begin(), sets[y].end());
                for (auto s : sets[z]) {
                    if (0 != t.count(s.first)) {
                        t[s.first] = ((t[s.first] + s.second) & 1);
                    }
                    else {
                        t.insert(s);
                    }
                }
                sets[x] = t;
            }
            else {
                unordered_map<int, int> t;
                // unordered_map<int, bool> cur;
                // int prev = -1;

                for (auto f : sets[y]) {
                    for (auto s : sets[z]) {
                        // pii temp = pii(f.first, s.first);
                        int temp = min(f.first, s.first) * offset + max(f.first, s.first);
                        if (0 != g[temp]) {
                            if (0 != f.second && 0 != s.second) {
                                t[g[temp]] = (t[g[temp]] + 1 & 1);
                            }
                        }
                        else {
                            // cur.insert(gcd(f, s));
                            int curGcd = gcd(f.first, s.first);
                            if (0 == f.second || 0 == s.second) {
                                ;
                            }
                            else {
                                t[curGcd] = (t[curGcd] + 1 & 1);
                            }
                            g[temp] = curGcd;
                            // m[pii(f.first, s.first)] = curGcd;
                        }
                        
                    }
                    // t.insert(cur.begin(), cur.end());
                }
                sets[x] = t;
            }
        }
        // for (int i = 1; i <= n; ++i) {
        //     for (auto m : sets[i]) {
        //         cout << m.first << ":" << m.second << " | ";
        //     }
        //     cout << endl;
        // }
    }
    // cout << endl;
    printf("\n");

    return 0;
}