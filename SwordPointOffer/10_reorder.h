#pragma once
/*
* 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的
* 后半部分
* 1、采用两个指针p1,p2，一个指针指向数组头，一个指针指向数组尾
* 2、p1<p2的前提下，p1一直向后遍历到偶数时停下来，p2一直向前遍历到奇数时停下来
* 3、交换p1,p2的值，如果p1<p2，则重复第二步
*
* 扩展1：如果改为非负数在负数的前面；或者能够被3整除的在不能被3整除的前面，应该怎么做
* 思路：其实大体框架逻辑一定，就只需要改变两处的判断逻辑即可，因此为了程序的扩展，我们需要将这部分判断抽取出来成一个函数即可
* 
* 扩展2：同时并保证奇数和奇数，偶数和偶数之间的相对位置不变。
* 思路1、开辟新的空间 存储所有偶数 同时原位置的偶数删掉 最后将偶数push到原数组 或者遍历两遍数组 依次存储所有奇数、所有偶数 最后将开辟数组赋值给原数组
* 思路2、类似buddle，前偶后奇就交换
*/
namespace arthurlea
{
#include<vector>
using namespace std;

class Solution_10
{
public:
	void reorderArray(int *pData, unsigned int length)
	{
		int* pBegin = pData;
		int* pEnd= pData + length - 1;
		while (pBegin < pEnd)
		{
			while ((pBegin < pEnd) && (*pBegin & 0x1 == 1)) //奇数，直到指向的是偶数
			{
				pBegin++;
			}
			while ((pBegin < pBegin) && (*pEnd & 0x1 == 0)) //偶数,直到指向的是奇数
			{
				pEnd--;
			}
			if (pBegin < pEnd)
			{
				int temp = *pBegin;
				*pBegin = *pEnd;
				*pEnd = temp;
			}
		}
	}
	void reOrder_Extend(int* pData, unsigned int length, bool (*Func)(int))
	{
		int* pBegin = pData;
		int* pEnd = pData + length - 1;
		while (pBegin < pEnd)
		{
			while ((pBegin < pEnd) && !Func(*pBegin))
			{
				++pBegin;
			}
			while ((pBegin < pEnd) && Func(*pEnd))
			{
				--pEnd;
			}
			if (pBegin < pEnd)
			{
				int temp = *pBegin;
				*pBegin = *pEnd;
				*pEnd = temp;
			}
		}
	}
	bool isEven(int data) //是否为偶数的判断函数
	{
		return (data & 0x1) == 0; //==0则为偶数，返回真
	}

	bool isNegative(int data) //是否为负数的判断函数
	{
		return data < 0; //为负就返回真
	}

	bool isExactDivisionBy3(int data) //是否被3整除的判断函数
	{
		return (data % 3) == 0; //能被3整除就返回真
	}

	//扩展2的解答
	void reOrderArray(vector<int> &array) {
		vector<int> arrayTemp;
		auto iteArr = array.begin();
		while (iteArr != array.end())
		{
			if (((*iteArr) & 0x1) == 0) //是偶数
			{
				arrayTemp.push_back(*iteArr);
				iteArr = array.erase(iteArr);//删除原数组的该偶数
			}
			else
			{
				++iteArr;
			}
		}
		for (auto data : arrayTemp)
		{
			array.push_back(data);
		}
		//另一种
		/*vector<int> result;
		int num = array.size();
		for (int i = 0; i<num; i++)
		{
			if (array[i] % 2 == 1)
				result.push_back(array[i]);
		}
		for (int i = 0; i<num; i++)
		{
			if (array[i] % 2 == 0)
				result.push_back(array[i]);
		}
		array = result;*/
	}
};

}