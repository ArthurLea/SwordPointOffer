#pragma once
/*
* ����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*/
namespace arthurlea
{

class Solution_08 {
public:
	//ע�⸺��
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
	//�����ٵĽⷨ
	int NumberOf1_And(int n)
	{
		int count = 0;
		while (n)
		{
			count++;
			n = n & (n - 1);//�����ұߵ�1��Ϊ0:��һ������ȥ1ͬ������&���㣬�൱�ڰ��ö����Ʊ�ʾ�����������ұߵ�1��Ϊ0
		}

		return count;
	}
};

}