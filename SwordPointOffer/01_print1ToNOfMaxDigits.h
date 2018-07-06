#pragma once
/*
* ����һ������n����˳���ӡ��1�����nΪ��ʮ�������ݣ���������3�����ӡ1 2 3...999
* ��������
*/
namespace arthurleaother
{
	#include <cstring>
	#include <iostream>

	using namespace std;
	class Solution_01
	{
	public:
		void print1ToNOfMaxDigits(int n)
		{
			char *number = new char[n + 1];
			memset(number, 0, n);
			number[n] = '\0';
			//string str = number; //ʵ�ʵ��õ���string(const char *)���캯��
			while (!increasement(number))
			{
				printNumber(number);
				cout << " ";
			}
			delete[] number;
		}
	private:
		bool increasement(char* number)
		{
			bool isOverFlow = false;
			int carryOver = 0;
			int len = strlen(number);
			for (int i = len-1; i >= 0; --i)
			{
				int nSum = number[i] - '0' + carryOver;
				if (i == len - 1)
				{
					nSum++;
				}
				if (nSum >= 10)
				{
					if (i == 0)
					{
						isOverFlow = true;
					}
					else
					{
						nSum -= 10;
						carryOver = 1;
						number[i] = nSum + '0';
					}
				}
				else
				{
					number[i] = nSum + '0';
					carryOver = 0;
				}
			}
			return isOverFlow;
		}
		void printNumber(const char* number)
		{
			int len = strlen(number);
			bool isBeginer0 = true;
			for (int i = 0; i <= len; ++i)
			{
				if (isBeginer0 && (number[i] != '0'))
				{
					isBeginer0 = false;
				}
				if (!isBeginer0)
				{
					cout << number[i];
				}
			}
		}
	};
}