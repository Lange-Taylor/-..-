#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//
//void menu() {
//	printf("***************************\n");
//	printf("********1. ��ʼ��Ϸ********\n");
//	printf("********0. ������Ϸ********\n");
//	printf("***************************\n");
//}
//
//void game() {
//	int random_num = rand() % 100 + 1;
//	int input = 0;
//	while (1) {
//		printf("������µ�����:");
//		scanf("%d", &input);
//		if (input > random_num) {
//			printf("�´���\n");
//		}
//		else if (input < random_num) {
//			printf("��С��\n");
//		}
//		else {
//			printf("��ϲ�¶���\n");
//			break;
//		}
//	}
//}
int main() {
	///*int input = 0;
	//srand((unsigned)time(NULL));
	//do {
	//	menu();
	//	printf("��ѡ��:");
	//	scanf("%d", &input);
	//	switch (input) {
	//	case 1:
	//			game();
	//			break;
	//	case 0:
	//		printf("�ݰ�");
	//		system("pause");
	//		break;
	//	default:
	//		printf("ѡ�����,����������!\n");
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
		printf("�ҵ���:%d", mid);
	
	else 
		printf("û�ҵ�");
		system("pause");
		return 0;
}