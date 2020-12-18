#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (root == NULL) { return 0;}
    int L = maxDepth(root->left) + 1;
    int R = maxDepth(root->right) + 1;
    int maxDepth = max(L,R);
    return maxDepth;
  }
};