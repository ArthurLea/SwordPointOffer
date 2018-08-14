#pragma once
/*
* ����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬
* ��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head��
* ��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
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
			//���ƽڵ㣬�����ƵĽڵ�˳��������ԭ������
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