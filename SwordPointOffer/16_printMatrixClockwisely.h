#pragma once
/*
* ����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
* ���磬�����������4 X 4���� 
* 1  2  3  4 
* 5  6  7  8 
* 9  10 11 12 
* 13 14 15 16 
* �����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/
#include <vector>
using namespace std;
namespace arthurlea
{
	class Solution_16
	{
	public:
		vector<int> printMatrix(vector<vector<int> > matrix) {
			vector<int> result;
			int rows = matrix.size();
			int coloumns = matrix[0].size();
			if (rows == 0 || coloumns == 0) return result;

			int start = 0;
			while (rows > start * 2 && coloumns > start * 2)
			{
				int endX = coloumns - 1 - start;
				int endY = rows - 1 - start;
				//printMatrixInCircle(result, matrix, rows, coloumns, starts);
				//��->��
				for (int i = start; i <= endX; ++i)
					result.push_back(matrix[start][i]);
				//��->��
				if (endY > start)
				{
					for (int i = start + 1; i <= endY; ++i)
						result.push_back(matrix[i][endX]);
				}
				//��->��
				if (endY > start && endX > start)
				{
					for (int i = endX - 1; i >= start; --i)
						result.push_back(matrix[endY][i]);
				}
				//��->��
				if (endY > start + 1 && endX > start)
				{
					for (int i = endY - 1; i > start; --i)
						result.push_back(matrix[i][start]);
				}
				start++;
			}
			return result;
		}
	};
}