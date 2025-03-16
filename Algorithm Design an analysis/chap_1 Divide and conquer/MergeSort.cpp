#define _CRT_SECURE_NO_WARNINGS 1
#include"MergeSort.h"

void Mergesort(int arr[], int s, int t) // 归并排序算法
{
	// 首先确定退出条件
	if (s == t) return;

	// 不退出就划分排序
	int m = (s + t) / 2;
	Mergesort(arr, s, m); // 排左边
	Mergesort(arr, m + 1, t); // 排右边
	Merge(arr, s, m, t); //合并

}

void Merge(int arr[], int s, int m, int t) // 合并算法
{
	// 用一个数组arr1临时存储再还给arr
	int arr1[MAX_LENGTH] = {0};
	int i = s;
	int j = m + 1;
	int k = s;
	// 改变里面的比较号就是升/降序
	while (i <= m && j <= t) {
		if (arr[i] < arr[j]) { // 升序排列
			arr1[k++] = arr[i];
			i++;
		}
		else {
			arr1[k++] = arr[j];
			j++;
		}
	}

	while (i <= m) {
		arr1[k++] = arr[i];
		i++;
	}
	while (j <= t) {
		arr1[k++] = arr[j];
		j++;
	}

	for (int i = s; i <= t; i++) {
		arr[i] = arr1[i];
	}
}