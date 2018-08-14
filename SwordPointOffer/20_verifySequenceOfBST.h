#pragma once
/*
* 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
* 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
* 注意:二叉搜索树的特点
*/
#include <vector>
using namespace std;
namespace arthurlea
{

	class Solution_20 {
	public:
		bool VerifySquenceOfBST(vector<int> sequence) {
			return bst(sequence, 0,sequence.size()-1);
		}
	private:
		bool bst(vector<int> sequence, int begin, int end)
		{
			if (sequence.empty() || begin < 0 || end<0 || begin>end) return false;
			//int len = sequence.size();
			int root = sequence[end];

			int index = begin;
			//在二叉搜索树中，左结点值均小于根节点
			for (; index < end; ++index) //找到左子树的最后的一节点位置
			{
				if(sequence[index] > root)
				{
					break;
				}
			}
			int endIndexOfRight = index;
			//在二叉搜索树中，右结点值均大于根节点，判断右子树的节点是否都大于根节点
			for (; endIndexOfRight < end; ++endIndexOfRight)
			{
				if (sequence[endIndexOfRight] < root)
				{
					return false;
				}
			}

			//判断左子树是不是二叉搜索树
			bool bLeft = true;
			if (index > begin)
			{
				bLeft = bst(sequence, begin, index - 1);
			}
			//判断右子树是不是二叉搜索树
			bool bRight = true;
			if (index < end)
			{
				bRight = bst(sequence,index,end-1);
			}

			return bLeft && bRight;
		}
	};
}