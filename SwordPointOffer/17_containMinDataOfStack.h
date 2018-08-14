#pragma once

/*
* ����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
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