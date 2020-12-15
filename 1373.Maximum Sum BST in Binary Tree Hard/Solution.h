/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxsum = 0;
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxsum;
    }
    vector<int> dfs(TreeNode* root) {
        //如果到达了叶子结点，返回 左边是极大值，右边是极小，也就是root->val大于右边或者且小于左边，必须返回false,0,0,0
        if (!root) return {true, INT_MAX, INT_MIN, 0};
        //深度优先，左子树一直向下，直到 到达root等于NULL，然后开始返回那个点的root的右子树
        auto lArr = dfs(root->left);
        //一直向返回那一个点的右子树一直向下，直到到达root等于NULL，然后返回
        auto rArr = dfs(root->right);

        //这里，由于左右子树都返回了，此时左右子树的 sum max min都知道了，该算root的 4个方面的值
        int sum = 0, curmax, curmin;
        if (!lArr[0] || !rArr[0] || root->val >= rArr[1] || root->val <= lArr[2]) {
            return {false, 0, 0, 0};
        }
        curmin = root->left ? lArr[1] : root->val;
        curmax = root->right ? rArr[2] : root->val;
        sum += (root->val + lArr[3] + rArr[3]);
        maxsum = max(maxsum, sum);
        return {true, curmin, curmax, sum};
    }
};