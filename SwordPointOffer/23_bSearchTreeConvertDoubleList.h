#pragma once
/*
* 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
* 要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
			convertNode(root, lastNodeInList); //最终指向链表的最后一个节点

			TreeNode* headInList = lastNodeInList;
			while (headInList->left != nullptr) //回退到链表的首部位置
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