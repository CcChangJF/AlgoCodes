#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
    void rev(vector<int> &A, int start, int len) {
        for (int i = 0; i < len / 2; ++i) {
            swap(A[i + start], A[start + len - 1 - i]);
        }
        return;
    }
public:
    vector<int> pancakeSort(vector<int>& A) {
        if (1 == A.size()) { return A;}
        vector<int> ans;
        int len = A.size();
        while(len > 0) {
            // cout << len << endl;
            int index = 0;
            while(len != A[index]) { ++index; }
            if (len - 1 == index) { 
                --len;
                continue; 
            }
            if (0 != index) { 
                ans.push_back(index + 1); 
                rev(A, 0, index + 1);
                // for (int k = 0; k < A.size(); ++k) {
                //     cout << A[k] << " ";
                // }
                // cout << endl;
                // getchar();
            }
            rev(A, 0, len);
            // for (int k = 0; k < A.size(); ++k) {
            //         cout << A[k] << " ";
            //     }
            //     cout << endl;
            ans.push_back(len--);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution s;
    vector<int> res;
    vector<int> test;

    test = vector<int>({4,3,2,1});
    res = s.pancakeSort(test);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;


    return 0;
}