#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

struct queue
{
	node* head;
	node* tail;
};

void createQueue(queue& q)
{
	q.head = q.tail = NULL;
}

node* createNODE(int x)
{
	node* p = new node;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho cap phat!" << endl;
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}

bool isEmpty(queue q)
{
	if (q.head == NULL)
		return true;
	return false;
}

bool push(queue& q, node* p)
{
	if (p == NULL)
		return false;
	if (isEmpty(q))
	{
		q.head = q.tail = p;
	}
	else
	{
		q.tail->next = p;
		q.tail = p;
	}
	return true;
}

bool pop(queue& q, int& x)
{
	if (isEmpty(q))
		return false;
	else
	{
		node* p = q.head;
		x = q.head->data;
		q.head = q.head->next;
		delete p;
	}
}

bool pop1(queue& q)
{
	if (isEmpty(q))
		return false;
	else
	{
		node* p = q.head;
		q.head = q.head->next;
		delete p;
	}
}

bool top(queue& q, int& x)
{
	if (isEmpty(q))
		return false;
	x = q.head->data;
	return true;
}

void showQueue(queue& q)
{
	while (isEmpty(q) == false)
	{
		int x;
		pop(q, x);
		cout << x << " ";
	}
	if (isEmpty(q) == true)
		cout << "\nQueue is EMPTY!" << endl;
	else
		cout << "\nQueue is containing node!" << endl;
}

void showQueue1(queue& q)
{
	node* p = q.head;
	if (q.head == NULL)
		cout << "\nQueue is empty!" << endl;
	else
	{
		p = q.head->next;
		cout << "\nQueue is elements: ";
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
	}
	cout << endl;
}

void MENU(queue& q)
{
	int choose;
	while (true)
	{
		system("cls");
		cout << "\n\t\t====== MENU =======" << endl;
		cout << "\t1 - Add first - push." << endl;
		cout << "\t2 - Show list queue - pop." << endl;
		cout << "\t3 - Show first queue - top." << endl;
		cout << "\t4 - Delete first node." << endl;
		cout << "\t0 - Exit.";
		cout << "\n\t\t======= END ========" << endl;

		cout << "\nEnter your choice: ";
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
			node* p = createNODE(x);
			push(q, p);
		}
		else if (choose == 2)
		{
			showQueue(q);
			// createQueue(q);
			system("pause");
		}
		else if (choose == 3)
		{
			int x;
			top(q, x);
			cout << "\nElement first is: " << x << endl;
			system("pause");
		}
		else if (choose == 4)
		{
			int x;
			pop1(q);
		}
		else
			break;
	}

	
}

int main()
{
	queue q;
	createQueue(q);
	MENU(q);

	system("pause");
	return 0;
}