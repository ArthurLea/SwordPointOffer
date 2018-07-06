#pragma once

/* 2、替换空格
* 请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
namespace arthurlea
{	

/*typedef */struct ResultData
{
	char* str;
	int numsOfBlank;
	int lengthOfOringin;
	int lengthOfFinal;
}/*Data*/;

class Solution_02 
{
public:

	void replaceSpace(char *str, int length) {
		//1、找到空格数
		int numsOfBlank = 0;
		int lengthOfOrigin = 0;
		int i = 0;
		while (str[i] != '\0')
		{
			++lengthOfOrigin;
			if (str[i] == ' ')
			{
				++numsOfBlank;
			}
			++i;
		}
		int lengthOfFinal = lengthOfOrigin + 2 * numsOfBlank;
		if (lengthOfFinal > length)
		{
			return;
		}
		int indexOfOrigin = lengthOfOrigin;
		int indexOfFinal = lengthOfFinal;
		while (indexOfFinal > indexOfOrigin)
		{
			if (str[indexOfOrigin] != ' ')
			{
				str[indexOfFinal--] = str[indexOfOrigin];
			}
			else
			{
				str[indexOfFinal--] = '0';
				str[indexOfFinal--] = '2';
				str[indexOfFinal--] = '%';
			}
			--indexOfOrigin;
		}

		/*用于测试叠加的*/
		m_data.str = str;
		m_data.numsOfBlank = numsOfBlank;
		m_data.lengthOfOringin = lengthOfOrigin;
		m_data.lengthOfFinal = lengthOfFinal;
		/**/
	}
	inline ResultData getResultData() const { return m_data; }
private:
	ResultData m_data;
};

}
