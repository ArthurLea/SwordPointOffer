#pragma once
/*
* 基本思想:同直接插入排序类似，只不过插入排序每次是将一个数插入已排好的序列以组成更大的序列
*     而选择排序每次是从剩余序列中选择一个最小的同前面已排好序的后一个数进行交换以组成更大的序列
*/
namespace arthurlea_04
{

	inline void swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	void selectSort(int arr[], int N)
	{
		for (int i = 0; i < N; i++)
		{
			int minIndex = i;
			for (int j = i + 1; j < N; j++)
			{
				if (arr[j] < arr[minIndex])
				{
					minIndex = j;
				}
			}
			swap(arr[i], arr[minIndex]);
		}
	}
}