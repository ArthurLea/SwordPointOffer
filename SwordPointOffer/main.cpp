#include <cstring>

#include <vector>
#include <string>
#include <algorithm>

#include <iostream>
#include <iomanip>
using namespace std;

#include "01_findInPartiallySortedMatrix.h"
#include "02_replaceBlank.h"
#include "03_printListFromTailToHead.h"
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
	ArthurLea::Solution_01 solution;
	solution.find(13, array);
	cout << "find 13 in array[" << solution.getResultIndex().row << "," << solution.getResultIndex().column << "]" << endl;
}

#pragma warning(disable:4996)
void _02_test()
{
	string str = "we are happy";
	cout << "Source str:" << str << endl;
	ArthurLea::Solution_02 solution;
	char* ch = new char[1024];
	strcpy(ch,str.c_str());
	solution.replaceSpace(ch,1024);
	cout << "Destination str:" << solution.getResultData().str << endl;
}
void _03_test()
{
	ArthureLea::ListNode* node = new ArthureLea::ListNode(1);
	ArthureLea::ListNode* node2 = new ArthureLea::ListNode(2);
	ArthureLea::ListNode* node3 = new ArthureLea::ListNode(3);
	ArthureLea::ListNode* node4 = new ArthureLea::ListNode(4);
	ArthureLea::ListNode* node5 = new ArthureLea::ListNode(5);
	node->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	ArthureLea::Solution_03 solution;
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
int main(int argc, char* argv[])
{
	//_01_test();
	//_02_test();
	//_03_test();
	system("pause");
	return 0;
}