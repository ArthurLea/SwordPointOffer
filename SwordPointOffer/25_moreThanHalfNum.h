#pragma once
#pragma once
/*
* ��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
* ��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬
* ������2
*/
#include <vector>
#include <set>
#include <iostream>
using namespace std;
namespace arthurlea
{
	class Solution_25
	{
		
	public:
		//�ⷨ1��ֱ�Ӷ���������Ȼ������λ����������������ΪO(nlogn),����ţ��鲢�ȣ�
		//��Ҫ�����ռ䣬�ı�������λ��
		
		//�ⷨ2�����ڿ���������partition������O(n)����Ϊ����֪����ÿ��partition�������᷵��
		//һ���±꣬���Ե�����±�Ϊ���ȵ�һ��ʱ�Ϳ���ֹͣpartition���õ���λ�����±꣬Ȼ��õ���ֵ
		// ���ǲ������ݴ���ʹ��ȫ�ֱ����ķ���֪ͨ��������Ϊ�գ�����<=0
		// �������������������,�ҵ������ֲ���������ĿҪ��
		bool g_bInput = true;
		
		int moreThanHalfNums(int* numbers, int length)
		{
			if (checkInvalidArray(numbers, length))
			{
				int middle = length / 2;
				int start = 0;
				int end = length - 1;
				int index = partition(numbers, start, end);
				while (index != middle)
				{
					if (index < middle)
					{
						start = index + 1;
						index = partition(numbers, start, end);
					}
					else //index > middle
					{
						end = index - 1;
						index = partition(numbers, start, end);
					}
				}
				if (checkMoreThanHalf(numbers, length, numbers[index]))
					return numbers[index];
			}
			else
				return -1; //δ�ҵ�����������
		}

		//���3 ���ı�����λ�õ�O(n)�㷨�����Ǽ�¼���ֳ��ֵĴ�����ÿ����һ���ľ�+1������͸���
		//��Ҫ�洢�����֣���-1��������ڳ���һ������������֣���ô���+1��һ�������������
		int moreThanHalfNums2(int* numbers, int length)
		{
			if (checkInvalidArray(numbers, length))
			{
				int middle = length / 2;
				int start = 0;
				int end = length - 1;
				int index = partition(numbers, start, end);
				while (index != middle)
				{
					if (index < middle)
					{
						start = index + 1;
						index = partition(numbers, start, end);
					}
					else //index > middle
					{
						end = index - 1;
						index = partition(numbers, start, end);
					}
				}
				if (checkMoreThanHalf(numbers, length, numbers[index]))
					return numbers[index];
			}
			else
				return -1; //δ�ҵ�����������
		}
	private:
		int partition(int* numbers, int start, int end)
		{
			int base = numbers[start];
			int i = start;
			int j = end;
			while(i < j)
			{
				while (i < j && base <= numbers[j])
					j--;
				if (i < j)
					numbers[i] = numbers[j];
				while (i < j && base >= numbers[i])
					i++;
				if (i < j)
					numbers[j] = numbers[i];
			}//�˳�while��i==j
			numbers[i] = base;
			int index = i;
			return index;
		}
		bool checkInvalidArray(int* numbers, int length)
		{
			g_bInput = true;
			if (numbers == nullptr || length <= 0)
			{
				g_bInput = false;
			}

			return g_bInput;
		}
		bool checkMoreThanHalf(int* numbers, int length, int number)
		{
			int times = 0;
			for (int i = 0; i<length; ++i)
			{
				if (numbers[i] == number)
					times++;
			}
			bool isMoreThanHalf = true;
			if (times * 2 <= length)
			{
				g_bInput = false;
				//isMoreThanHalf = false;
			}

			return isMoreThanHalf;
		}
	};
}