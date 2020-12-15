#include <vector>
using namespace std;

//这份代码的将k个有序的链表合并写出来，使用了容器的方法，但是对于合并的过程使用的迭代法
//时间复杂度为O(m+n)，空间复杂度为O(1)

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(nullptr) {}
};

class test {
	ListNode *mergeTwolists(ListNode *l1, ListNode *l2) {
		ListNode *head = nullptr, **lastPtrRef = &head;
		//指针赋值与指针移动的区别，这里不用*lastPtrRef, 因为不是给其赋值，而是移动指针
		for (; l1 && l2 ; lastPtrRef = &((*lastPtrRef)->next)) {
			if (l1->val <= l2->val) {*lastPtrRef = l1; l1 = l1->next;}
			else {*lastPtrRef = l2; l2 = l2->next;}
		}
		*lastPtrRef = l1 ? l1 : l2;
		return head;
	}

	using VectNodeCiter = std::vector<ListNode *>::const_iterator;
	ListNode *mergeKlists(VectNodeCiter beg, VectNodeCiter end) {
		if (beg == end) return nullptr;
		else if (std::distance(beg,end) == 1) return *beg;
		else if (std::distance(beg,end) == 2) return mergeTwolists(*beg, *std::next(beg));
		else return mergeTwolists(mergeKlists(beg, beg + std::distance(beg, end)/2),mergeKlists(beg + std::distance(beg, end)/2, end));
	}
public:
	ListNode * mergeKlists(std::vector<ListNode*> &lists) {
		return mergeKlists(lists.cbegin(), lists.cend());
	}
};