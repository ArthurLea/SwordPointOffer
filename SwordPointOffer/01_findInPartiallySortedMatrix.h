#pragma once


/* 1����ά�����еĲ���
* ��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
*/
namespace ArthurLea
{
	typedef struct index
	{
		int row;
		int column;
	}ResultIndex;
	class Solution_01 
	{
	public:
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
						/*���ڲ��Ե��ӵ�*/
						m_index.row = row;
						m_index.column = column;
						/**/
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

}