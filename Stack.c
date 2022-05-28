#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		int newCapacity = ps->capacity == 0 ? 4: ps->capacity * 2;
		STDataType* tmp = realloc(ps->a, sizeof(STDataType)*newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail");
			exit(-1);
		}
		else
		{
			ps->capacity = newCapacity;
			ps->a = tmp;
		}
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}