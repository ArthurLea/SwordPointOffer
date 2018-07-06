#pragma once
/*
* ����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ�������
* ��벿��
* 1����������ָ��p1,p2��һ��ָ��ָ������ͷ��һ��ָ��ָ������β
* 2��p1<p2��ǰ���£�p1һֱ��������ż��ʱͣ������p2һֱ��ǰ����������ʱͣ����
* 3������p1,p2��ֵ�����p1<p2�����ظ��ڶ���
*
* ��չ1�������Ϊ�Ǹ����ڸ�����ǰ�棻�����ܹ���3�������ڲ��ܱ�3������ǰ�棬Ӧ����ô��
* ˼·����ʵ�������߼�һ������ֻ��Ҫ�ı��������ж��߼����ɣ����Ϊ�˳������չ��������Ҫ���ⲿ���жϳ�ȡ������һ����������
* 
* ��չ2��ͬʱ����֤������������ż����ż��֮������λ�ò��䡣
* ˼·1�������µĿռ� �洢����ż�� ͬʱԭλ�õ�ż��ɾ�� ���ż��push��ԭ���� ���߱����������� ���δ洢��������������ż�� ��󽫿������鸳ֵ��ԭ����
* ˼·2������buddle��ǰż����ͽ���
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
			while ((pBegin < pEnd) && (*pBegin & 0x1 == 1)) //������ֱ��ָ�����ż��
			{
				pBegin++;
			}
			while ((pBegin < pBegin) && (*pEnd & 0x1 == 0)) //ż��,ֱ��ָ���������
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
	bool isEven(int data) //�Ƿ�Ϊż�����жϺ���
	{
		return (data & 0x1) == 0; //==0��Ϊż����������
	}

	bool isNegative(int data) //�Ƿ�Ϊ�������жϺ���
	{
		return data < 0; //Ϊ���ͷ�����
	}

	bool isExactDivisionBy3(int data) //�Ƿ�3�������жϺ���
	{
		return (data % 3) == 0; //�ܱ�3�����ͷ�����
	}

	//��չ2�Ľ��
	void reOrderArray(vector<int> &array) {
		vector<int> arrayTemp;
		auto iteArr = array.begin();
		while (iteArr != array.end())
		{
			if (((*iteArr) & 0x1) == 0) //��ż��
			{
				arrayTemp.push_back(*iteArr);
				iteArr = array.erase(iteArr);//ɾ��ԭ����ĸ�ż��
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
		//��һ��
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