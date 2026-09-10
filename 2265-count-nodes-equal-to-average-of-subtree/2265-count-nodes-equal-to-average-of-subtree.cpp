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

    int count=0;

    pair<int,int> postorder(TreeNode* root){

        if(!root){
            return {0,0};
        }

        pair<int,int> a = postorder(root->left);
        pair<int,int> b = postorder(root->right);
        pair<int,int> c = { (a.first+b.first+root->val) , (a.second+b.second+1)};
        if( ((c.first)/(c.second)) ==root->val ) count++;

        return c;

    }
public:
    int averageOfSubtree(TreeNode* root) {
        postorder(root);
        return count;
    }
};