#pragma once
/*
* ��O(1)ʱ����ɾ�������㣬�������Ϊͷ��㣬�ʹ�ɾ���Ľ��
* 1������˼·��˳������ҵ������㣬Ȼ��������ǰ���ָ������next��㣬���Ӷ�ΪO(n)
* 2�����ڲ����ں������ڴ��ַ�������Ľ��ֵ���ɽ���Ҫɾ�����A����һ���ڵ�Bֱ�Ӹ�ֵ��A��Ȼ��ɾ��B����

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
			
			if (pToBeDeleted->m_next != NULL)//ɾ���Ľ�㲻��β���
			{
				ListNode* pNext = pToBeDeleted->m_next;
				pToBeDeleted->m_val = pNext->m_val;
				pToBeDeleted->m_next = pNext->m_next;

				delete pNext; //���տռ�
				pNext = NULL;
			}
			else if (/*pToBeDeleted->m_next == NULL &&*/ *pListHead == pToBeDeleted)//����ֻ��һ�����
			{
				delete pToBeDeleted;
				pToBeDeleted = NULL;
				*pListHead = NULL;
			}
			else //ɾ������β���
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