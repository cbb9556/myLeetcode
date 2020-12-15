#include <vector>
using std::vector;
//#include <cstddef>

//结构体数据结构，表示链表的每个节点，有指针数据需要使用成员初始化列表
struct ListNode {
    int val; //存储的整形数据
    ListNode *next;//指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {} // 构造函数，结构体与类的唯一区别，结构体默认为public
};

class Solution {
    //合并两个链表，数据类型是结构体指针，指针的好处不需要对对象进行初始化
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        //命名方式，同时声明** 和 *； **是一个哨兵指针
        ListNode *head = nullptr, **lastPtrRef = &head;
        //循环结束条件，只要有一个链表为空就结束；哨兵每次都移到已经合并好的链表的最后
        for (;l1 && l2; lastPtrRef = &((*lastPtrRef)->next)) {
            //每次将哨兵指向最小的那个值的链表，使用*取链表的值，将
            if (l1->val <= l2->val) { *lastPtrRef = l1; l1 = l1->next; }
            else { *lastPtrRef = l2; l2 = l2->next; }
        }
        *lastPtrRef = l1 ? l1 : l2;
        return head;
    }

    //别名
    using vecNodeCIter = vector<ListNode *>::const_iterator;

    //递归合并K个list
    ListNode *mergeKLists(vecNodeCIter beg, vecNodeCIter end) {
        if (beg == end) return NULL;
        //迭代器取值操作                   
        else if (std::distance(beg, end) == 1) return *beg;
        else if (std::distance(beg, end) == 2) return mergeTwoLists(*beg, *std::next(beg));
        else return mergeTwoLists(mergeKLists(beg, beg + std::distance(beg, end)/2), mergeKLists(beg + std::distance(beg, end)/2, end));
    }
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        //cbegin是const迭代器，不能用于修改元素
        return mergeKLists(lists.cbegin(), lists.cend());
    }
};

// a recursive algorithm
// compare the minimum list[i], and 
class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

// the Iterative algorithm
// 
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // creat a gard node with a value < 0
        ListNode* preHead = new ListNode(-1);

        // a prev pointer 
        ListNode* prev = preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev->next = l1 == nullptr ? l2 : l1;

        return preHead->next;
    }
};