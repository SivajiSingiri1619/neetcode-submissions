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
    bool ans = true;
    int height(TreeNode* root){
         if(!root) return 0;

         return max(height(root->left)+1,height(root->right)+1);
    }
    void helper(TreeNode* root){
       
        if(abs(height(root->left) - height(root->right)) > 1)  ans = false;
        if(root->left) helper(root->left);
        if(root->right) helper(root->right);
        
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
         helper(root);
         return ans;
    }
};
