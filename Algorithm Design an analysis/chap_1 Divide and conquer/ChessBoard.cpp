#define _CRT_SECURE_NO_WARNINGS 1
#include"ChessBoard.h"
#include<iostream>
using namespace std;
// tr���ϵ�row��tc���ϵ�col��dr��ǵ�row��dc��ǵ�col��size�߳�
void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
	// ����д�ݹ�Ľ�������
	if (size == 1) return; // ���size��1��ôֱ�ӷ���

	// ����һ��Ӧ���ȼ�¼����(������)
	int t1 = ++t;  

	size = size / 2;
	if (dr < tr + size && dc < tc + size) { // ��ǵ��Ƿ��ڵڶ�������
		ChessBoard(tr, tc, dr, dc, size); // ����ڱ��ڵ㣬��ôԭ���ޱ���
	}
	else {
		board[tr + size - 1][tc + size - 1] = t1; // ���ڵĻ����½Ǳ�� // һ��Ҫ�������λ��tr��tc!!!
		ChessBoard(tr, tc, tr + size - 1, tc + size - 1, size); // ȫ����Ҫ����λ�ư�����
	}

	if (dr < tr + size && dc >= tc + size) { // ��ǵ��Ƿ��ڵ�һ������
		ChessBoard(tr, tc + size, dr, dc, size); // ��ǵ��ڵĻ��ǲ��øı�ǵ�λ�õ�
	}
	else {
		board[tr + size - 1][tc + size] = t1;
		// �������ֱ�ӷ�t������Ȼ֮������޶�û�����ˣ�ÿ�ζ��ô�ͬһ�㿪ʼ������һ�����εݹ�ͼ��
		ChessBoard(tr, tc + size, tr + size - 1, tc + size, size);
	}
	
	if (dr >= tr + size && dc < tc + size) { // ��ǵ��Ƿ��ڵ���������
		ChessBoard(tr + size, tc, dr, dc, size);
	}
	else {
		board[tr + size][tc + size - 1] = t1;
		ChessBoard(tr + size, tc, tr + size, tc + size - 1, size);
	}

	if (dr >= tr + size && dc >= tc + size) { // ��ǵ��Ƿ��ڵ���������
		ChessBoard(tr + size, tc + size, dr, dc, size);
	}
	else {
		board[tr + size][tc + size] = t1;
		ChessBoard(tr + size, tc + size, tr + size, tc + size, size);
	}
}