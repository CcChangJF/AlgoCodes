#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
    int getFirstGreater(vector<int> &vec, int s, int e, int val) {
        for (int i = s; i < e; ++i) {
            if (val < vec[i]) { return i; }
        }
        return e;
    }

    TreeNode* build(vector<int> &preorder, int left, int right) {
        if (left >= right) { return NULL;}
        int p = left;
        int mid = getFirstGreater(preorder, left + 1, right, preorder[p]);
        TreeNode* root = new TreeNode(preorder[p]);
        root -> left = build(preorder, left + 1, mid);
        root -> right = build(preorder, mid, right);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, preorder.size());
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //8,5,1,7,10,12


    return 0;
}