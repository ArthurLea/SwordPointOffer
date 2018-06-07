#pragma once
/*
* �����������ֱ�Ӳ����������������л������������£�ֱ�Ӳ�������Ч�ʺܸߵ��ص�
* 1��gap=N/2������Ϊ0->gap��
* 2���������Ԫ��,��ÿ����в�������
* 3��gap=gap/2�����gap��Ϊ0���ظ��ڶ��������ǳ�֮Ϊ�����Ų塱
*/
/* 
* ϣ�������ǻ��ڲ�������������������ʶ�����Ľ������ģ�
*  ~���������ڶԼ����Ѿ��ź�������ݲ���ʱ��Ч�ʸߣ������Դﵽ���������Ч��
*  ~����������һ����˵�ǵ�Ч�ģ���Ϊ��������ÿ��ֻ�ܽ������ƶ�һλ
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

	//�Ľ�1���������
	// ������ÿ���飬���ô�gap��ʼѭ�򽥽���ʽ������ֱ�Ӳ�������
	void shellSort2(int arr[], int N)
	{
		for (int gap = N / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < N; i++)
			{
				int tmp = arr[i]; //��ǰ��Ҫ���������
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
	//�Ľ�2����һ��������swap�����ֵ�����Ծ������
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