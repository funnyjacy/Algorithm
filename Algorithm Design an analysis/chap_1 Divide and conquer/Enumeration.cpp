#define _CRT_SECURE_NO_WARNINGS 1
void enumeration(int arr[], int length, int &result, int &bestBeg, int &bestEnd)
{
	result = 0;
	for (int i = 0; i < length; i++) { // �������Ϊ�������
		int sum = 0;
		for (int j = i; j < length; j++) { // ����㿪ʼ����ۼ�
			sum += arr[j];
			if (sum > result) {
				result = sum;
				bestBeg = i;
				bestEnd = j;
			}
		}
	}
}