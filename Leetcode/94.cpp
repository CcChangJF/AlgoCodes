
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res = vector<int>();
        if (NULL == root) {
            return res;
        }
        TreeNode *p = root;
        stack<TreeNode *> s = stack<TreeNode *>();
        while(!s.empty() || NULL != p) {
            if (NULL != p) {
                s.push(p);
                p = p -> left;
            }
            else {
                TreeNode *parent = s.top();
                res.push_back(parent -> val);
                p = parent -> right;
                s.pop();
            }
        }
        return res;
    }
};

int main() {

    return 0;
}