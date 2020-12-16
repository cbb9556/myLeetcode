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
    ListNode *a = create_linkedlist({7,3,5,1,9});
    printList(a);

    ListNode* ret = s.reverseBetween(a, 1, 3);
    printList(ret);
    clear(ret);
	return 0;
}