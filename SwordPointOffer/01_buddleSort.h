#pragma once
/* 从小到大排序
* 未排序的数组长度为N
* 1、比较相邻前后的两个元素[j-1],[j]，如果前面元素大于后面的元素就交换两个元素
* 2、这样一趟后，最大的数就通过冒泡的方式放到了“N-1”的位置
* 3、N=N-1,如果N!=0就重复前两步
*/
namespace arthurlea_01
{
	inline void swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	//1、常规操作
	void buddleSort(int arr[], int N)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 1; j < N - i; ++j)
			{
				if (arr[j - 1] > arr[j])
				{
					swap(arr[j - 1], arr[j]);
				}
			}
		}
	}
	//改进1：加一个标志flag，如果在一趟比较过程中未发生一次交换，说明已经排序好
	void buddleSort2(int arr[], int N)
	{
		int flag = true;
		int count = N;
		while (flag)
		{
			flag = false;
			for (int j = 1; j < count; j++)
			{
				if (arr[j - 1] > arr[j])
				{
					swap(arr[j - 1], arr[j]);
					flag = true;
				}
			}
			--count;
		}
	}
	//改进2：降低比较次数，如果有100个数的数组，前10个数无序，后90个已经有序，那么在比较
	//发生交换的位置一定在10之前，因为后面有序不会发生交换，此时可以记录这个位置，然后作为
	//下次遍历的终点
	void buddleSort3(int arr[], int N)
	{
		int count = N;
		bool flag = true;
		int index = N;
		while (flag)
		{
			count = index;
			flag = false;
			for (int j = 1; j < count; ++j)
			{
				if (arr[j - 1]>arr[j])
				{
					swap(arr[j - 1], arr[j]);
					index = j;
					flag = true;
				}
			}
		}
	}

}