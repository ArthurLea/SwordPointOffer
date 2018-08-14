#pragma once


/*
* ����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
* ·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
* (ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)
*/
#include <vector>
using namespace std;
namespace arthurlea
{
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
	};
	class Solution_21 {
	public:			
		vector<vector<int>> result;
		vector<int> pathSet;
		vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {

			if (root == nullptr) return result;

			pathSet.push_back(root->val);
			if ((expectNumber - root->val) == 0 && root->left == nullptr && root->right == nullptr)
			{
				result.push_back(pathSet);
			}
			FindPath(root->left, expectNumber - root->val);
			FindPath(root->right, expectNumber - root->val);
			if (!pathSet.empty())
			{
				pathSet.pop_back();
			}
			return result;
		}
	};
}
