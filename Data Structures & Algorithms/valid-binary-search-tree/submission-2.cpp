/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validity(INT_MIN, root, INT_MAX);
    }
    bool validity(int left, TreeNode* root, int right) {
        if(!root)
            return true;
        else if(!(left < root->val) || !(right > root->val))
            return false;
        return validity(left, root->left, root->val) &&
                validity(root->val, root->right, right);
    }
};
