#pragma once
/*
* ����һ��������ת��������������ı�ͷ��
* ˼·�������ǵ����������ڷ�תʱ��������Ҫ֪����ǰ���pNode����Ҫֻ����ǰ����ǰһ�����pPrev��Ϊ�˷�ֹ������ѣ�
*     �ڷ�תpNode֮ǰ��������Ҫ����pNode����һ�����pNext
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