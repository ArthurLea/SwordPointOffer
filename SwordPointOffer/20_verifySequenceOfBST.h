#pragma once
/*
* ����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
* ����������Yes,�������No���������������������������ֶ�������ͬ��
* ע��:�������������ص�
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
			//�ڶ����������У�����ֵ��С�ڸ��ڵ�
			for (; index < end; ++index) //�ҵ�������������һ�ڵ�λ��
			{
				if(sequence[index] > root)
				{
					break;
				}
			}
			int endIndexOfRight = index;
			//�ڶ����������У��ҽ��ֵ�����ڸ��ڵ㣬�ж��������Ľڵ��Ƿ񶼴��ڸ��ڵ�
			for (; endIndexOfRight < end; ++endIndexOfRight)
			{
				if (sequence[endIndexOfRight] < root)
				{
					return false;
				}
			}

			//�ж��������ǲ��Ƕ���������
			bool bLeft = true;
			if (index > begin)
			{
				bLeft = bst(sequence, begin, index - 1);
			}
			//�ж��������ǲ��Ƕ���������
			bool bRight = true;
			if (index < end)
			{
				bRight = bst(sequence,index,end-1);
			}

			return bLeft && bRight;
		}
	};
}