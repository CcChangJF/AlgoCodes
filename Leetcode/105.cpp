
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



void preOrder(TreeNode *root) {
    if (NULL == root) {
        return;
    }
    cout << root -> val << " ";
    preOrder(root -> left);
    preOrder(root -> right);
    return;
}

void inOrder(TreeNode *root) {
    if (NULL == root) {
        return;
    }
    inOrder(root -> left);
    cout << root -> val << " ";
    inOrder(root -> right);
    return;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (0 == preorder.size()) { return NULL;}
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *p = root;
        int preIndex = 1;
        int inIndex = 0;
        stack<TreeNode *> s = stack<TreeNode *>();
        s.push(root);
        while(preIndex < preorder.size()) {
            if (s.top() -> val != inorder[inIndex]) {
                p -> left = new TreeNode(preorder[preIndex++]);
                s.push(p -> left);
                p = p -> left;
            }
            else {
                ++inIndex;
                TreeNode *par = s.top();
                s.pop();
                if (s.empty() || s.top() -> val != inorder[inIndex]) {
                    par -> right = new TreeNode(preorder[preIndex++]);
                    p = par -> right;
                    s.push(p);
                }
            }
        }
        // preOrder(root);
        // cout << endl;
        // inOrder(root);
        // cout << endl;
        return root;
    }
};

class Solution1 {

    TreeNode *build(TreeNode *root, vector<int> &preorder, int index,
        vector<int> &inorder, int left, int right) {
        if (left == right) {
            return NULL;
        }
        // cout << "root: " << preorder[index] << " , ";
        root = new TreeNode(preorder[index]);
        int newRootIndex = left;
        while (preorder[index] != inorder[newRootIndex]) {
            ++newRootIndex;
        }
        // cout << "newRoot: " << newRootIndex << endl;
        root -> left = build(root -> left, preorder, index + 1, 
            inorder, left, newRootIndex);
        root -> right = build(root -> right, preorder, index + (newRootIndex - left) + 1,
            inorder, newRootIndex + 1, right);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (0 == preorder.size()) { return NULL;}
        TreeNode *root = NULL;
        root = build(root, preorder, 0, inorder, 0, inorder.size());
        // preOrder(root);
        // cout << endl;
        // inOrder(root);
        // cout << endl;
        return root;
    }
};

int main() {

    Solution s;
    vector<int> preorder;
    vector<int> inorder;


    preorder = vector<int>({3,9,20,15,7});
    inorder = vector<int>({9,3,15,20,7});
    s.buildTree(preorder, inorder);
    return 0;
}