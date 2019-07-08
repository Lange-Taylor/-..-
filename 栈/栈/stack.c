#include "stack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void StackInit(Stack* s,int capacity) {
	assert(s);
	s->arr = (STDataType*)malloc(sizeof(STDataType)*capacity);
	if (s->arr == NULL)
	{
		assert(0);
		return;
	}
	s->capacity = capacity;
	s->size = 0;
}
void StackPush(Stack* s,STDataType data) {
	assert(s);
	if (s->capacity == s->size)
	{
		CheckCapacity(s);
	}
	s->arr[s->size++] = data;
}
void StackPop(Stack* s) {
	assert(s);
	if (StackEmpty(s))
		return;
	s->size -= 1;
}
STDataType StackTop(Stack* s) {
	assert(s);
	return s->arr[s->size-1];
}
int StackEmpty(Stack* s) {
	assert(s);
	return s->size == 0;
}
int StackSize(Stack* s) {
	assert(s);
	return s->size;
}
int StackCapacity(Stack* s) {
	assert(s);
	return s->capacity;
}
void StackDestroy(Stack* s) {
	if (s->arr) {
		free(s->arr);
	}
	s->capacity = 0;
	s->size = 0;
}
void CheckCapacity(Stack* s) {
	assert(s);
	int newcapacity = 2 * s->capacity;
	STDataType* pTemp = (STDataType*)malloc(sizeof(STDataType)*newcapacity);
	if (pTemp == NULL) {
		assert(0);
		return;
	}
	for (int i = 0; i < s->size; i++) {
		pTemp[i] = s->arr[i];
	}
	free(s->arr);
	s->arr = pTemp;
	s->capacity = newcapacity;
}
int main() {
	
	Stack s;
	StackInit(&s,3);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	printf("%d\n", StackSize(&s));
	printf("%d\n", StackTop(&s));

	StackPush(&s, 4);
	StackPush(&s, 5);
	printf("%d\n", StackSize(&s));
	printf("%d\n", StackTop(&s));

	StackPop(&s);
	printf("%d\n", StackSize(&s));
	printf("%d\n", StackTop(&s));

	StackDestroy(&s);

	return 0;
}