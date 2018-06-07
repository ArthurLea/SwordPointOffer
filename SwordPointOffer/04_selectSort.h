#pragma once
/*
* ����˼��:ֱͬ�Ӳ����������ƣ�ֻ������������ÿ���ǽ�һ�����������źõ���������ɸ��������
*     ��ѡ������ÿ���Ǵ�ʣ��������ѡ��һ����С��ͬǰ�����ź���ĺ�һ�������н�������ɸ��������
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