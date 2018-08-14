#pragma once
#pragma once

/*
* ���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
* ����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳��
* ����4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
*��ע�⣺���������еĳ�������ȵģ�
*/
#include <vector>
#include <stack>
using namespace std;
namespace arthurlea
{

	class Solution_18
	{
	public:
		bool IsPopOrder(vector<int> pushV, vector<int> popV) {
			bool bPossible = false;
			if (!pushV.empty() && !popV.empty())
			{
				//int lenPushV = pushV.size();
				//int lenPopV = popV.size();
				int indexPushV = 0;
				int indexPopV = 0;
				stack<int> data;
				for(; indexPopV < popV.size(); ++indexPopV)
				{
					while (data.empty() || data.top() != popV[indexPopV])
					{
						data.push(pushV[indexPushV]);
						indexPushV++;
						if (indexPushV >= pushV.size())
							break;
					}
					if (data.top() != popV[indexPopV])
						break;

					data.pop();
				}
				if (data.empty() && indexPopV==popV.size())
				{
					bPossible = true;
				}
			}
			return bPossible;
		}
	};
}