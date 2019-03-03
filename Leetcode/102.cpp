
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (NULL == root) {
            return res;
        }
        queue<TreeNode *> q = queue<TreeNode*>();
        q.push(root);
        int length = 1;
        while (!q.empty()) {
            vector<int> cur = vector<int>();
            int newLength = 0;
            for (int i = 0; i < length; ++i) {
                TreeNode *p = q.front();
                q.pop();
                if (NULL != p -> left) {
                    q.push(p -> left);
                    ++newLength;
                }
                if (NULL != p -> right) {
                    q.push(p -> right);
                    ++newLength;
                }
                cur.push_back(p -> val);
            }
            length = newLength;
            res.push_back(cur);
        }
        return res;
    }
};

int main() {

    return 0;
}