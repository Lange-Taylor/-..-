//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
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
//	printf("请输入一个你想要生成的几乘几的整数:");
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
	//使用函数实现两个数的交换。
	int x = 10;
	int y = 20;
	Swap(&x, &y);
	printf("%d %d\n", x, y);
	system("pause");
	return 0;
}