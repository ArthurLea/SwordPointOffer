#pragma once

/*
* 输入两颗二叉树A，B，判断B是否是A的子结构
*/
namespace arthurlea
{
	struct TreeNode
	{
		int				val;
		TreeNode*		left;
		TreeNode*		right;
	};
	class Solution_14
	{
	public:
		bool hasSubTree(TreeNode* pRoot1, TreeNode* pRoot2)
		{
			bool result = false;
			
			if (pRoot1 != nullptr && pRoot2 != nullptr)
			{
				if (pRoot1->val == pRoot2->val)
				{
					result = doesTree1HasTree2(pRoot1, pRoot2);
				}
				if (!result)
				{
					result = hasSubTree(pRoot1->left, pRoot2);
				}
				if (!result)
				{
					result = hasSubTree(pRoot1->right, pRoot2);
				}
			}
			return result;
		}
	private:
		bool doesTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2)
		{
			if (pRoot1 == nullptr)
			{
				return false;
			}
			if (pRoot2 == nullptr)
			{
				return true;
			}
			
			if (pRoot1->val != pRoot2->val)
			{
				return false;
			}
			return doesTree1HasTree2(pRoot1->left, pRoot2->left) &&
				doesTree1HasTree2(pRoot1->right, pRoot2->right);
		}
	};
}