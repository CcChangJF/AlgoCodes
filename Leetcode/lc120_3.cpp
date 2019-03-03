#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
    int porder(TreeNode *root) {
        if (NULL == root) { return 0; }
        else {
            int left = porder(root -> left);
            int right = porder(root -> right);
            return left + right + abs(1 - left - right - root -> val);
        }
    }
public:
    int distributeCoins(TreeNode* root) {
        return porder(root);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);



    return 0;
}