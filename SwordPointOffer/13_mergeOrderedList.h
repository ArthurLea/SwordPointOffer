#pragma once
/*
* 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/
namespace arthurlea
{
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
class Solution_13 
{
public:
	ListNode * Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL)
		{
			return pHead2;
		}
		if (pHead2 == NULL)
		{
			return pHead1;
		}
		ListNode* pHead = NULL;
		if (pHead1->val < pHead2->val)
		{
			pHead = pHead1;
			pHead->next = Merge(pHead1->next, pHead2);
		}
		else
		{
			pHead = pHead2;
			pHead->next = Merge(pHead1,pHead2->next);
		}
		return pHead;
	}
};
}