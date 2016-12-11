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

//ȡջ��Ԫ��
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

//��ջ
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

//��ջ
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

//ȡջ��Ԫ��
ElemType getStackBottomElement(seqStack S)
{
	if (stackEmpty(S))
	{
		return -1;
	}
	int x = -2;
	while (!stackEmpty(S))  //��Ϊ��ʱ������ѭ��
	{
		x = S.data[S.top--];
	}
	return x;
}