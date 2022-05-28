#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void STtest1()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackDestroy(&st);
}
void STtest2()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	StackDestroy(&st);
}
int main()
{
	//STtest1();
	STtest2();
	return 0;
}