
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (NULL == root) { return true;}
        vector<int> inorder = vector<int>();
        stack<TreeNode *> s = stack<TreeNode *>();
        TreeNode *p = root;
        while (!s.empty() || NULL != p) {
            if (NULL != p) {
                s.push(p);
                p = p -> left;
            }
            else {
                TreeNode *parent = s.top();
                inorder.push_back(parent -> val);
                p = parent -> right;
                s.pop();
            }
        }
        for (int i = 1; i < inorder.size(); ++i) {
            if (inorder[i] <= inorder[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}