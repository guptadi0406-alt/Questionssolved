/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans = 0;
    int dfs(TreeNode root){
        if(root==null) return 0;

        int a = dfs(root.left);
        int b = dfs(root.right);
        int c = Math.max(a,Math.max(b,root.val));

        if(c==root.val) ans++;

        return c;

    }

    public int countDominantNodes(TreeNode root) {
        
        dfs(root);
        return ans ;
    }
}