#pragma once
/*
* 基本思想：将某个数插入到已经排序号的数组中
* 1、数组a[0]默认有序，无序a[1...n-1],令i=1
* 2、将a[i]插入到列表a[0...i-1]中，形成a[0...i]有序列表
* 3、i++重复第二步直到i=n-1
*/
//书本源代码
void directInsertSort(int arr[], int N)
{
	for (int i = 1; i < N; i++) //当前需要排序的数下标
	{
		int j = 0;
		for (j = i-1; j >= 0; j++)
		{
			if (arr[i] < arr[j]) //找到需要插入的位置j,数据应该插到j+1
			{
				break;
			}
		}
		int temp = arr[i];
		for (int k = i - 1; k >= j; k--) //移动
		{
			arr[k + 1] = arr[k];
		}
		arr[j+1] = temp; //复制数据
	}
}

//改进代码1，优化
void directInsertSort2(int arr[], int N)
{
	for (int i = 1; i < N; i++)
	{
		int temp = arr[i]; //待插入的数据
		if (temp < arr[i - 1])
		{
			int j = i - 1;
			for (; j >= 0&&arr[j]>temp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j+1] = temp;
		}
	}
}
//改进2：使用数据交换来代替数据移动
inlien void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void directInsertSort2(int arr[], int N)
{
	for (int i = 1; i < N; i++)
	{
		for (int j = i - 1; j >= 0 && arr[j] > arr[j+1]; j--)
		{
			swap(arr[j], arr[j+1]);
		}
	}
}
