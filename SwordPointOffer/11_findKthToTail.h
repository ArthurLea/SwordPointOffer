#pragma once
#pragma once
/*
* ����һ����������������е�����k����㡣
* 1��һ��˼·,�������������Ҵ�n-k+1���ڵ㣬Ȼ��ɾ�����У�����������Ҫ֪��n��������Ҫ��ȫ����һ�β��� ����ܵĸ��Ӷ�ΪO(2*n)
* 2��>��������ָ��p1,p2����ʼ��ָ������ͷ��p1ָ������k-1����Ȼ��ʣ��n-k+1����������β��
*    >��ʱp1��p2ͬʱ��,��ô��n-k+1������ҵ��˵����ĵ�k�����
* ³���Լ�飺����ա�kС��0���������С��k
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