
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;

class Solution {
    set<int> prime(int n) {
        set<int> res = set<int>();
        for(int i=2;i<=n;i++) {
            while(n!=i)
            {
              if(n%i==0)
              {
                res.insert(i);
                n=n/i;
              }
              else
                break;
            }
        }
        return res;
    }
public:
    int largestComponentSize(vector<int>& A) {
        if (A.size() <= 1) { return A.size();}
        vector<set<int> > cnt;
        vector<vector<int> > res;
        for (int i = 0; i < A.size(); ++i) {
            int find = -1;
            for (int j = cnt.size() - 1; j >= 0; --j) {
                for (set<int>::iterator iter = cnt[j].begin(); iter != cnt[j].end(); ++iter) {
                    if (A[i] % (*iter) == 0) {
                        set<int> temp = prime(A[i]);
                        cnt.insert(temp.begin(), temp.end());
                        if (-1 != find) {
                            set<int> last = cnt[find];
                            cnt[j].insert(last.begin(), last.end());
                            cnt.erase(cnt.begin() + find);
                            vector<int> lastv = res[find];
                            res[j].insert(lastv.begin(), lastv.end());
                            res.erase(last.begin() + find);
                        }
                        find = j;
                        break;
                    }
                }
            }
            if (-1 == find) {
                vector<int> nv = vector<int>({A[i]});
                res.push_back(nv);
                set<int> ns = prime(A[i]);
                cnt.push_back(ns);
            }
        }
        int maxRes = 0;
        for (int i = 0; i < res.size(); ++i) {
            maxRes = max(maxRes, (int)res[i].size());
        }
        return maxRes;
    }
};

int main() {
    Solution s;
    vector<int> test = vector<int>({0});
    s.largestComponentSize(test);
    return 0;
}