#pragma once

/*
* 7、计算斐波拉契数列
* 考虑是采用递归或者循环，递归效率是否能真正最好
* 拓展1：青蛙跳阶梯，一只青蛙一次跳级可以跳1级阶梯，也可以跳2级阶梯，那么对于n级的阶梯，该青蛙可以有多少种跳法
* 拓展2：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法
* 分析：
*   假如有1级阶梯，显然只有一种跳法，即总数为f(1)=1
*	假如有2级阶梯，显然第一种可以跳1级，然后剩下1级；第二种为直接跳2级，总数法f(2)=2
*	假如有n级阶梯，第一种跳1级，剩下n-1级阶梯的为f(n-1)的跳法；
*				  第二种跳2级，剩下n-2阶梯的为f(n-2)的跳法，那么总数为f(n)=f(n-1)+f(n-2)
*/
#include <cmath>
namespace arthurlea
{
class Solution_07 
{
public:
	long long Fibonacci(int n) 
	{
		int arr[] = { 0,1 };
		if (n < 2)
		{
			return arr[n];
		}
		long long fibMinusOne = 0;
		long long fibMinusTwo = 1;
		long long fibN = 0;
		for (int i = 2; i <= n; ++i)
		{
			fibN = fibMinusOne + fibMinusTwo;
			fibMinusOne = fibMinusTwo;
			fibMinusTwo = fibN;
		}
		return fibN;
	}
	long long FibonacciForReverse(int n)
	{
		if (n <= 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return 1;
		}
		return FibonacciForReverse(n - 1) + FibonacciForReverse(n - 2);
	}
	//拓展1：青蛙跳台阶，只能跳1级和2级
	int jumpFloor(int number) 
	{
		int result[] = { 1, 2 };
		if (number <= 2)
		{
			return result[number - 1];
		}
		long long fMinusOne = 1;
		long long fMinusTwo = 2;
		long long fn = 0;
		for (int i = 3; i <= number; ++i)
		{
			fn = fMinusOne + fMinusTwo;
			fMinusOne = fMinusTwo;
			fMinusTwo = fn;
		}
		return fn;
	}
	//拓展2：青蛙变态跳台阶，n级阶梯有1,2,3...n种跳级方法
	/*
			1		  ,	n=1
	fn =  2		  ,	n=2
			2^(n-1) , n>2
	->fn = 2^(n-1)
	*/    
	int jumpFloorII(int number) 
	{
		long long fn = 1;
		for (int i = 1; i <= number-1; ++i)
		{
			fn *= 2;
		}
		return fn;
		
		//return pow(2, number - 1);
	}
};

}