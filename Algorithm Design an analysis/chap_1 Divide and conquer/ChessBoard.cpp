#define _CRT_SECURE_NO_WARNINGS 1
#include"ChessBoard.h"
#include<iostream>
using namespace std;
// tr左上点row，tc左上点col，dr标记点row，dc标记点col，size边长
void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
	// 首先写递归的结束条件
	if (size == 1) return; // 如果size是1那么直接返回

	// 进入一层应该先记录层数(方块数)
	int t1 = ++t;  

	size = size / 2;
	if (dr < tr + size && dc < tc + size) { // 标记点是否在第二象限内
		ChessBoard(tr, tc, dr, dc, size); // 如果在本节点，那么原象限遍历
	}
	else {
		board[tr + size - 1][tc + size - 1] = t1; // 不在的话右下角标记 // 一定要加上相对位置tr，tc!!!
		ChessBoard(tr, tc, tr + size - 1, tc + size - 1, size); // 全部都要加上位移啊！！
	}

	if (dr < tr + size && dc >= tc + size) { // 标记点是否在第一象限内
		ChessBoard(tr, tc + size, dr, dc, size); // 标记点在的话是不用改标记点位置的
	}
	else {
		board[tr + size - 1][tc + size] = t1;
		// 这个不能直接放t啊，不然之后的象限都没法用了，每次都得从同一层开始（想象一下树形递归图）
		ChessBoard(tr, tc + size, tr + size - 1, tc + size, size);
	}
	
	if (dr >= tr + size && dc < tc + size) { // 标记点是否在第三象限内
		ChessBoard(tr + size, tc, dr, dc, size);
	}
	else {
		board[tr + size][tc + size - 1] = t1;
		ChessBoard(tr + size, tc, tr + size, tc + size - 1, size);
	}

	if (dr >= tr + size && dc >= tc + size) { // 标记点是否在第四象限内
		ChessBoard(tr + size, tc + size, dr, dc, size);
	}
	else {
		board[tr + size][tc + size] = t1;
		ChessBoard(tr + size, tc + size, tr + size, tc + size, size);
	}
}