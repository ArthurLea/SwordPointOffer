#pragma once
/*
* 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/
namespace arthurlea
{

class Solution_08 {
public:
	//注意负数
	int NumberOf1(int n)
	{
		int count = 0;
		unsigned int flag = 1;
		while (flag)
		{
			if (n & flag)
			{
				count++;
			}
			flag = flag << 1;
		}

		return count;
	}
	//更快速的解法
	int NumberOf1_And(int n)
	{
		int count = 0;
		while (n)
		{
			count++;
			n = n & (n - 1);//把最右边的1变为0:将一个数减去1同自身做&运算，相当于把用二进制表示的自身中最右边的1变为0
		}

		return count;
	}
};

}