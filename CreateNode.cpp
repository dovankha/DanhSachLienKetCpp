#include <iostream>
using namespace std;

//------------Tao node
struct node
{
	int data;
	node* next;
};

node* createNode(int val)
{
	node* p = new node;
	if (p == NULL)
	{
		cout << "\nNot enough memory allocated!" << endl;
		return NULL;
	}
	p->data = val;
	p->next = NULL;
	return p;
};

//------------Tao danh sach
struct LinkedList
{
	node* head;
	node* tail;
};

void createList(LinkedList& l)
{
	l.head = l.tail = NULL;
}

void addHead(LinkedList& l, node* p)
{
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}
}

void addTail(LinkedList& l, node* p)
{
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

int length(LinkedList l)
{
	int count = 0;

	/*node* p = l.head;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}*/

	for (node* i = l.head; i != NULL; i = i->next)
		count++;
	return count;
}

void insertAfterQ(LinkedList& l, node* p)
{
	int val;
	cout << "\nEnter a node available: ";
	cin >> val;
	node* q = createNode(val);
	if (q->data == l.head->data && l.head->next == NULL)
		addTail(l, p);
	else
	{
		for (node* i = l.head; i != NULL; i = i->next)
		{
			if (q->data == i->data)
			{
				node* h = createNode(p->data);
				//node* g = i->next;
				h->next = i->next;
				i->next = h;
			}
		}
	}
}

void insertBeforeQ(LinkedList& l, node* p)
{
	int x;
	cout << "\nEnter a node available: ";
	cin >> x;
	node* q = createNode(x);

	if (q->data == l.head->data && l.head->next == NULL)
		addHead(l, p);
	else
	{
		node* g = new node;
		for (node* i = l.head; i != NULL; i = i->next)
		{
			if (q->data == i->data)
			{
				node* h = createNode(p->data);
				h->next = i;
				g->next = h;
			}
			g = i; // cap nhat g = gia tri node i moi
		}
	}
}

void insertNodePossible(LinkedList& l, node* p, int pos)
{
	if (l.head == NULL || pos == 1)
		addHead(l, p);
	else if (pos == length(l) + 1)
		addTail(l, p);
	else
	{
		int dem = 0;
		node* g = new node;
		for (node* i = l.head; i != NULL; i = i->next)
		{
			dem++;
			if (dem == pos)
			{
				node* h = createNode(p->data);
				h->next = i;
				g->next = h;
				break;
			}
			g = i;
		}
	}
}

void removeHead(LinkedList& l)
{
	if (l.head == NULL)
		return;
	node* p = l.head;
	l.head = l.head->next;
	delete p;
}

void removeTail(LinkedList& l)
{
	if (l.head == NULL)
		return;
	if (l.head->next == NULL)
	{
		removeHead(l);
		return;
	}
	for (node* i = l.head; i != NULL; i = i->next)
	{
		if (i->next == l.tail)
		{
			delete l.tail;
			i->next = NULL;
			l.tail = i;
			return;
		}
	}
}

void removeNodeAfter(LinkedList& l, node* q)
{
	for (node* i = l.head; i != NULL; i = i->next)
	{
		if (i->data == q->data)
		{
			node* g = i->next; // g la node se xoa.
			i->next = g->next; // cap nhat con tro lai.
			delete g;
		}
	}
}

void removeAnyNode(LinkedList& l, int pos)
{
	if (l.head == NULL)
		return;
	if (l.head->data == pos)
	{
		removeHead(l);
		return;
	}
	if (l.tail->data == pos)
	{
		removeTail(l);
		return;
	}
	node* g = new node; // node g la node nam truoc node can xoa

	for (node* i = l.head; i != NULL; i = i->next)
	{
		if (i->data == pos)
		{
			g->next = i->next;
			delete i;
			return;
		}
		g = i; // tro den node can xoa
	}
}

void removeList(LinkedList& l)
{
	node* rm = NULL;
	while (l.head != NULL)
	{
		rm = l.head;
		l.head = l.head->next;
		delete rm;
	}

	/*for (node* i = l.head; i != NULL; i = i->next)
		delete i;*/
}

void showList(LinkedList l)
{
	for (node* i = l.head; i != NULL; i = i->next)
	{
		cout << i->data << " ";
	}
}

void MENU(LinkedList l)
{
	int choose, x, pos;

	while (true)
	{
		system("clear");
		cout << "\t\t========= MENU ===========" << endl;
		cout << "\n\t1 - Add Node" << endl;
		cout << "\t2 - Show list node & length." << endl;
		cout << "\t3 - Add node P after node Q." << endl;
		cout << "\t4 - Add node P before node Q." << endl;
		cout << "\t5 - Add node in possible." << endl;
		cout << "\t6 - Remove node Head." << endl;
		cout << "\t7 - Remove node Tail." << endl;
		cout << "\t8 - Remove node after node Q." << endl;
		cout << "\t9 - Remove any node." << endl;
		cout << "\t10 - Remove list node." << endl;
		cout << "\t0 - Exit";
		cout << "\n\n\t\t========= END ============" << endl;

		cout << "\nEnter your choose: ";
		cin >> choose;

		if (choose < 0 || choose > 10)
		{
			cout << "\nYour choose is not correct! Enter your choose, please!" << endl;
			system("pause");
		}
		else if (choose == 1)
		{
			cout << "\nEnter a integer number: ";
			cin >> x;
			node* p = createNode(x);
			addTail(l, p);
		}
		else if (choose == 2)
		{
			cout << "\n\t===== SHOW LIST NODE =====" << endl;
			cout << "\n=> Your node list: ";
			showList(l);
			cout << "\n=> Length of list: " << length(l) << " (node)" << endl;
			system("pause");
		}
		else if (choose == 3)
		{
			cout << "\nEnter a value need insert: ";
			cin >> x;
			node* m = createNode(x);
			insertAfterQ(l, m);
		}
		else if (choose == 4)
		{
			cout << "\nEnter a value need insert: ";
			cin >> x;
			node* p = createNode(x);
			insertBeforeQ(l, p);
		}
		else if (choose == 5)
		{
			cout << "\nEnter a value need insert: ";
			cin >> x;
			node* p = createNode(x);

			do
			{
				cout << "\nEnter possible: ";
				cin >> pos;
				if (pos < 1 || pos > length(l) + 1)
				{
					cout << "\nPossible is incorrect! Enter again, please!" << endl;
					system("pause");
				}
			} while (pos < 1 || pos > length(l) + 1);

			insertNodePossible(l, p, pos);
			(length(l) + 1);
			/*int n = length(l);
			n++;*/
		}
		else if (choose == 6)
			removeHead(l);
		else if (choose == 7)
			removeTail(l);
		else if (choose == 8)
		{
			cout << "Enter node Q: ";
			cin >> x;
			node* q = createNode(x);
			removeNodeAfter(l, q);
		}
		else if (choose == 9)
		{
			cout << "\nEnter possible need remove: ";
			cin >> pos;
			removeAnyNode(l, pos);
		}
		else if (choose == 10)
		{
			int num;
			cout << "\n\t==== REMOVE LIST ====" << endl;
			cout << "\nDo you want to REMOVE list?" << endl;
			cout << "\t1. YES	2. NO" << endl;
			cout << "Please enter: ";
			cin.ignore(1);
			cin >> num;
			if (num == 1)
			{
				removeList(l);
				cout << "\n\t===== You have DELETE list node =====" << endl;
				system("pause");
			}
			else if (num == 2)
			{
				cout << "\n\t ==== You have cancelled ====" << endl;
				system("pause");
			}
			else
			{
				cout << "\n\t====Your selection is INCORRECT!====" << endl;
				system("pause");
			}
			
		}
		else
			break;
	}
}

int main()
{
	LinkedList list;
	createList(list);
	MENU(list);

	system("pause");
	return 0;
}
