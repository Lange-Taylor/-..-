#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//
//void menu() {
//	printf("***************************\n");
//	printf("********1. 开始游戏********\n");
//	printf("********0. 结束游戏********\n");
//	printf("***************************\n");
//}
//
//void game() {
//	int random_num = rand() % 100 + 1;
//	int input = 0;
//	while (1) {
//		printf("请输入猜的数字:");
//		scanf("%d", &input);
//		if (input > random_num) {
//			printf("猜大了\n");
//		}
//		else if (input < random_num) {
//			printf("猜小了\n");
//		}
//		else {
//			printf("恭喜猜对了\n");
//			break;
//		}
//	}
//}
int main() {
	///*int input = 0;
	//srand((unsigned)time(NULL));
	//do {
	//	menu();
	//	printf("请选择:");
	//	scanf("%d", &input);
	//	switch (input) {
	//	case 1:
	//			game();
	//			break;
	//	case 0:
	//		printf("拜拜");
	//		system("pause");
	//		break;
	//	default:
	//		printf("选择错误,请重新输入!\n");
	//		break;
	//	}
	//} while (input);*/
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int left = 0;
	int right = sizeof(arr)/sizeof(arr[0])-1;
	int mid = 0;
	int key = 6;
	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] < key) {
			mid = mid + 1;
		}
		else if (arr[mid] > key) {
			mid = mid - 1;
		}
		else {
			break;
		}
	}
	if (left <= right) 
		printf("找到了:%d", mid);
	
	else 
		printf("没找到");
		system("pause");
		return 0;
}