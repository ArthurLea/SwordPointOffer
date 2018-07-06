#pragma once

/* 2���滻�ո�
* ��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
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
		//1���ҵ��ո���
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

		/*���ڲ��Ե��ӵ�*/
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
