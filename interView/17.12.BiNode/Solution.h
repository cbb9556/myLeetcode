#include <cstdlib>
#include "BSTree.h"
using namespace std; 

class Solution {
public:
    BSTree<int> node;
    void inOrder(BSTree<int> &node)
    {
        if(node.isEmpty())  return ;
        inOrder(node.left);
        node->left=NULL;    //将该节点的左孩子设为NULL
        cur->right=node;    //将该节点赋给上一个节点的右孩子
        cur=node;           //更新cur
        inOrder(node->right);
    }
    void convertBiNode(BSTree<int> &root) {
        inOrder(root);
        return ans->right;
    }
};