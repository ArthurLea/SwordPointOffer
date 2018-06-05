#pragma once
/*
* ����˼�룺��ĳ�������뵽�Ѿ�����ŵ�������
* 1������a[0]Ĭ����������a[1...n-1],��i=1
* 2����a[i]���뵽�б�a[0...i-1]�У��γ�a[0...i]�����б�
* 3��i++�ظ��ڶ���ֱ��i=n-1
*/
//�鱾Դ����
void directInsertSort(int arr[], int N)
{
	for (int i = 1; i < N; i++) //��ǰ��Ҫ��������±�
	{
		int j = 0;
		for (j = i-1; j >= 0; j++)
		{
			if (arr[i] < arr[j]) //�ҵ���Ҫ�����λ��j,����Ӧ�ò嵽j+1
			{
				break;
			}
		}
		int temp = arr[i];
		for (int k = i - 1; k >= j; k--) //�ƶ�
		{
			arr[k + 1] = arr[k];
		}
		arr[j+1] = temp; //��������
	}
}

//�Ľ�����1���Ż�
void directInsertSort2(int arr[], int N)
{
	for (int i = 1; i < N; i++)
	{
		int temp = arr[i]; //�����������
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
//�Ľ�2��ʹ�����ݽ��������������ƶ�
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
