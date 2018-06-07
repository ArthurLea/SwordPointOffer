#pragma once
/*
* 按增量分组的直接插入排序，利用在序列基本有序的情况下，直接插入排序效率很高的特点
* 1、gap=N/2，共分为0->gap组
* 2、按组遍历元素,对每组进行插入排序
* 3、gap=gap/2，如果gap不为0，重复第二步，我们称之为“跳着插”
*/
/* 
* 希尔排序是基于插入排序的以下两点性质而提出改进方法的：
*  ~插入排序在对几乎已经排好序的数据操作时，效率高，即可以达到线性排序的效率
*  ~但插入排序一般来说是低效的，因为插入排序每次只能将数据移动一位
*/
namespace arthurlea_03
{
	inline void swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	void shellSort(int arr[], int N)
	{
		//int gap = N / 2;
		for (int gap = N / 2; gap > 0; gap /= 2)
		{
			for (int i = 0; i < gap; i++)
			{
				for (int j = i + gap; j < N; j += gap)
				{
					int tmp = arr[j];
					int k = j - gap;
					//for (; k >= 0 && arr[k] > tmp; k -= gap)
					//{
					//swap(arr[k], arr[j]);
					//}
					while (k >= 0 && arr[k] > tmp)
					{
						arr[k + gap] = arr[k];
						k -= gap;
					}
					arr[k + gap] = tmp;
				}
			}
		}
	}

	//改进1：精简代码
	// 不遍历每个组，采用从gap开始循序渐进方式，依次直接插入排序
	void shellSort2(int arr[], int N)
	{
		for (int gap = N / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < N; i++)
			{
				int tmp = arr[i]; //当前需要插入的数据
				int j = i - gap;
				while (((j >= 0) && arr[j] > tmp))
				{
					arr[j + gap] = arr[j];
					j -= gap;
				}
				arr[j + gap] = tmp;
			}
		}
	}
	//改进2：进一步精简，用swap替代赋值操作以精简操作
	void shellSort3(int arr[], int N)
	{
		for (int gap = N / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < N; i++)
			{
				for (int j = i - gap; (j >= 0) && (arr[j] > arr[j + gap]); j -= gap)
				{
					swap(arr[j], arr[j + gap]);
				}
			}
		}
	}
}