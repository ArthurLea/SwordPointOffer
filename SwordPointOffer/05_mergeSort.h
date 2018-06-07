#pragma once
/* ���η� 
* ������������кϲ����ԴﵽO(n)��Ч��
* ����˼�룺������������Ѿ����򣬺ϲ����ǿ��ԴﵽO(N)��Ч�ʣ���˲��ý�ԭ���зֽ�Ϊ������������е�˼�롣ʹ�õݹ�ֽ�
*    ֱ��ÿ������ֻʣһ��������ô��ʱ�������ڴ��ںϲ��Ĺ��̣���Ҫ����Ŀռ�O(N)
*/
namespace arthurlea_05
{
#include <cstdio>
	void mergeSort_step1_decompose(int arr[], int first, int last, int* pArr);
	void mergeSort_step2_merge(int arr[], int first, int mid, int last, int* pArr);

	bool mergeSort(int arr[], int N)
	{
		int* pArr = new int[N]();
		if (pArr == NULL) //�ռ�δ����ɹ�
			return false;
		mergeSort_step1_decompose(arr, 0, N-1, pArr);
		delete[] pArr;
	}

	void mergeSort_step1_decompose(int arr[], int first, int last, int* pArr)
	{
		int mid = (first + last) / 2;
		if (first < last)
		{
			mergeSort_step1_decompose(arr, first, mid, pArr); //�������
			mergeSort_step1_decompose(arr, mid + 1, last, pArr); //�ұ�����
			mergeSort_step2_merge(arr, first, mid, last, pArr); //�ϲ�������������
		}
	}
	//���ж�����������a[first...mid]��a[mid...last]�ϲ�
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