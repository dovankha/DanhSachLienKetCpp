#include <iostream>
using namespace std;

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
void chuyenCoSo(stack& s, int coSo, int heThapPhan)
{
	while (heThapPhan != 0)
	{
		int x = heThapPhan % coSo;
		node* p = createNode(x);  // them x vao node p
		push(s, p);
		heThapPhan /= coSo;
	}
}

void showStack(stack& s)
{
	while (!isEmpty(s)) // isEmpty(s) == false
	{
		int x;
		pop(s, x);
		if (x < 10)
			cout << x;
		else
		{
			if (x == 10)
				cout << "A";
			else if (x == 11)
				cout << "B";
			else if (x == 12)
				cout << "C";
			else if (x == 13)
				cout << "D";
			else if (x == 14)
				cout << "E";
			else if (x == 15)
				cout << "F";

		}
	}
}

int main()
{
	stack s;
	createStack(s);
	int heThapPhan, coSo;

	cout << "Nhap gia tri he thap phan (10) can chuyen: ";
	cin >> heThapPhan;
	cout << "\nNhap co so can chuyen (2, 8, 16): ";
	cin >> coSo;

	chuyenCoSo(s, coSo, heThapPhan);
	cout << "\n\tKET QUA " << endl;
	showStack(s);
	cout << endl;

	system("pause");
	return 0;
}