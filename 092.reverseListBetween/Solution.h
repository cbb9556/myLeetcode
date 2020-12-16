#include <string>
#include <vector>
#include <cmath>
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr || head->next == nullptr || m == n) return head;
        ListNode *dumHead = new ListNode(0);
        dumHead->next = head;
        
        ListNode *front = dumHead, *p, *q, *r;
        int i = 0;
        for(; i < m-1; i++) front = front->next;    // front -> 第 m-1 个元素
        p = front->next;
        q = p->next;
        for(i += 2; i < n + 1; i++){    // i 最初跟踪 front；反转链表时，i 跟踪 p，故初始化为 i+2
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        front->next->next = q;
        front->next = p;
        if(front == dumHead) head = front->next;
        delete dumHead;
        return head;
    }
};
