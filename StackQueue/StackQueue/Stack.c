#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	//À©ÈÝ
	if (ps->capacity == ps->top)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->arr, newCapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
	//Ñ¹Õ»
	ps->arr[ps->top] = x;
	ps->top++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->arr[ps->top - 1];
}
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}
int StackSize(Stack* ps)
{
	return ps->top; 
}
