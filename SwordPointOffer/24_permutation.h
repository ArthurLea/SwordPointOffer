#pragma once
/*
* 字符串的全排列
* 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,
* 则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
* 注意：输入的字符串中可能有重复字符
*/
#include <vector>
#include <set>
#include <iostream>
using namespace std;
namespace arthurlea
{
	class Solution_24
	{
	/*public:
		int permutation(char* pStr)
		{
			count = 0;
			if (pStr == nullptr) return 0;
			return permutation(pStr, pStr);
		}
	private:
		int count = 0;
		int permutation(char* pStr, char* pBegin)
		{
			if (*pBegin == '\0')
			{
				count++;
				cout << pStr << endl;
			}
			else
			{
				for (char* pCh = pBegin; *pCh != '\0'; pCh++)
				{
					char temp = *pCh;
					*pCh = *pBegin;
					*pBegin = temp;
					count = permutation(pStr, pBegin + 1);

					temp = *pCh;
					*pCh = *pBegin;
					*pBegin = temp;
				}
			}
			return count;
		}*/
	public:
		vector<string> Permutation(string str) {
			if (str.size() != 0)
			{
				int nSize = str.size();
				Permutation(str, nSize, 0);
			}
			//for (set<string>::iterator iter = permutationSet.begin(); iter != permutationSet.end(); ++iter)
			for(auto iter : permutationSet)
			{
				permutation.push_back(iter);
			}
			return permutation;
		}

		void Permutation(string str, int nSize, int n)
		{
			if (n == str.size())
			{
				permutationSet.insert(str);
			}

			else
			{
				for (int i = n + 1; i < str.size(); ++i)
				{
					if (str[n] != str[i])
					{
						char tmp = str[n];
						str[n] = str[i];
						str[i] = tmp;

						Permutation(str, nSize, n + 1);

						tmp = str[n];
						str[n] = str[i];
						str[i] = tmp;
					}
				}
			}
		}
	private:
		vector<string> permutation;
		set<string> permutationSet; //保证不重复
	};
}