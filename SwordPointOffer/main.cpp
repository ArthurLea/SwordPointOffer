namespace arthurlea
{

#include <cstring>
#include <cstdlib>

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

#include "00_testAllSort.h"

#include "01_findInPartiallySortedMatrix.h"
#include "02_replaceBlank.h"
#include "03_printListFromTailToHead.h"
#include "04_reConstructBinaryTree.h"
#include "05_twoStackAsQueue.h"
#include "06_minNumberInRotateArray.h"
#include "07_fibonacci.h"
#include "08_numberOf1.h"
#include "09_power.h"
//#include <cstdlib> //srand NULL
#include <ctime>
void _01_test()
{
	vector<vector<int> > array;
	const int rows = 7;
	const int columns = 7;
	int data[rows][columns] = {
		1,2,3,4,5,6,7,
		2,4,5,6,7,9,10,
		4,6,7,9,10,12,11,
		6,7,8,10,11,13,14,
		7,8,9,11,12,14,15,
		9,10,12,13,14,15,17,
		10,11,13,15,16,18,20
	};

	for (auto i = 0; i < rows; i++)
	{
		vector<int> v;
		for (int j = 0; j < columns; j++)
		{
			v.push_back(data[i][j]);
		}
		array.push_back(v);
	}
	for (auto i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << setiosflags(ios::left) << setw(5) << array[i][j] << " ";
		}
		cout << endl;
	}
	arthurlea::Solution_01 solution;
	solution.find(13, array);
	cout << "find 13 in array[" << solution.getResultIndex().row << "," << solution.getResultIndex().column << "]" << endl;
}

#pragma warning(disable:4996)
void _02_test()
{
	string str = "we are happy";
	cout << "Source str:" << str << endl;
	arthurlea::Solution_02 solution;
	char* ch = new char[1024];
	strcpy(ch, str.c_str());
	solution.replaceSpace(ch, 1024);
	cout << "Destination str:" << solution.getResultData().str << endl;
}
void _03_test()
{
	arthurlea::ListNode* node = new arthurlea::ListNode(1);
	arthurlea::ListNode* node2 = new arthurlea::ListNode(2);
	arthurlea::ListNode* node3 = new arthurlea::ListNode(3);
	arthurlea::ListNode* node4 = new arthurlea::ListNode(4);
	arthurlea::ListNode* node5 = new arthurlea::ListNode(5);
	node->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	arthurlea::Solution_03 solution;
	vector<int> v = solution.printListFromTailToHead(node);
	for_each(v.begin(), v.end(), [](const int& data) { cout << data << " "; });
	cout << endl;
	vector<int> v2 = solution.printListFromTailToHead_Reversingly(node);
	for_each(v2.begin(), v2.end(), [](const int& data) { cout << data << " "; });
	delete node;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
}
void _04_test()
{
	int preArr[] = { 1,2,4,7,3,5,6,8 };
	int vinArr[] = { 4,7,2,1,5,3,8,6 };
	vector<int> pre;
	vector<int> vin;
	for (int i = 0; i < 8; i++)
	{
		pre.push_back(preArr[i]);
		vin.push_back(vinArr[i]);
	}
	arthurlea::Solution_04 solution;
	arthurlea::TreeNode* root = solution.reConstructBinaryTree(pre, vin);
}
void _06_test()
{
	//int arr[] = { 5,6,7,1,2,3,4 };
	int arr[] = { 1,1,1,0,1,1,1 };
	vector<int> rotateArray;
	for (int i = 0; i < 7; i++)
	{
		rotateArray.push_back(arr[i]);
	}
	arthurlea::Solution_06 solution;
	int min = solution.minNumberInRotateArray(rotateArray);
	cout << min << endl;
}
void _07_test()
{
	cout << "sizeof(int)=" << sizeof(int) << endl;
	cout << "<< sizeof(long)=" << sizeof(long) << endl;
	cout << "sizeof(long long)=" << sizeof(long long) << endl;
	cout << "sizeof(double)=" << sizeof(double) << endl;
	cout << "sizeof(float)=" << sizeof(float) << endl;
	arthurlea::Solution_07 solution;
	clock_t timeStart = clock();
	long long fibonacci100 = solution.Fibonacci(100);
	cout << "use cycle for to calculate fibonacci spend time is " << clock() - timeStart << "ms, fibonacci100 = " << fibonacci100 << endl;
	cout << solution.jumpFloorII(1) << endl;
	cout << solution.jumpFloorII(2) << endl;
	cout << solution.jumpFloorII(3) << endl;
	cout << solution.jumpFloorII(4) << endl;
	cout << solution.jumpFloorII(5) << endl;
	cout << solution.jumpFloorII(6) << endl;
	timeStart = clock();
	fibonacci100 = solution.FibonacciForReverse(100);
	cout << "use reverse for to calculate fibonacci spend time is " << clock() - timeStart << "ms, fibonacci100 = " << fibonacci100 << endl;

}
void _08_test()
{
	arthurlea::Solution_08 solution;
	cout << solution.NumberOf1(1) << endl;
	cout << solution.NumberOf1(2) << endl;
	cout << solution.NumberOf1(3) << endl;
	cout << solution.NumberOf1(4) << endl;
	cout << solution.NumberOf1(10) << endl;
	cout << solution.NumberOf1(15) << endl;
	cout << solution.NumberOf1(-15) << endl;

	cout << solution.NumberOf1_And(1) << endl;
	cout << solution.NumberOf1_And(2) << endl;
	cout << solution.NumberOf1_And(3) << endl;
	cout << solution.NumberOf1_And(4) << endl;
	cout << solution.NumberOf1_And(10) << endl;
	cout << solution.NumberOf1_And(15) << endl;
	cout << solution.NumberOf1_And(-15) << endl;
}
void _09_test()
{
	arthurlea::Solution_09 solution;
	cout << solution.Power(0, -1) << endl;
	cout << solution.Power(0, 0) << endl;
	cout << solution.Power(0, 1) << endl;
	cout << solution.Power(2.0, 4) << endl;
	cout << solution.Power(2.0, -4) << endl;
	cout << solution.Power(2.0, 99) << endl;
	cout << solution.Power(2.0, 100) << endl;
	cout << solution.Power(2.0, -99) << endl;
	cout << solution.Power(2.0,-100) << endl;
}

}
int main(int argc, char* argv[])
{	
	//arthurlea::sortTest(1000);
	//arthurlea::sortTest(10000);
	//arthurlea::sortTest(100000);

	//arthurlea::_01_test();
	//arthurlea::_02_test();
	//arthurlea::_03_test();
	//arthurlea::_04_test();

	//arthurlea::_06_test();
	//arthurlea::_07_test();
	//arthurlea::_08_test();
	arthurlea::_09_test();

	system("pause");
	return 0;
}