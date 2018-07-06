#pragma once
/*
* 5、利用两个栈实现队列的入队出队
* 相似：两个队列实现栈的入栈出栈
*/
namespace arthurlea
{

#include <stack>
using namespace std;

class Solution_05
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				int getTopFromStack1 = stack1.top();
				stack2.push(getTopFromStack1);
				stack1.pop();
			}
		}
		/*if(stack.empty())
		{
		throw exception("Invaild input");
		}*/
		int head = stack2.top();
		stack2.pop();
		return head;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

}