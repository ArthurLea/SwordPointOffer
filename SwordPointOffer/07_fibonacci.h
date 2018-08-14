#pragma once

/*
* 7������쳲���������
* �����ǲ��õݹ����ѭ�����ݹ�Ч���Ƿ����������
* ��չ1�����������ݣ�һֻ����һ������������1�����ݣ�Ҳ������2�����ݣ���ô����n���Ľ��ݣ������ܿ����ж���������
* ��չ2��һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж���������
* ������
*   ������1�����ݣ���Ȼֻ��һ��������������Ϊf(1)=1
*	������2�����ݣ���Ȼ��һ�ֿ�����1����Ȼ��ʣ��1�����ڶ���Ϊֱ����2����������f(2)=2
*	������n�����ݣ���һ����1����ʣ��n-1�����ݵ�Ϊf(n-1)��������
*				  �ڶ�����2����ʣ��n-2���ݵ�Ϊf(n-2)����������ô����Ϊf(n)=f(n-1)+f(n-2)
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
	//��չ1��������̨�ף�ֻ����1����2��
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
	//��չ2�����ܱ�̬��̨�ף�n��������1,2,3...n����������
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