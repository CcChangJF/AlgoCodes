#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
    void cover(TreeNode *root, int &res) {
        if (NULL == root -> left && NULL == root -> right) {
            light[root] = false;
            cam[root] = false;
        }
        else if (NULL == root -> right) {
            cover(root -> left, res);
            if (!light[root -> left] && !cam[root -> left]) {
                cam[root] = true;
                light[root] = true;
                ++res;
            }
            else if (!cam[root -> left]) {
                cam[root] = false;
                light[root] = false;
            }
            else if (!light[root -> left]) {
                light[root] = true;
                cam[root] = false;
            }
            else {
                light[root] = true;
                cam[root] = false;
            }
        }
        else if (NULL == root -> left) {
            cover(root -> right, res);
            if (!light[root -> right] && !cam[root -> right]) {
                cam[root] = true;
                light[root] = true;
                ++res;
            }
            else if (!cam[root -> right]) {
                cam[root] = false;
                light[root] = false;
            }
            else if (!light[root -> right]) {
                light[root] = true;
                cam[root] = false;
            }
            else {
                light[root] = true;
                cam[root] = false;
            }
        }
        else {
            cover(root -> left, res);
            cover(root -> right, res);
            if (cam[root -> left] || cam[root -> right]) {
                return;
            }
            else {
                ++res;
                cam[root] = true;
                light[root] = true;
                return;
            }
        }
    }

    bool getChild(TreeNode *root) {
        if (root == NULL) { return false;}
        return cam[root];
    }
public:
    map<TreeNode *, bool> cam;
    map<TreeNode*, bool> light;
    int minCameraCover(TreeNode* root) {
        if (NULL == root) { return 0;}
        if (NULL == root -> left && NULL == root -> right) { return 1;}
        
        int res = 0;
        cover(root, res);
        if (!light[root] && !getChild(root -> left) && !getChild(root -> right)) { ++res;}
        return res;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);



    return 0;
}