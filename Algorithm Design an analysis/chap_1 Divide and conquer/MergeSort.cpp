#define _CRT_SECURE_NO_WARNINGS 1
#include"MergeSort.h"

void Mergesort(int arr[], int s, int t) // �鲢�����㷨
{
	// ����ȷ���˳�����
	if (s == t) return;

	// ���˳��ͻ�������
	int m = (s + t) / 2;
	Mergesort(arr, s, m); // �����
	Mergesort(arr, m + 1, t); // ���ұ�
	Merge(arr, s, m, t); //�ϲ�

}

void Merge(int arr[], int s, int m, int t) // �ϲ��㷨
{
	// ��һ������arr1��ʱ�洢�ٻ���arr
	int arr1[MAX_LENGTH] = {0};
	int i = s;
	int j = m + 1;
	int k = s;
	// �ı�����ıȽϺž�����/����
	while (i <= m && j <= t) {
		if (arr[i] < arr[j]) { // ��������
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