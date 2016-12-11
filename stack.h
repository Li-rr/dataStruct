#pragma once
struct sStack
{
	ElemType data[MAXSIZE];
	int top;
};
typedef struct sStack seqStack;

void initialStack(seqStack &S)
{
	S.top = -1;
}
bool stackEmpty(seqStack &S)
{
	if (S.top == -1)
		return true;
	else
		return false;
}

//取栈顶元素
ElemType stackTop(seqStack S)
{

	if (stackEmpty(S))
		return -1; //the stack is empty
	else
	{
		return S.data[S.top];

	}
}

bool stackFull(seqStack S)
{
	if (S.top == MAXSIZE - 1)
		return true;
	else
		return false;
}

//入栈
bool pushStack(seqStack &S, ElemType x)
{
	if (stackFull(S))
		return false;
	else
	{
		S.top++;
		S.data[S.top] = x;
		//S.data[++S.top]=x;
		return true;
	}
}

//出栈
ElemType popStack(seqStack &S)
{
	if (stackEmpty(S))
		return -1;
	else
	{
		return S.data[S.top--];
		//S.top--;
		//x = S.data[S.top--];

	}
}

//取栈底元素
ElemType getStackBottomElement(seqStack S)
{
	if (stackEmpty(S))
	{
		return -1;
	}
	int x = -2;
	while (!stackEmpty(S))  //不为空时，进入循环
	{
		x = S.data[S.top--];
	}
	return x;
}