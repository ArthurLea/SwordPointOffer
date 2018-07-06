#pragma once
#pragma once
/*
* 输入一个链表，输出该链表中倒数第k个结点。
* 1、一般思路,遍历整个链表，找大n-k+1个节点，然后删除就行，这里我们需要知道n，所以需要完全遍历一次才行 因此总的复杂度为O(2*n)
* 2、>利用两个指针p1,p2，开始都指向链表头，p1指针先走k-1步，然后剩下n-k+1步到达链表尾，
*    >此时p1，p2同时走,那么走n-k+1步后就找到了倒数的第k个结点
* 鲁棒性检查：链表空、k小于0、链表个数小于k
*/
namespace arthurlea
{
#include<vector>
using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL) {
}
};
class Solution_11
{
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if ((pListHead == NULL) || (k <= 0))
		{
			return NULL;
		}
		ListNode* pBeginRun = pListHead;
		ListNode* pBehind = NULL;
		for (unsigned int i = 0; i < k - 1; ++i)
		{
			if (pBeginRun->next != NULL)
			{
				pBeginRun = pBeginRun->next;
			}
			else
			{
				return NULL;
			}
		}
		pBehind = pListHead;
		while (pBeginRun->next != NULL)
		{
			pBeginRun = pBeginRun->next;
			pBehind = pBehind->next;
		}

		return pBehind;
	}
};
}