#define _CRT_SECURE_NO_WARNINGS 1
#include"QuickSort.h"

void quickSort(int arr[], int i, int j) // 对数组排序
{
	// 首先写递归终止条件
	if (i > j) return;

	// 递归调用自身
	int pivot = get_Pivot(arr, i, j); // 取得转点的下标
	quickSort(arr, i, pivot - 1); // 转点左边排序
	quickSort(arr, pivot + 1, j); // 转点右边排序
}

int get_Pivot(int arr[], int i, int j) // 得到转点（左边的数全小于pivot右边的数全大于pivot）
{  
	// 默认arr[0]为转点

	// 终止条件
	while (i < j) {
		// 遍历右边，找到比[k]小的然后交换
		while (i < j && arr[i] <= arr[j]) j--;
		if (i < j) { // 找到且左边坐标小的情况才交换
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++; // 原k位置已经是小的了，从下一位开始比较
		}

		// 遍历左边，找到比[j]大的交换
		while (i < j && arr[i] <= arr[j]) i++;
		if (i < j) { // 找到且左边坐标小的情况才交换
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			j--;
		}
	}
	
	return i;
}