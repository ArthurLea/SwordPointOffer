#pragma once
/*
* 6、从旋转数组中寻找最小数
* 数组本有序，从小到大排序，经过旋转，前面部分数据放在后面，后面的数据直接往前移
* eg:arr[i..j..n-1]中[i~j]的数据往后移动，[j+1~n-1]数据往前移，现在需要从旋转后的数组中找到最小的数据
* 5 6 7 1 2 3 4 
* 1 1 0 1 1 1 1
*/
namespace arthurlea
{

/*
* 5、利用两个栈实现队列的入队出队
* 相似：两个队列实现栈的入栈出栈
*/
#include <exception>

class Solution_06
{
public:
	int minNumberInRotateArray(vector<int> rotateArray) 
	{
		if (rotateArray.size() <= 0)
		{
			//throw new exception("Invalid input");
		}
		int index1 = 0;
		int index2 = rotateArray.size() - 1;
		int mid = index1;
		while (rotateArray[index1] >= rotateArray[index2])
		{
			if ((index2 - index1) == 1)
			{
				mid = index2;
				return rotateArray[mid];
			}
			mid = (index1 + index2) / 2;
			if ((rotateArray[index1] == rotateArray[mid]) && (rotateArray[mid] == rotateArray[index2]))
			{
				return minInorder(rotateArray, index1, index2);
			}
			if (rotateArray[mid] >= rotateArray[index1])
			{
				index1 = mid;
			}
			else if (rotateArray[mid] <= rotateArray[index2])
			{
				index2 = mid;
			}
		}
		return  rotateArray[mid];
	}
private:
	int minInorder(vector<int>arr, int index1, int index2)
	{
		int min = arr[index1];
		for (int i = index1+1; i <= index2; ++i)
		{
			if (min > arr[index1])
			{
				min = arr[index1];
			}
		}
		return min;
	}
};

}