#pragma once
/* 分治法 有数组arr[0...N-1]
* 基本思想：首先找一个基准base，将序列中比base大的放到右边，将base小的放到左边，
*    然后记录下base的位置，对左右两边采用同样的方法，很多时候以第一个位置作为base，其位置index为0
* 1、i=l,j=r,将i作为基准base的位置，首先从j开始往前索引（j--），找到比base小的，然后a[i] = a[j]
* 2、从i开始往后索引（i++)，找到比base大的数，然后a[i] = a[j]
* 3、如果i<j，重复1、2步骤，结束时i==j
*/

int adjustArr(int arr[], int l, int r);
void fastSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int baseIndex = adjustArr(arr, l, r);
		fastSort(arr, l, baseIndex - 1);
		fastSort(arr, baseIndex + 1, r);
	}
}
int adjustArr(int arr[],int l,int r)
{
	int base = arr[l];
	int i = l;
	int j = r;
	while (i < j)
	{
		while ((i < j) && arr[j] >= base)
		{
			j--;
		}
		if (i < j)
		{
			arr[i] = arr[j];
		}
		while ((i < j) && arr[i] < base)
		{
			i++;
		}
		if (i < j)
		{
			arr[j] = arr[i];
		}
	}
	arr[i] = base;
	return i;
	//arr[j] = base;
	//return j;
}
//改进1：优化代码

void fastSort2(int arr[], int left, int right)
{
	if (left < right)
	{
		int i = left;
		int j = right;
		int base = arr[i];
		while (i < j)
		{
			while ((i < j) && (arr[j] >= base))
			{
				j--;
			}
			if (i < j)
			{
				arr[i] = arr[j];
			}
			while ((i < j) && (arr[i] < base))
			{
				i++;
			}
			if (i < j)
			{
				arr[j] = arr[i];
			}
		}
		arr[i] = base;
		//arr[j] = base;
		fastSort2(arr, left, i - 1);
		fastSort2(arr, i + 1, right);
	}
}