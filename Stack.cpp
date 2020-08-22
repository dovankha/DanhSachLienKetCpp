#include <iostream>
using namespace std;

int top = -1; // de tinh so luong phan tu.

struct node
{
	int data;
	node* next;
};

struct stack
{
	node* top;
};

void createStack(stack& s)
{
	s.top = NULL;
}

node* createNode(int x)
{
	node* p = new node; // ()
	if (p == NULL)
	{
		cout << "\nNot enough memory!" << endl;
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}

// kiem tra stack co rong khong
bool isEmpty(stack s)
{
	if (s.top == NULL)
		return true;
	return false;
}

// them 1 phan tu vao dau stack-LIFO
bool push(stack& s, node* p)
{
	if (p == NULL)
		return false;
	if (isEmpty(s) == true)
		s.top = p;
	else
	{
		p->next = s.top;
		s.top = p;
	}
	return true;
}

// xoa phan tu dau trong stack - so luong stack giam di 1
bool pop(stack& s, int& x)
{
	if (isEmpty(s))
		return false;
	else
	{
		node* p = s.top;
		x = p->data;
		s.top = s.top->next;
		delete p;
	}
	return true;
}

bool pop1(stack& s)
{
	if (isEmpty(s))
		return false;
	node* p = s.top;
	s.top = s.top->next;
	delete p;
}


// xem thong tin phan tu dau tien cua stack
bool Top(stack& s, int& x)
{
	if (isEmpty(s) == true)
		return false;
	x = s.top->data;
	return true;
}

// xuat danh sach stack
void showStack(stack s)
{
	while (isEmpty(s) == false)
	{
		int x;
		pop(s, x);
		cout << x << " ";
	}

	if (isEmpty(s) == true)
		cout << "\nStack is EMPTY!" << endl;
	else
		cout << "\nStack is containing node!" << endl;
}

void showStack1(stack s)
{
	node* p = NULL;
	if (s.top == NULL)
		cout << "\nStack is empty!" << endl;
	else
	{
		p = s.top->next;
		cout << "\nStack is element: ";
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
	}
	cout << endl;
}

int topp(int stack[])
{
	return stack[top];
}

int sizeee()
{
	return top + 1;
}

void MENU(stack& s)
{
	int choose;
	while (true)
	{
		system("clear");
		cout << "\n\t\t====== MENU =======" << endl;
		cout << "\t1 - Add first - push." << endl;
		cout << "\t2 - Show list stack - pop." << endl;
		cout << "\t3 - Show first stack - top." << endl;
		cout << "\t4 - Delete first node." << endl;
		cout << "\t0 - Exit.";
		cout << "\n\t\t======= END ========" << endl;

		cout << "\nEnter your choose: ";
		cin >> choose;

		if (choose < 0 || choose > 4)
		{
			cout << "\nYour choose is incorrect!" << endl;
			system("pause");
		}
		else if (choose == 1)
		{
			int x;
			cout << "\nEnter element to insert: ";
			cin >> x;
			node* p = createNode(x);
			push(s, p);
		}
		else if (choose == 2)
		{
			showStack1(s);
			system("pause");
		}
		else if (choose == 3)
		{
			int x;
			Top(s, x);
			cout << "\nElement first is: " << x << endl;
			system("pause");
		}
		else if (choose == 4)
		{
			int x;
			pop1(s);
		}
		else
			break;
	}
}

int main()
{
	stack s;
	createStack(s);
	MENU(s);

	system("pause");
	return 0;
}