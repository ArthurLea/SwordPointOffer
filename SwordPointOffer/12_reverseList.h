#pragma once
/*
* 输入一个链表，反转链表后，输出新链表的表头。
* 思路：由于是单链表，所以在反转时，我们需要知道当前结点pNode，需要只掉当前结点的前一个结点pPrev，为了防止链表断裂，
*     在反转pNode之前，我们需要记忆pNode的下一个结点pNext
*/
namespace arthurlea
{
#include <iostream>
using namespace std;
struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
class Solution_12
{
public:
	ListNode * ReverseList(ListNode* pHead) 
	{
		ListNode* pReverseList = NULL;
		ListNode* pNode = pHead;
		ListNode* pPrev = NULL;
		while (pNode != NULL)
		{
			ListNode* pNext = pNode->next;
			if (pNext == NULL)
			{
				pReverseList = pNode;
			}
			pNode->next = pPrev;
			pPrev = pNode;

			pNode = pNext;
		}

		return pReverseList;
	}
};
}