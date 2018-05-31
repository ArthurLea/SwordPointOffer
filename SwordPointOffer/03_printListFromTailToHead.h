#pragma once

/* 3、从尾到头打印链表
* 输入一个链表，从尾到头打印链表每个节点的值。
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
		// 递归解法 使用递归时尽量少的在函数内定义变量以降低栈开销 如果有返回值 那么就更需要将该返回值定义在函数外了 如果定义在内部
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