#include <stdio.h>
#include <stdlib.h>
void sxh(int n) {
	int x, y, z;
	x = n/100;
	y = (n/10)%10;
	z = n % 10;
	if (x * x * x + y * y * y + z * z * z == n) {
		printf("%d\t",n);
	}
		
}
int main() {
	///*int n = 7;
	//int j = 0;
	//int i = 0;
	//for (j = 1; j <= n; ++j) {
	//	for (i = 0; i < 2 * n; ++i) {

	//		if (i < 2 * j-1) {
	//			printf("*");
	//		}else
	//		printf(" ");
	//	}
	//	printf("\n");
	//}
	//for (j = 2; j <= n; ++j) {
	//	for (i = 2*n-1; i > 0; --i) {

	//		if (i < 2*j-1 ) {
	//			printf(" ");
	//		}
	//		else
	//			printf("*");
	//	}
	//	printf("\n");
	//}
	//*/
	//求出0～999之间的所有“水仙花数”并输出。
		//“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，如；153＝1＋5＋3 ? ，则153是一个“水仙花数”。

		/*
		在数论中，水仙花数（Narcissistic number）也称为自恋数、自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number），是指一N位数，其各个数之N次方和等于该数。
		例如153、370、371及407就是三位数的水仙花数，其各个数之立方和等于该数：
		153 = 1^3 + 5^3 + 3^3。
		370 = 3^3 + 7^3 + 0^3。
		371 = 3^3 + 7^3 + 1^3。
		407 = 4^3 + 0^3 + 7^3。
		*/
	for (int i = 0; i < 1000; ++i) {
		 sxh(i);
	
	}

	system("pause");
	return 0;
}