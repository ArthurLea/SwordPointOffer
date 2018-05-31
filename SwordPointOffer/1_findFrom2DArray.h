#include <vector>

#include <iostream>
using namespace std;
/* 1����ά�����еĲ���
* ��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
*/
class Solution {
public:
	typedef struct index
	{
		int row;
		int column;
	}ResultIndex;

	bool find(int target, const vector<vector<int> >& array)
	{
		bool ifFind = false;
		if ((array.size() != 0) && (array[0].size() != 0))
		{
			int rows = array.size();
			int row = 0;
			int column = array[0].size() - 1;
			while ((row < rows) && (column >= 0))
			{
				if (array[row][column] == target)
				{
					ifFind = true;
					m_index.row = row;
					m_index.column = column;
					break;
				}
				else if (array[row][column] > target)
				{
					column--;
				}
				else
				{
					row++;
				}
			}
		}

		return ifFind;
	}
	inline ResultIndex getResultIndex() const { return m_index; }
private:
	ResultIndex m_index;
};