#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    std::unordered_set<ListNode*> set;

    ListNode* cur_a = headA;
    while (cur_a) {
      set.insert(cur_a);
      cur_a = cur_a->next;
    }

    ListNode* cur_b = headB;
    while (cur_b) {
      if (set.find(cur_b) != set.end())  //找到了
      {
        return cur_b;
      }
      cur_b = cur_b->next;
    }
    
    return nullptr;
  }
};