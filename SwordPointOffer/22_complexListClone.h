#pragma once
/*
* 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
* 另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
* （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/
namespace arthurlea
{
	
	struct RandomListNode {
		int label;
		struct RandomListNode *next, *random;
		RandomListNode(int x) : label(x), next(nullptr), random(nullptr) { }
	};
	class Solution_22 {
	public:
		RandomListNode * Clone(RandomListNode* pHead)
		{
			//复制节点，将复制的节点顺着连接在原链表上
			cloneNodes(pHead);
			connectRandomNodes(pHead);
			RandomListNode * result = divisionSourceAndCloneNode(pHead);
			return result;
		}
	private:
		void cloneNodes(RandomListNode* pHead)
		{
			RandomListNode* pNode = pHead;
			while (pNode != nullptr)
			{
				RandomListNode* pCloneNode = new RandomListNode(0);
				pCloneNode->label = pNode->label;
				pCloneNode->next = pNode->next;
				pCloneNode->random = nullptr;

				pNode->next = pCloneNode;
				pNode = pCloneNode->next;
			}
		}
		void connectRandomNodes(RandomListNode* pHead)
		{
			RandomListNode* pNode = pHead;
			while (pNode != nullptr)
			{
				RandomListNode* pCloneNode = pNode->next;

				if (pNode->random != nullptr)
				{
					pCloneNode->random = pNode->random->next;
				}
				pNode = pCloneNode->next;
			}
		}
		RandomListNode* divisionSourceAndCloneNode(RandomListNode* pHead)
		{
			RandomListNode* pNode = pHead;
			RandomListNode* pCloneNode = nullptr;
			RandomListNode* pCloneHead = nullptr;

			if (pNode != nullptr)
			{
				pCloneNode = pCloneHead = pNode->next;

				pNode->next = pCloneNode->next;
				pNode = pNode->next;
			}
			while (pNode != nullptr)
			{
				pCloneNode->next = pNode->next;
				pCloneNode = pCloneNode->next;

				pNode->next = pCloneNode->next;
				pNode = pNode->next;
			}

			return pCloneHead;
		}
	};
}