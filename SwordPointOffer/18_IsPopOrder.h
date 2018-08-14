#pragma once
#pragma once

/*
* 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
* 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
* 序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
*（注意：这两个序列的长度是相等的）
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