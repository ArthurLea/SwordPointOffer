#pragma once
/*
* 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/
#include <vector>
#include <queue>
using namespace std;
namespace arthurlea
{
	struct TreeNode
	{
		int				val;
		TreeNode*		left;
		TreeNode*		right;
	};
	class Solution_19
	{
	public:
		vector<int> PrintFromTopToBottom(TreeNode* root) {
			queue<TreeNode*> dataQueue;
			vector<int> result;
			if (root == nullptr) return result;

			dataQueue.push(root);
			while (!dataQueue.empty()) //while(dataQueu.size())
			{
				TreeNode* currentNode = dataQueue.front();
				dataQueue.pop();
				result.push_back(currentNode->val);

				if (currentNode->left != nullptr)
				{
					dataQueue.push(currentNode->left);
				}
				if(currentNode->right != nullptr)
				{
					dataQueue.push(currentNode->right);
				}
			}

			return result;
		}
	};
}