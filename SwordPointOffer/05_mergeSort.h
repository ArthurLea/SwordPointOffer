#pragma once
/* 分治法 
* 有序的两个序列合并可以达到O(n)的效率
* 基本思想：如果两个序列已经有序，合并他们可以达到O(N)的效率，因此采用将原序列分解为两个有序的序列的思想。使用递归分解
*    直到每个序列只剩一个数，那么此时有序，由于存在合并的过程，需要额外的空间O(N)
*/
namespace arthurlea_05
{
#include <cstdio>
	void mergeSort_step1_decompose(int arr[], int first, int last, int* pArr);
	void mergeSort_step2_merge(int arr[], int first, int mid, int last, int* pArr);

	bool mergeSort(int arr[], int N)
	{
		int* pArr = new int[N]();
		if (pArr == NULL) //空间未分配成功
			return false;
		mergeSort_step1_decompose(arr, 0, N-1, pArr);
		delete[] pArr;
	}

	void mergeSort_step1_decompose(int arr[], int first, int last, int* pArr)
	{
		int mid = (first + last) / 2;
		if (first < last)
		{
			mergeSort_step1_decompose(arr, first, mid, pArr); //左边有序
			mergeSort_step1_decompose(arr, mid + 1, last, pArr); //右边有序
			mergeSort_step2_merge(arr, first, mid, last, pArr); //合并两个有序序列
		}
	}
	//将有二个有序数列a[first...mid]和a[mid...last]合并
	void mergeSort_step2_merge(int arr[], int first, int mid, int last, int* pArr)
	{
		int i = first;
		int j = mid+1;
		int k = 0;
		int m = mid;
		int n = last;
		while ((i <= m) && (j <= n))
		{
			if (arr[i] < arr[j])
				pArr[k++] = arr[i++];
			else
				pArr[k++] = arr[j++];
		}
		while (i <= m)
		{
			pArr[k++] = arr[i++];
		}
		while (j <= n)
		{
			pArr[k++] = arr[j++];
		}
		for (int i = 0; i < k; i++)
		{
			arr[first + i] = pArr[i];
		}
	}
}