#pragma once
namespace arthurlea //�����������
{
#include <ctime>
#include <cstdlib>  //srand NULL

#include <Windows.h>

#include <iomanip>
#include <iostream>
	using namespace std;

#include "01_buddleSort.h"
#include "02_directInsertSort.h"
#include "03_shellSort.h"
#include "04_selectSort.h"
#include "05_mergeSort.h"
#include "06_fastSort.h"
#include "07_heapSort.h"

#define SIZE 2000000
	enum ConsoleTextColor {
		CTC_RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
		CTC_GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
		CTC_BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
		CTC_YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
		CTC_PURPLE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
		CTC_CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
		CTC_WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
		CTC_BLACK = 0
	};

	enum ConsoleBackGroundColor {
		CBC_RED = BACKGROUND_INTENSITY | BACKGROUND_RED,
		CBC_GREEN = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
		CBC_BLUE = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
		CBC_YELLOW = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
		CBC_PURPLE = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
		CBC_CYAN = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
		CBC_WHITE = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
		CBC_BLACK = 0
	};

	void setConsoleColor(ConsoleTextColor textColor = CTC_WHITE, ConsoleBackGroundColor backgroundColor = CBC_BLACK)
	{
		//STD_ERROR_HANDLE;
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, textColor | backgroundColor);
	}
	//�������
	void sortTest(const int numSize)
	{
		srand((unsigned int)time(0));
		int *arr = new int[SIZE];
		int *arrTmp = new int[SIZE];
		//����׼��
		for (int i = 0; i < numSize; i++)
		{
			arr[i] = rand();
			arrTmp[i] = arr[i];
		}
		setConsoleColor(CTC_RED);//����������ɫΪ��ɫ
		cout << "������" << numSize << ",Դ����Ϊ��" << endl;
		setConsoleColor(CTC_WHITE);//����������ɫΪ��ɫ
								   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
		cout << endl;

		clock_t timeStart, timeEnd;
		//ð������
		{
			timeStart = clock();
			arthurlea_01::buddleSort(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//����������ɫΪ��ɫ
			cout << "ð������ʱ�䣺 " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//����������ɫΪ��ɫ
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //�ָ����ݲ�������sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//ð������,�Ľ�1������һ����־
		{
			timeStart = clock();
			arthurlea_01::buddleSort2(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//����������ɫΪ��ɫ
			cout << "ð������2���Ľ�1������һ����־��ʱ�䣺 " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//����������ɫΪ��ɫ
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; }); 
									   //cout << endl;
									   //�ָ����ݲ�������sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//ð������,�Ľ�2������һ����־��˳���¼����λ��
		{
			timeStart = clock();
			arthurlea_01::buddleSort3(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//����������ɫΪ��ɫ
			cout << "ð������2���Ľ�1������һ����־��ʱ�䣺 " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//����������ɫΪ��ɫ
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //�ָ����ݲ�������sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}

		//ֱ�Ӳ�������
		{
			timeStart = clock();
			arthurlea_02::directInsertSort(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//����������ɫΪ��ɫ
			cout << "ֱ�Ӳ�������ʱ�䣺 " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//����������ɫΪ��ɫ
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //�ָ����ݲ�������sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//ֱ�Ӳ�������,���Ż�����
		{
			timeStart = clock();
			arthurlea_02::directInsertSort2(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//����������ɫΪ��ɫ
			cout << "ֱ�Ӳ������򣬼��Ż����룬ʱ�䣺 " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//����������ɫΪ��ɫ
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //�ָ����ݲ�������sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//ֱ�Ӳ�������,�Ľ���ʹ��swap�����ƶ�
		{
			timeStart = clock();
			arthurlea_02::directInsertSort3(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//����������ɫΪ��ɫ
			cout << "ֱ�Ӳ������򣬸Ľ���ʹ��swap�����ƶ���ʱ�䣺 " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//����������ɫΪ��ɫ
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //�ָ����ݲ�������sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//ϣ������
		{
			timeStart = clock();
			arthurlea_03::shellSort(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//����������ɫΪ��ɫ
			cout << "ϣ������ʱ�䣺 " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//����������ɫΪ��ɫ
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //�ָ����ݲ�������sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//ϣ�����򣬾������
		{
			timeStart = clock();
			arthurlea_03::shellSort(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//����������ɫΪ��ɫ
			cout << "ϣ�����򣬾�����룬ʱ�䣺 " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//����������ɫΪ��ɫ
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //�ָ����ݲ�������sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//ϣ������ʹ��swap�����ƶ�
		{
			timeStart = clock();
			arthurlea_03::shellSort(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//����������ɫΪ��ɫ
			cout << "ϣ������ʹ��swap�����ƶ���ʱ�䣺 " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//����������ɫΪ��ɫ
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //�ָ����ݲ�������sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//ѡ������
		{
			timeStart = clock();
			arthurlea_04::selectSort(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//����������ɫΪ��ɫ
			cout << "ѡ������ʱ�䣺 " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//����������ɫΪ��ɫ
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //�ָ����ݲ�������sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//�鲢����
		{
			timeStart = clock();
			arthurlea_05::mergeSort(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//����������ɫΪ��ɫ
			cout << "�鲢����ʱ�䣺 " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//����������ɫΪ��ɫ
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //�ָ����ݲ�������sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//��������
		{
			timeStart = clock();
			arthurlea_06::fastSort(arr, 0, numSize - 1);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//����������ɫΪ��ɫ
			cout << "��������ʱ�䣺 " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//����������ɫΪ��ɫ
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //�ָ����ݲ�������sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//���������Ż�����
		{
			timeStart = clock();
			arthurlea_06::fastSort2(arr, 0, numSize - 1);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//����������ɫΪ��ɫ
			cout << "���������Ż����룬ʱ�䣺 " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//����������ɫΪ��ɫ
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //�ָ����ݲ�������sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//������
		{
			timeStart = clock();
			arthurlea_07::heapSortInit(arr, numSize);
			arthurlea_07::heapSort(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//����������ɫΪ��ɫ
			cout << "������ʱ�䣺 " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//����������ɫΪ��ɫ
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //�ָ����ݲ�������sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}

		cout << endl;
		delete[] arr;
		delete[] arrTmp;
	}
	/*
	������1000,Դ����Ϊ��

	ð������ʱ�䣺 2ms
	ð������2���Ľ�1������һ����־��ʱ�䣺 25ms
	ð������2���Ľ�1������һ����־��ʱ�䣺 1ms
	ֱ�Ӳ�������ʱ�䣺 1ms
	ֱ�Ӳ������򣬼��Ż����룬ʱ�䣺 0ms
	ֱ�Ӳ������򣬸Ľ���ʹ��swap�����ƶ���ʱ�䣺 1ms
	ϣ������ʱ�䣺 0ms
	ϣ�����򣬾�����룬ʱ�䣺 0ms
	ϣ������ʹ��swap�����ƶ���ʱ�䣺 0ms
	ѡ������ʱ�䣺 2ms
	�鲢����ʱ�䣺 0ms
	��������ʱ�䣺 1ms
	���������Ż����룬ʱ�䣺 0ms
	������ʱ�䣺 0ms

	������10000,Դ����Ϊ��

	ð������ʱ�䣺 288ms
	ð������2���Ľ�1������һ����־��ʱ�䣺 235ms
	ð������2���Ľ�1������һ����־��ʱ�䣺 234ms
	ֱ�Ӳ�������ʱ�䣺 86ms
	ֱ�Ӳ������򣬼��Ż����룬ʱ�䣺 34ms
	ֱ�Ӳ������򣬸Ľ���ʹ��swap�����ƶ���ʱ�䣺 64ms
	ϣ������ʱ�䣺 2ms
	ϣ�����򣬾�����룬ʱ�䣺 3ms
	ϣ������ʹ��swap�����ƶ���ʱ�䣺 4ms
	ѡ������ʱ�䣺 246ms
	�鲢����ʱ�䣺 1ms
	��������ʱ�䣺 0ms
	���������Ż����룬ʱ�䣺 2ms
	������ʱ�䣺 76ms

	������100000,Դ����Ϊ��

	ð������ʱ�䣺 17008ms
	ð������2���Ľ�1������һ����־��ʱ�䣺 17134ms
	ð������2���Ľ�1������һ����־��ʱ�䣺 17132ms
	ֱ�Ӳ�������ʱ�䣺 3745ms
	ֱ�Ӳ������򣬼��Ż����룬ʱ�䣺 1889ms
	ֱ�Ӳ������򣬸Ľ���ʹ��swap�����ƶ���ʱ�䣺 4635ms
	ϣ������ʱ�䣺 14ms
	ϣ�����򣬾�����룬ʱ�䣺 13ms
	ϣ������ʹ��swap�����ƶ���ʱ�䣺 14ms
	ѡ������ʱ�䣺 16064ms
	�鲢����ʱ�䣺 9ms
	��������ʱ�䣺 8ms
	���������Ż����룬ʱ�䣺 7ms
	������ʱ�䣺 6630ms
	*/
}