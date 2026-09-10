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
    int count=0;

    public int[] post(TreeNode root,int sum,int n){
        if(root==null){
            int arr[]={0,0};
            return arr;
        }

        int a[]=post(root.left,sum,n);
        int b[]=post(root.right,sum,n);

        int arr[]={a[0]+b[0]+root.val,a[1]+b[1]+1};
       

        if(root.val==(arr[0]/arr[1])){
            count++;
        }
        return arr;
    }
    public int averageOfSubtree(TreeNode root) {
        int sum=0;
        int n=0;
        post(root,sum,n);
        return count;
    }
}