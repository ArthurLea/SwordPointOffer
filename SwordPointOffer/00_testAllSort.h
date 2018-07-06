#pragma once
namespace arthurlea //各大排序测试
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
	//排序测试
	void sortTest(const int numSize)
	{
		srand((unsigned int)time(0));
		int *arr = new int[SIZE];
		int *arrTmp = new int[SIZE];
		//数据准备
		for (int i = 0; i < numSize; i++)
		{
			arr[i] = rand();
			arrTmp[i] = arr[i];
		}
		setConsoleColor(CTC_RED);//设置字体颜色为红色
		cout << "数据量" << numSize << ",源数据为：" << endl;
		setConsoleColor(CTC_WHITE);//设置字体颜色为黑色
								   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
		cout << endl;

		clock_t timeStart, timeEnd;
		//冒泡排序
		{
			timeStart = clock();
			arthurlea_01::buddleSort(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//设置字体颜色为红色
			cout << "冒泡排序时间： " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//设置字体颜色为黑色
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //恢复数据测试其他sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//冒泡排序,改进1，加入一个标志
		{
			timeStart = clock();
			arthurlea_01::buddleSort2(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//设置字体颜色为红色
			cout << "冒泡排序2，改进1，加入一个标志，时间： " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//设置字体颜色为黑色
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; }); 
									   //cout << endl;
									   //恢复数据测试其他sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//冒泡排序,改进2，加入一个标志，顺便记录交换位置
		{
			timeStart = clock();
			arthurlea_01::buddleSort3(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//设置字体颜色为红色
			cout << "冒泡排序2，改进1，加入一个标志，时间： " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//设置字体颜色为黑色
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //恢复数据测试其他sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}

		//直接插入排序
		{
			timeStart = clock();
			arthurlea_02::directInsertSort(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//设置字体颜色为红色
			cout << "直接插入排序，时间： " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//设置字体颜色为黑色
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //恢复数据测试其他sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//直接插入排序,简单优化代码
		{
			timeStart = clock();
			arthurlea_02::directInsertSort2(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//设置字体颜色为红色
			cout << "直接插入排序，简单优化代码，时间： " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//设置字体颜色为黑色
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //恢复数据测试其他sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//直接插入排序,改进，使用swap代替移动
		{
			timeStart = clock();
			arthurlea_02::directInsertSort3(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//设置字体颜色为红色
			cout << "直接插入排序，改进，使用swap代替移动，时间： " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//设置字体颜色为黑色
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //恢复数据测试其他sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//希尔排序
		{
			timeStart = clock();
			arthurlea_03::shellSort(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//设置字体颜色为红色
			cout << "希尔排序，时间： " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//设置字体颜色为黑色
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //恢复数据测试其他sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//希尔排序，精简代码
		{
			timeStart = clock();
			arthurlea_03::shellSort(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//设置字体颜色为红色
			cout << "希尔排序，精简代码，时间： " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//设置字体颜色为黑色
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //恢复数据测试其他sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//希尔排序，使用swap代替移动
		{
			timeStart = clock();
			arthurlea_03::shellSort(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//设置字体颜色为红色
			cout << "希尔排序，使用swap代替移动，时间： " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//设置字体颜色为黑色
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //恢复数据测试其他sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//选择排序
		{
			timeStart = clock();
			arthurlea_04::selectSort(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//设置字体颜色为红色
			cout << "选择排序，时间： " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//设置字体颜色为黑色
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //恢复数据测试其他sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//归并排序
		{
			timeStart = clock();
			arthurlea_05::mergeSort(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//设置字体颜色为红色
			cout << "归并排序，时间： " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//设置字体颜色为黑色
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //恢复数据测试其他sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//快速排序
		{
			timeStart = clock();
			arthurlea_06::fastSort(arr, 0, numSize - 1);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//设置字体颜色为红色
			cout << "快速排序，时间： " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//设置字体颜色为黑色
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //恢复数据测试其他sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//快速排序，优化代码
		{
			timeStart = clock();
			arthurlea_06::fastSort2(arr, 0, numSize - 1);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//设置字体颜色为红色
			cout << "快速排序，优化代码，时间： " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//设置字体颜色为黑色
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //恢复数据测试其他sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}
		//堆排序
		{
			timeStart = clock();
			arthurlea_07::heapSortInit(arr, numSize);
			arthurlea_07::heapSort(arr, numSize);
			timeEnd = clock();
			setConsoleColor(CTC_RED);//设置字体颜色为红色
			cout << "堆排序，时间： " << timeEnd - timeStart << "ms" << endl; //
			setConsoleColor(CTC_WHITE);//设置字体颜色为黑色
									   //for_each(arr, arr + numSize, [](const int& data) { cout << setw(7) << data << " "; });
									   //cout << endl;
									   //恢复数据测试其他sort
			for (int i = 0; i < numSize; i++) arr[i] = arrTmp[i];
		}

		cout << endl;
		delete[] arr;
		delete[] arrTmp;
	}
	/*
	数据量1000,源数据为：

	冒泡排序时间： 2ms
	冒泡排序2，改进1，加入一个标志，时间： 25ms
	冒泡排序2，改进1，加入一个标志，时间： 1ms
	直接插入排序，时间： 1ms
	直接插入排序，简单优化代码，时间： 0ms
	直接插入排序，改进，使用swap代替移动，时间： 1ms
	希尔排序，时间： 0ms
	希尔排序，精简代码，时间： 0ms
	希尔排序，使用swap代替移动，时间： 0ms
	选择排序，时间： 2ms
	归并排序，时间： 0ms
	快速排序，时间： 1ms
	快速排序，优化代码，时间： 0ms
	堆排序，时间： 0ms

	数据量10000,源数据为：

	冒泡排序时间： 288ms
	冒泡排序2，改进1，加入一个标志，时间： 235ms
	冒泡排序2，改进1，加入一个标志，时间： 234ms
	直接插入排序，时间： 86ms
	直接插入排序，简单优化代码，时间： 34ms
	直接插入排序，改进，使用swap代替移动，时间： 64ms
	希尔排序，时间： 2ms
	希尔排序，精简代码，时间： 3ms
	希尔排序，使用swap代替移动，时间： 4ms
	选择排序，时间： 246ms
	归并排序，时间： 1ms
	快速排序，时间： 0ms
	快速排序，优化代码，时间： 2ms
	堆排序，时间： 76ms

	数据量100000,源数据为：

	冒泡排序时间： 17008ms
	冒泡排序2，改进1，加入一个标志，时间： 17134ms
	冒泡排序2，改进1，加入一个标志，时间： 17132ms
	直接插入排序，时间： 3745ms
	直接插入排序，简单优化代码，时间： 1889ms
	直接插入排序，改进，使用swap代替移动，时间： 4635ms
	希尔排序，时间： 14ms
	希尔排序，精简代码，时间： 13ms
	希尔排序，使用swap代替移动，时间： 14ms
	选择排序，时间： 16064ms
	归并排序，时间： 9ms
	快速排序，时间： 8ms
	快速排序，优化代码，时间： 7ms
	堆排序，时间： 6630ms
	*/
}