#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// * Definition for a binary tree node.
    struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
 
class Solution {
public:
/*  递归版本的拷贝树实现
    TreeNode *copyTree(TreeNode *root, int delta = 0) {
        auto nroot = new TreeNode(root->val + delta);
        if (root->left)
            nroot->left = copyTree(root->left, delta);
        if (root->right)
            nroot->right = copyTree(root->right, delta);
        return nroot;
    }
*/
    // 非递归版本的拷贝树实现
    TreeNode *copyTree(TreeNode *root, int delta = 0) {
        auto nroot = new TreeNode(root->val + delta);
        queue<TreeNode*> qt;
        queue<TreeNode*> qo;
        qo.push(root);
        qt.push(nroot);
        while (!qt.empty()) {
            auto o_root = qo.front();
            qo.pop();
            auto t_root = qt.front();
            qt.pop();
            if (o_root->left) {
                t_root->left = new TreeNode(o_root->left->val + delta);
                qo.push(o_root->left);
                qt.push(t_root->left);
            }
            if (o_root->right) {
                t_root->right = new TreeNode(o_root->right->val + delta);
                qo.push(o_root->right);
                qt.push(t_root->right);
            }
        }
        return nroot;
    }

    vector<TreeNode*> generateTrees(int n) {
        // 使用static变量，节省用例不同用例执行时的重复求解开销
        static vector<vector<TreeNode*>> dp(1, vector<TreeNode*>(1, NULL));
        int c_size = n + 1; 
        int o_size = dp.size();
        //cout<<dp.size()<<endl;
        if (c_size > dp.size())
            dp.resize(c_size);
        //cout<<dp.size()<<endl;       

        for (int i = o_size; i <= n; i++) { // 升序求解
            for (int j = 1; j <= i; j++) { // 遍历以不同的数的为根
                const auto &left = dp[j - 1];
                const auto &right = dp[i - j];
                auto &cc = dp[i];
                for (const auto left_ptr : left) // 遍历所有可能的左子树
                    for (const auto right_ptr : right) { // 遍历所有可能的右子树
                        auto root = new TreeNode(j);
                        if (j > 1)
                            root->left = copyTree(left_ptr); // 拷贝左子树
                        if (i > j)
                            root->right = copyTree(right_ptr, j); // 拷贝右子树，并加上偏移值
                        cc.push_back(root);
                    }
            }
        }
        if (n == 0)
            return {};
        return dp[n];
    }
};