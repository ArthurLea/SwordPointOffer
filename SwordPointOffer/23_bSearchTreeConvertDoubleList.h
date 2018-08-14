#pragma once
/*
* ����һ�ö��������������ö���������ת����һ�������˫������
* Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
*/
#include <iostream>
using namespace std;
namespace arthurlea
{
	struct TreeNode
	{
		int				val;
		TreeNode*		left;
		TreeNode*		right;
	};
	class Solution_23
	{
	public:
		TreeNode* convert(TreeNode* root)
		{
			TreeNode* lastNodeInList = NULL; 
			convertNode(root, lastNodeInList); //����ָ����������һ���ڵ�

			TreeNode* headInList = lastNodeInList;
			while (headInList->left != nullptr) //���˵�������ײ�λ��
			{
				headInList = headInList->left;
			}

			return headInList;
		}
	private:
		void convertNode(TreeNode* root, TreeNode*& lastNodeInList)
		{
			if (root == nullptr) return;
			TreeNode* currentNode = root;
			if (currentNode->left != nullptr)
			{
				convertNode(currentNode->left, lastNodeInList);
			}

			currentNode->left = lastNodeInList;
			if (lastNodeInList != nullptr)
			{
				lastNodeInList->right = currentNode;
			}
			lastNodeInList = currentNode;

			if (currentNode->right != nullptr)
			{
				convertNode(currentNode->right, lastNodeInList);
			}
		}
	};
}