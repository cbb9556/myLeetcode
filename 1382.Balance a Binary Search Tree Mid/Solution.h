class Solution {
public:
    //存储排序后的树的值
    vector<int> inorderSeq;

    //通过中序遍历，让树的值从小到大排序
    void getInorder(TreeNode* o) {
        if (o->left) getInorder(o->left);
        inorderSeq.push_back(o->val);
        if (o->right) getInorder(o->right);
    }

    //
    TreeNode* build(int l, int r) {
        int mid = (l + r) >> 1;
        TreeNode* o = new TreeNode(inorderSeq[mid]);
        if (l <= mid - 1) o->left = build(l, mid - 1);
        if (mid + 1 <= r) o->right = build(mid + 1, r);
        return o;
    }

    TreeNode* balanceBST(TreeNode* root) {
        getInorder(root);
        return build(0, inorderSeq.size() - 1);
    }
};


