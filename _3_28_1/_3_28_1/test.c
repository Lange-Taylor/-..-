//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//void Swap(int a,int b) {
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("%d\n", a);
//	printf("%d\n", b);
//}
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main() {
//	printf("������һ������Ҫ���ɵļ��˼�������:");
//	int n;
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 1; i <= n; ++i) {
//		int j = 0;
//		for (j = 1; j <= i; ++j) {
//			printf("%2d*%2d=%3d", j, i, i*j);
//		}
//		printf("\n");
//	}
	//ʹ�ú���ʵ���������Ľ�����
	int x = 10;
	int y = 20;
	Swap(&x, &y);
	printf("%d %d\n", x, y);
	system("pause");
	return 0;
}