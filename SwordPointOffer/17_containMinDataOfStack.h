#pragma once

/*
* 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/
#include <cassert>
#include <stack>
using namespace std;
namespace arthurlea
{
	class Solution_17
	{
	public:
		void push(int val) {
			st.push(val);
			if (minSt.size() == 0 || val < minSt.top())
			{
				minSt.push(val);
			}
			else
			{
				int min = minSt.top();
				minSt.push(min);
			}
		}
		void pop() {
			//assert(st.size() > 0 && minSt.size() > 0);
			//if(st.top() == minSt.top())
			minSt.pop();

			st.pop();
			/*if (st.empty())
			{
			while (!minSt.empty())
			{
			minSt.pop();
			}
			}*/
		}
		int top() {
			//assert(st.size() > 0 && minSt.size() > 0);
			return st.top();
		}
		int min() {
			//assert(st.size() > 0 && minSt.size() > 0);
			return minSt.top();
		}
	private:
		stack<int> st;
		stack<int> minSt;
	};
}