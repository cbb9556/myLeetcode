#include <iostream>
#include <vector>
#include "Solution.h"
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

int main(int argc, char const *argv[]) {
	Solution s;
    ListNode *a = create_linkedlist({1,3,5,7,10});
    ListNode *b = create_linkedlist({1,3,5,7,9});
    
    printList(a);

    ListNode *ret = s.mergeTwoLists(a,b);
    printList(ret);
    clear(ret);
	return 0;
}