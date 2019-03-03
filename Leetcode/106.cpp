
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (0 == inorder.size()) { return NULL;}
        int inIndex = inorder.size() - 1;
        int postIndex = postorder.size() - 1;
        stack<TreeNode *> s = stack<TreeNode *>();
        TreeNode *root = new TreeNode(postorder[postIndex--]);
        s.push(root);
        while(postIndex >= 0) {
            TreeNode *p = s.top();
            if (p -> val != inorder[inIndex]) {
                p -> right = new TreeNode(postorder[postIndex--]);
                s.push(p -> right);
            }
            else {
                s.pop();
                --inIndex;
                if (s.empty() || s.top() -> val != inorder[inIndex]) {
                    p -> left = new TreeNode(postorder[postIndex--]);
                    s.push(p -> left);
                }
            }
        }
        return root;
    }
};


class Solution1 {
    TreeNode *build(vector<int> &postorder, int rootIndex, 
        vector<int> &inorder, int left, int right) {
        cout << rootIndex << " " << left << " " << right << endl;
        if (left >= right) { return NULL;}
        TreeNode *root = new TreeNode(postorder[rootIndex]);
        int newRootIndex = right -  1;
        while (postorder[rootIndex] != inorder[newRootIndex]) {
            --newRootIndex;
        }
        root -> right = build(postorder, rootIndex - 1, inorder, newRootIndex + 1, right);
        root -> left = build(postorder, rootIndex - (right - newRootIndex), inorder, left, newRootIndex);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (0 == inorder.size() ) { return NULL;}
        TreeNode *root = build(postorder, postorder.size() - 1, inorder, 0, inorder.size());
        return root;
    }
};

int main() {
    Solution s;

    vector<int> inorder;
    vector<int> postorder;

    inorder = vector<int>({9,3,15,20,7});
    postorder = vector<int>({9,15,7,20,3})

    return 0;
}