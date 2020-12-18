#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "Solution.h"
using namespace std;
using vecIter = std::vector<int>::iterator;

TreeNode* createBinaryTree(vecIter beg, vecIter end) {
  std::vector<TreeNode*> vec;
  for (vecIter it = beg; it != end; ++it)
    vec.push_back(new TreeNode(*it));

  for (int i = 0, pos = 0; pos != vec.size() - 1; ++i) {
    vec[i]->left = vec[++pos];
    vec[i]->right = vec[++pos];
  }
  return *vec.begin();
}

void print_bfs(TreeNode* p) {
  if (!p)
    return;
  std::vector<std::string> v;
  std::queue<TreeNode*> q;
  q.push(p);
  do {
    TreeNode* node = q.front();
    q.pop();
    if (node)
      v.push_back(std::to_string(node->val));
    else {
      v.push_back("#");
      continue;
    }
    q.push(node->left);
    q.push(node->right);
  } while (!q.empty());

  auto found = std::find_if(v.rbegin(), v.rend(),
                            [](const std::string& s) { return s != "#"; });
  v.erase(found.base(), v.end());
  for (const auto& s : v)
    std::cout << s << ",";
  std::cout << "\b " << std::endl;
}

int main() {
  std::vector<int> vec{1, 2, NULL, 4, 5};
  TreeNode* p = createBinaryTree(vec.begin(), vec.end());
  Solution s;

  print_bfs(p);
  std::cout << s.maxDepth(p) << std::endl;
  return 0;
}
