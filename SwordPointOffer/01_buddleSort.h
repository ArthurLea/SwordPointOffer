#pragma once
/* ��С��������
* δ��������鳤��ΪN
* 1���Ƚ�����ǰ�������Ԫ��[j-1],[j]�����ǰ��Ԫ�ش��ں����Ԫ�ؾͽ�������Ԫ��
* 2������һ�˺���������ͨ��ð�ݵķ�ʽ�ŵ��ˡ�N-1����λ��
* 3��N=N-1,���N!=0���ظ�ǰ����
*/
namespace arthurlea_01
{
	inline void swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	//1���������
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
	//�Ľ�1����һ����־flag�������һ�˱ȽϹ�����δ����һ�ν�����˵���Ѿ������
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
	//�Ľ�2�����ͱȽϴ����������100���������飬ǰ10�������򣬺�90���Ѿ�������ô�ڱȽ�
	//����������λ��һ����10֮ǰ����Ϊ�������򲻻ᷢ����������ʱ���Լ�¼���λ�ã�Ȼ����Ϊ
	//�´α������յ�
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