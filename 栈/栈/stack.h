#pragma once

typedef int STDataType;

typedef struct Stack
{
	STDataType* arr;
	int size;
	int capacity;
}Stack;
void StackInit(Stack* s, int capacity);
void StackPush(Stack* s,STDataType data);
void StackPop(Stack* s);
STDataType StackTop(Stack* s);
int StackEmpty(Stack* s);
int StackSize(Stack* s);
int StackCapacity(Stack* s);
void StackDestroy(Stack* s);
void CheckCapacity(Stack* s);