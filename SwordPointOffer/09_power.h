#pragma once
/*
* 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
* 注意：1、底数为0和指数为负数的情况
* 2、double小数类型为0时的判断
*/
namespace arthurlea
{

class Solution_09
{
public:
	bool isInvaildInput = false;
	double Power(double base, int exponent)
	{
		if (equal(base, 0.0) && (exponent < 0)) //0的任何正次方都没有意义
		{
			isInvaildInput = true;
			return 0.0;
		}
		unsigned int absExponent = (unsigned int)(exponent);
		if (exponent < 0)
		{
			absExponent = (unsigned int)(-exponent);
		}
		double result = PowerWithUnsignedExponent(base, absExponent); 
		//double result = PowerWithUnsignedExponent_Reverse(base, absExponent);
		if (exponent < 0)
		{
			result = 1 / result;
		}

		return result;
	}
private:
	bool equal(double num1, double num2)
	{
		if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	double PowerWithUnsignedExponent(double base, int absExponent)
	{
		double result = 1.0;
		for (int i = 1; i <= absExponent; i++)
		{
			result *= base;
		}

		return result;
	}
	double PowerWithUnsignedExponent_Reverse(double base, int absExponent) //更快的乘方算法
	{
		if (absExponent == 0)
		{
			return 1;
		}
		if (absExponent == 1)
		{
			return base;
		}
		double result = PowerWithUnsignedExponent_Reverse(base, absExponent >> 1);
		result *= result;
		if ((absExponent & 0x1) == 1) //指数为奇数
		{
			result *= base;
		}

		return result;
	}
};

}