#define _CRT_SECURE_NO_WARNINGS 1
void enumeration(int arr[], int length, int &result, int &bestBeg, int &bestEnd)
{
	result = 0;
	for (int i = 0; i < length; i++) { // 最外层作为数组起点
		int sum = 0;
		for (int j = i; j < length; j++) { // 从起点开始逐次累加
			sum += arr[j];
			if (sum > result) {
				result = sum;
				bestBeg = i;
				bestEnd = j;
			}
		}
	}
}