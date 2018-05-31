#pragma once

/* 3����β��ͷ��ӡ����
* ����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��
*/
namespace ArthureLea
{
	#include <vector>
	#include <stack>

	using namespace std;

	struct ListNode 
	{
       int val;
       struct ListNode *next;
       ListNode(int x) : val(x), next(NULL) { }
	};

	class Solution_03
	{
	public:
		vector<int> printListFromTailToHead(ListNode* head) 
		{
			vector<int> result;
			stack<int> container;
			ListNode* pNode = head;
			while (pNode != NULL)
			{
				container.push(pNode->val);
				pNode = pNode->next;
			}
			while (!container.empty())
			{
				int val = container.top();
				result.push_back(val);
				container.pop();
			}

			return result;
		}
		// �ݹ�ⷨ ʹ�õݹ�ʱ�����ٵ��ں����ڶ�������Խ���ջ���� ����з���ֵ ��ô�͸���Ҫ���÷���ֵ�����ں������� ����������ڲ�
		vector<int> result;
		vector<int> printListFromTailToHead_Reversingly(ListNode* head)
		{
			if (head != NULL)
			{
				if (head->next != NULL)
				{
					result = printListFromTailToHead_Reversingly(head->next);
				}
			}
			result.push_back(head->val);
			return result;
		}
	};
}