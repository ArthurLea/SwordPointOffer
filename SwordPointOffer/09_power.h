#pragma once
/*
* ����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
* ע�⣺1������Ϊ0��ָ��Ϊ���������
* 2��doubleС������Ϊ0ʱ���ж�
*/
namespace arthurlea
{

class Solution_09
{
public:
	bool isInvaildInput = false;
	double Power(double base, int exponent)
	{
		if (equal(base, 0.0) && (exponent < 0)) //0���κ����η���û������
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
	double PowerWithUnsignedExponent_Reverse(double base, int absExponent) //����ĳ˷��㷨
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
		if ((absExponent & 0x1) == 1) //ָ��Ϊ����
		{
			result *= base;
		}

		return result;
	}
};

}