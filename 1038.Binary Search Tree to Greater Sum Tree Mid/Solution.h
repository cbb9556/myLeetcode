
// Definition for a binary tree node.
class TreeNode {
    public:
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) {val = x;}
};

class Solution {
    public:
    int sum = 0;
    TreeNode bstToGst(TreeNode root) {
        if(root != null){
            bstToGst(root.right);
            sum = sum + root.val;
            root.val = sum;
            bstToGst(root.left);
        }
        return root;
    }
};