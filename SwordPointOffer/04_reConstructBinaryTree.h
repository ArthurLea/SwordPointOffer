#pragma once

namespace arthurlea
{
	/**
	* Definition for binary tree
	* struct TreeNode {
	*     int val;
	*     TreeNode *left;
	*     TreeNode *right;
	*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	* };
	*/
	#include <vector>
	#include <iostream>
	#include <exception>
	using namespace std;

	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	class Solution_04
	{
	public:
		TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin)
		{
			if (pre.empty() || vin.empty() || (pre.size()!=vin.size()))
				return NULL;
			int* preStart = &pre[0];
			int* preEnd = &pre[pre.size() - 1];
			int* vinStart = &vin[0];
			int* vinEnd = &vin[vin.size() - 1];
			return constructBinaryTree(preStart, preEnd, vinStart, vinEnd);
		}
	private:
		TreeNode * constructBinaryTree(int* preStart, int* preEnd, int* vinStart, int* vinEnd)
		{
			int rootVal = preStart[0];
			TreeNode* root = new TreeNode(preStart[0]);
			//root->val = rootVal;
			//root->left = root->right = NULL;
			if (preStart == preEnd)
			{
				if ((vinStart == vinEnd) && (preStart == vinEnd))
				{
					return root;
				}
				//else
				//{
				//	throw exception("Invalid input");
				//}
			}
			//�����������в��Ҹ��ڵ�
			int* rootVin = vinStart;
			while ((rootVin != vinEnd) && (*rootVin != rootVal))
			{
				++rootVin;
			}
			//if ((rootVin == vinEnd) || (*rootVin != rootVal))
			//{
			//	throw exception("Invalid input");
			//}
			int leftLength;
			try
			{
				leftLength = rootVin - vinStart;
			}
			catch (exception e)
			{
				cout << e.what() << endl;
			}
			int* preLeftEnd = preStart + leftLength;
			//����������
			if (leftLength > 0)
			{
				root->left = constructBinaryTree(preStart + 1, preLeftEnd, vinStart, rootVin - 1);
			}
			//����������
			if (leftLength < (preEnd - preStart))
			{
				root->right = constructBinaryTree(preLeftEnd + 1, preEnd, rootVin + 1, vinEnd);
			}

			return root;
		}
	};
}