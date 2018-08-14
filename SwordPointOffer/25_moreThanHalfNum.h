#pragma once
#pragma once
/*
* 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
* 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，
* 因此输出2
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
		//解法1，直接对数组排序，然后获得中位数就是这个数，最快为O(nlogn),如快排，归并等，
		//还要辅助空间，改变了数组位置
		
		//解法2，基于快速排序中partition函数的O(n)，因为我们知道，每次partition函数都会返回
		//一个下标，所以当这个下标为长度的一半时就可以停止partition，得到中位数的下标，然后得到该值
		// 考虑参数传递错误，使用全局变量的方法通知，如数组为空，长度<=0
		// 考虑数组内容输入错误,找到的数字并不满足题目要求
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
				return -1; //未找到，输入有误
		}

		//解答3 不改变数组位置的O(n)算法，我们记录数字出现的次数，每出现一样的就+1，否则就更新
		//需要存储的数字，并-1，如果存在超过一半的这样的数字，那么最后+1的一定就是这个数字
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
				return -1; //未找到，输入有误
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
			}//退出while后i==j
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