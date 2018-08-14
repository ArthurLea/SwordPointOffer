#pragma once

/*
* 输入一颗二叉树，输出它的镜像
*/
namespace arthurlea
{
	struct TreeNode
	{
		int				val;
		TreeNode*		left;
		TreeNode*		right;
	};
	class Solution_15
	{
	public:
		void mirrorRecursively(TreeNode* pNode)
		{
			if (pNode == nullptr || (pNode->left == nullptr && pNode->right == nullptr))
			{
				return;
			}

			TreeNode* temp = pNode->left;
			pNode->left = pNode->right;
			pNode->right = temp;

			if (pNode->left)
			{
				mirrorRecursively(pNode->left);
			}
			if (pNode->right)
			{
				mirrorRecursively(pNode->right);
			}
		}
	};
}