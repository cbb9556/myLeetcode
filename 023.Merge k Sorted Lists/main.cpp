//#include "solution.h"
#include "test.h"
#include <iostream>
using namespace std;

ListNode *create_linkedlist(std::initializer_list<int> lst)
{
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : nullptr;
    for (ListNode *cur=head; iter != lst.end(); cur=cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}

void clear(ListNode *head)
{
    while (head) {
        ListNode *del = head;
        head = head->next;
        delete del;
    }
}

void printList(ListNode *head) {
    for (ListNode *cur = head; cur; cur = cur->next)
        cout << cur->val << "->";
    cout << "\b\b  " << endl;
}

int main()
{
    test s;
    vector<ListNode *> vec{
        create_linkedlist({1,3,5,7,9}),
        create_linkedlist({2,4,6,8,10}),
        create_linkedlist({0,11,12,13,14})
    };
    ListNode *ret = s.mergeKlists(vec);    
    printList(ret);
    clear(ret);
/*
    Solution1 s2;
    std::vector<ListNode *> vect{
        create_linkedlist({2,3,4,5}),
        create_linkedlist({1,4,5,6})
    };

    ListNode *rett = s2.mergeTwoLists(vect[0],vect[1]);
    printList(rett);
    clear(rett);
*/
    return 0;
}

