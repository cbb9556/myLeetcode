#include <cstddef>
#include <cstdlib>
#include <iostream>
using namespace std;
/*this vim git history*/
struct ListNode {
	/* data */
	int val;
	ListNode* Next;
	ListNode(int x): val(x), Next(NULL) {}
};

class Solution {
private:
	/* data */
public:
	Solution(/* args */) = default;
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode dummy(0), *tail = &dummy;

		//div_t存储一个除法的 商 和 余数 quot是商；rem是余数

		for (div_t sum{0,0}; sum.quot || l1 || l2; tail = tail->Next) {
			if (l1) {sum.quot += l1->val; l1 = l1->Next;}
			if (l2) {sum.quot += l2->val; l2 = l2->Next;}
			sum = div(sum.quot,10);
			tail->Next = new ListNode(sum.rem);
		}
		return dummy.Next;
	}

};

ListNode *create_linkedlist(std::initializer_list<int> lst) {
	auto iter = lst.begin();
	ListNode *head = lst.size() ? new ListNode(*iter++) : NULL;
	for (ListNode *cur = head; iter != lst.end(); cur = cur->Next) {
		cur->Next = new ListNode(*iter++);
	}
	return head;
}

ListNode * creat_linkedlist(initializer_list<int> lst) {
	auto iter = ls.begin();
	ListNode *head = lst.size() ? new ListNode(*iter)
}
int main(int argc, char const *argv[])
{
	Solution s;
    ListNode *l1 = create_linkedlist({2,4,3});
    ListNode *l2 = create_linkedlist({5,6,4});
    ListNode *ret = s.addTwoNumbers(l1, l2);
    for (ListNode *cur = ret; cur; cur = cur->Next)
        cout << cur->val << "->";
    cout << "\b\b  " << endl;
	return 0;
}
