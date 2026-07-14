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
    int ans=0;
    int height(TreeNode* root){
        if(!root) return 0;

        return max(height(root->left)+1,height(root->right)+1);
    }
    void findOf(TreeNode* root){
        ans = max(ans,height(root->left) + height(root->right));
       if(root->left) findOf(root->left);
       if(root->right) findOf(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
         findOf(root);
         return ans;
    }
};
