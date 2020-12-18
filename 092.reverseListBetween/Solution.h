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

        //边界条件 反转的范围 为0 即 m == n； 空链表 ； 只有一个节点的链表
        if(head == nullptr || head->next == nullptr || m == n) return head;

        //最后返回时 需要用到的 哨兵
        ListNode *dumHead = new ListNode(0);
        dumHead->next = head;
        
        ListNode *front = dumHead, *p, *q, *r;
        int i = 0;
        
        //front指到 m-1 那个元素， 
        for(; i < m-1; i++) front = front->next;    // front -> 第 m-1 个元素
        p = front->next; // m
        q = p->next; // m+1
        
        //三个指针 
        for(i += 2; i < n + 1; i++){    // i 最初跟踪 front；反转链表时，i 跟踪 p，故初始化为 i+2
            r = q->next; //
            q->next = p;
            p = q;
            q = r;
        }

        front->next->next = q;
        front->next = p;
        
        //防止m = 1时，front = dumHead 头节点 被放到尾端 结果 仅返回 head
        if(front == dumHead) head = front->next;
        delete dumHead;
        return head;
    }
};
