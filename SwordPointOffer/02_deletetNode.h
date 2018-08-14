#pragma once
/*
* 在O(1)时间内删除链表结点，传入参数为头结点，和待删除的结点
* 1、常规思路：顺序遍历找到这个结点，然后让他的前结点指向他的next结点，复杂度为O(n)
* 2、由于并不在乎结点的内存地址，仅关心结点值，可将需要删除结点A的下一个节点B直接赋值给A，然后删除B即可

*/
namespace arthurleaother
{
#include <iostream>

	using namespace std;

	struct ListNode
	{
		int m_val;
		ListNode* m_next;
	};
	class Solution_02
	{
	public:
		void deleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
		{
			if (!pListHead || !pToBeDeleted)
			{
				return;
			}
			
			if (pToBeDeleted->m_next != NULL)//删除的结点不是尾结点
			{
				ListNode* pNext = pToBeDeleted->m_next;
				pToBeDeleted->m_val = pNext->m_val;
				pToBeDeleted->m_next = pNext->m_next;

				delete pNext; //回收空间
				pNext = NULL;
			}
			else if (/*pToBeDeleted->m_next == NULL &&*/ *pListHead == pToBeDeleted)//链表只有一个结点
			{
				delete pToBeDeleted;
				pToBeDeleted = NULL;
				*pListHead = NULL;
			}
			else //删除的是尾结点
			{
				ListNode* pNode = *pListHead;
				while (pNode->m_next != pToBeDeleted)
				{
					pNode = pNode->m_next;
				}
				pNode->m_next = NULL;

				delete pToBeDeleted;
				pToBeDeleted = NULL;
			}
		}
	};
}