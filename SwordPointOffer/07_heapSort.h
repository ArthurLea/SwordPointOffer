#pragma once
/* 二叉堆
* 完全二叉树、近似完全二叉树（将其按照序号排序，如果序号同其构造为满二叉树的序号一致，则为完全二叉树；或者是其树的最深层次
*    叶子节点应该在最左边，同时其他叶子节点不存在单独的右节点）
* 二叉堆特点：
* 1、父节点的键值总是大于或者等于（小于或等于）它的任何一个子节点，分别叫最大堆、最小堆
* 2、它的左子树和右子树也是一个二叉堆
*/
// 序列：1 2 3 17 19 36 7 25 100就是一个最小堆，一共0...9个节点
/*
					 1
				   /   \
				  2     3
				 / \   / \
				17 19 36  7
			   / \
			 25  100
第i个节点的父节点：(i-1)/2
		  左节点：i*2+1
		  右节点：i*2+2
*/
namespace arthurlea_07
{
	inline void swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	/*
	1、最小堆的插入：每次都是先放在数组的最后位置，我们知道节点到他的父节点是有序的,通过父节点公式遍历它的父节点
					进行排序，相当于一次直接插入排序，我们称之为“树上插”
	*/
	//插入数组的第i个节点，那么此时它的父节点位置为(i-1)/2
	void headSortFixedUp(int arr[], int i)
	{
		int tmp = arr[i]; //该节点的值
		int parentIndex = (i - 1) / 2;
		while (parentIndex >= 0)
		{
			if (arr[parentIndex] <= tmp)
				break;
			arr[i] = arr[parentIndex];
			i = parentIndex;
			parentIndex = (i - 1) / 2;
		}
		arr[i] = tmp;
		//for (int parentIndex = (i - 1) / 2; (parentIndex >= 0) && (arr[parentIndex] > tmp); i = parentIndex, parentIndex = (i - 1) / 2)
		//	swap(arr[i], arr[parentIndex]);
	}
	//在最小堆中加入新的数据val
	void headSortInsert(int arr[], int n, int val)
	{
		arr[n] = val;
		headSortFixedUp(arr, n);
	}
	/* arr[0...n-1]
	2、最小堆的删除：只能删除根节点，然后对堆重新调整排序。即每次删除时，我们将删除节点放到序列最后位置，也就是同最后位置
		进行swap(arr[0],arr[n-1],接着我们利用节点寻找左右子节点的公式从根节点的左右子树寻找最小的同当前父节点比较，
		如果父节点较小，说明已经是最小堆，不需要调整了，否则继续利用公式继续向下寻找
	*/
	//从第i个节点开始调整，n为节点总数，从0开始计算，第i个节点的左右子节点位置分别为i*2+1，i*2+2
	void headSortFixedDown(int arr[], int i, int n)
	{
		int j = i * 2 + 1;
		int tmp = arr[i];
		while (j < n)
		{
			if ((j+1<n)&&(arr[j] > arr[j + 1]))
				j++;
			if (arr[j] >= tmp)
				break;
			arr[i] = arr[j];
			i = j;
			j = i * 2 + 1;
		}
		arr[i] = tmp;
	}
	void heapSortDelete(int arr[], int n) //每次删除一个节点放到序列的最后位置
	{
		swap(arr[0], arr[n - 1]);
		headSortFixedDown(arr, 0, n - 1);
	}

	/* 序列arr[0...n-1]，首先按照顺序存储方式得到其完全二叉树，
		   那么可以知道最后一个叶子节点a[n-1]的父节点位置为(n-1-1)/2 = n/2-1
	3、最小堆的建立（堆化序列）：将每一个可作为父节点的节点都做一次调整，按照最小堆的特性向下开始调整。因此我们需要找到
		  最后一个叶子节点的父节点，从这个节点开始向前索引，进行向下调整
	*/
	//n代表数组大小
	void heapSortInit(int arr[], int n)
	{
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			//headSortFixedDown(arr, i, n);
			int tmp = arr[i];						//代调整的数
			int j = i * 2 + 1;						// i节点的左节点位置
			while (j < n)							//直到遍历到序列的最后一个位置
			{
				if ((j+1<n)&&(arr[j] > arr[j + 1])) //找到i节点左右节点最小的那个数
					j++;
				if (arr[j] >= tmp)					// 左右节点如果都比i节点的键值大，那么就退出
					break;
				arr[i] = arr[j];					//小的话就将这个小的数复制到i节点
				i = j;								//找到比i节点小的位置，更新i节点，开始下面子节点的判断
				j = i * 2 + 1;						//更新j节点，找到i节点更新后的左子节点位置
			}
			arr[i] = tmp;							//将当前待调整的数放到找到的i节点位置
		}
	}

	/*
	* 4、堆排序：由于最小堆的特性，父节点的键值始终比左右节点的键值小，因此我们每次都取父节点，然后做向下的调整，因此每次取值
		相当于一次堆删除操作，然后最小的数放到了序列的最后位置
	*/
	void heapSort(int arr[], int n)
	{
		for (int i = n - 1; i > 0; i--)
		{
			swap(arr[0], arr[i]);
			headSortFixedDown(arr, 0, i);
		}
	}
}