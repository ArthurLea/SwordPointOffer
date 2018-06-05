#pragma once
/* ���η� ������arr[0...N-1]
* ����˼�룺������һ����׼base���������б�base��ķŵ��ұߣ���baseС�ķŵ���ߣ�
*    Ȼ���¼��base��λ�ã����������߲���ͬ���ķ������ܶ�ʱ���Ե�һ��λ����Ϊbase����λ��indexΪ0
* 1��i=l,j=r,��i��Ϊ��׼base��λ�ã����ȴ�j��ʼ��ǰ������j--�����ҵ���baseС�ģ�Ȼ��a[i] = a[j]
* 2����i��ʼ����������i++)���ҵ���base�������Ȼ��a[i] = a[j]
* 3�����i<j���ظ�1��2���裬����ʱi==j
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
//�Ľ�1���Ż�����

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