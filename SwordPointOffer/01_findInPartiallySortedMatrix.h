#pragma once


/* 1、二维数组中的查找
* 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
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
						/*用于测试叠加的*/
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