#if 0

#include <stdio.h>

void is_little_endian()
{
	int a = 0x12345678;
	char b = *(char*)&a;
	if (b == 0x78)
		printf("小端字节序");
	else
		printf("大端字节序");
}

int main()

{
	is_little_endian();
	return 0;
}
#endif

#include <stdio.h>

//void is_little_endian()
//{
//	union {
//		int a;
//		char b;
//	}temp;
//	temp.a = 0x12345678;
//	if(temp.b == 0x78)
//		printf("小端字节序");
//	else
//		printf("大端字节序");
//}

void is_little_endian()
{
	union {
		char a;
		int b;
	}temp;
	temp.b = 0x12345678;
	if (temp.a == 0x78)
		printf("小端字节序");
	else
		printf("大端字节序");
}


int main()
{
	is_little_endian();
	return 0;
}