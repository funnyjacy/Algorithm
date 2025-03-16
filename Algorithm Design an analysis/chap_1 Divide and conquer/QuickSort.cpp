#define _CRT_SECURE_NO_WARNINGS 1
#include"QuickSort.h"

void quickSort(int arr[], int i, int j) // ����������
{
	// ����д�ݹ���ֹ����
	if (i > j) return;

	// �ݹ��������
	int pivot = get_Pivot(arr, i, j); // ȡ��ת����±�
	quickSort(arr, i, pivot - 1); // ת���������
	quickSort(arr, pivot + 1, j); // ת���ұ�����
}

int get_Pivot(int arr[], int i, int j) // �õ�ת�㣨��ߵ���ȫС��pivot�ұߵ���ȫ����pivot��
{  
	// Ĭ��arr[0]Ϊת��

	// ��ֹ����
	while (i < j) {
		// �����ұߣ��ҵ���[k]С��Ȼ�󽻻�
		while (i < j && arr[i] <= arr[j]) j--;
		if (i < j) { // �ҵ����������С������Ž���
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++; // ԭkλ���Ѿ���С���ˣ�����һλ��ʼ�Ƚ�
		}

		// ������ߣ��ҵ���[j]��Ľ���
		while (i < j && arr[i] <= arr[j]) i++;
		if (i < j) { // �ҵ����������С������Ž���
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			j--;
		}
	}
	
	return i;
}