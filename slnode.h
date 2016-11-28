
struct  slNode
{
	ElemType data;
	struct slNode * next;
};
typedef struct slNode node, *linkList;

void initialList(linkList &L)
{
	L = new node;
	L->next = NULL;
	cout << "sucess\n";
}
//O(1)
int listLength(linkList L)
{
	int len = 0;
	linkList p = L->next;
	while (p)
	{
		len++;
		p = p->next;
	}
	return len;
}

//find with according to number,O(n)
linkList getElement(linkList L, int i)
{
	linkList p = L->next;
	int j = 1;
	if (i > listLength(L))
		return NULL;
	while (j != i&&p)
	{
		j++;
		p = p->next;
	}
	return p;
}

//find with according to value,O(n)
linkList listLocate(linkList L, ElemType x)
{
	linkList p = L->next;
	while (p != NULL&&p->data != x)
	{
		p = p->next;
	}
	return p;
}

//insert,O(n)
bool listInsert(linkList L, int i, ElemType x)
{
	linkList p = L, S;
	int k = 0;
	while (k != i - 1 && p != NULL)
	{
		p = p->next;
		k++;
	}
	if (p == NULL)
		return false;
	else
	{
		S = new node;
		S->data = x;
		S->next = p->next;
		p->next = S;
		return true;
	}
}

//delete
bool listDelete(linkList L, int i)
{
	linkList p = L, u;
	int k = 0;
	while (k != i - 1 && p != NULL)
	{
		p = p->next;
		k++;
	}
	if (p == NULL || p->next == NULL)
	{
		return false;
	}
	else
	{
		u = p->next;
		p->next = u->next;
		delete u;
		return true;
	}

}

void createListR(linkList &L)
{
	ElemType x;
	linkList u, R;
	L = new node;
	L->next = NULL;
	R = L;
	cout << "enter data(9999 exit):" << endl;
	cin >> x;
	while (x != 9999)
	{
		u = new node;
		u->data = x;
		u->next = NULL;
		R->next = u;
		R = u;
		cin >> x;
	}
}

void createListH(linkList &L)
{
	linkList u;
	ElemType x;
	L = new node;
	L->next = NULL;
	cout << "enter data(9999 exit):" << endl;
	cin >> x;
	while (x != 9999)
	{
		u = new node;
		u->data = x;
		u->next = L->next;
		L->next = u;
		cin >> x;
	}
}
