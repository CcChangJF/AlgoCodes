
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res = vector<int>();
        if (NULL == root) { return res;}
        stack<TreeNode*> s = stack<TreeNode *>();
        TreeNode *p = root;
        while (!s.empty() || NULL != p) {
            if (NULL != p) {
                s.push(p);
                res.insert(res.begin(), p -> val);
                p = p -> right;
            }
            else {
                p = s.top() -> left;
                s.pop();
            }
        }
        return res;
    }
};

int main() {

    return 0;
}