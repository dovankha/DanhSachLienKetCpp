#include <iostream>
using namespace std;

//De: Nhap danh sach lien ket cac phan so
//Quan li danh sach lien ket bang con tro dau nen khong co khoi tao danh sach lien ket

struct phanSo
{
	int tuSo, mauSo;
};

void nhapPhanSo(phanSo& ps)
{
	cout << "\nNhap tu so: ";
	cin >> ps.tuSo;
	do
	{
		cout << "\nNhap mau so: ";
		cin >> ps.mauSo;
		if (ps.mauSo == 0)
		{
			cout << "\nMau so phai khac 0! Vui long nhap lai!" << endl;
			system("pause");
		}
	} while (ps.mauSo == 0);
}

int timUCLN(int x, int y)
{
	while (x != y)
	{
		if (x < y)
			y -= x;
		else if (x > y)
			x -= y;
	}
	return x;
}

void rutGonPhanSo(phanSo& ps)
{
	int ucln = timUCLN(ps.tuSo, ps.mauSo);
	ps.tuSo = ps.tuSo / ucln;
	ps.mauSo = ps.mauSo / ucln;
}

void xuatPhanSo(phanSo ps)
{
	if (ps.tuSo == ps.mauSo)
	{
		cout << ps.tuSo << "/" << ps.mauSo;
		rutGonPhanSo(ps);
		cout << " = " << ps.tuSo;
		
	}
	else
	{
		rutGonPhanSo(ps);
		if (ps.mauSo == 1)
			cout << ps.tuSo << endl;
		else
			cout << ps.tuSo << "/" << ps.mauSo;
	}
}

struct node
{
	phanSo data; // du lieu la phan so.
	node* next;
};

node* khoiTaoNode(phanSo x)
{
	node* p = new node;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho cap phat!" << endl;
		return 0;
	}
	p->data = x;
	p->next = NULL;
	return p;
}

void themDau(node*& head, node* p)
{
	if (head == NULL)
		head = p;
	else
	{
		p->next = head;
		head = p;
	}
}

void themCuoi(node*& head, node* p)
{
	if (head == NULL)
		head = p;
	else
	{
		for (node* i = head; ; i = i->next)
		{
			// neu i dang xet ma tro den null thi chinh la node cuoi
			if (i->next == NULL)
			{
				i->next = p;
				break;
			}
		}
	}
}

void themNodePSauNodeQ(node*& head, phanSo x, node* q)
{
	// duyet danh sach kiem tra xem co ton tai phan tu q khong
	for (node* i = head; i != NULL; i = i->next)
	{
		if (i->data.tuSo == q->data.tuSo && i->data.mauSo == q->data.mauSo)
		{
			node* p = khoiTaoNode(x);
			p->next = i->next;
			i->next = p;
		}
	}
}

void xoaDau(node*& head)
{
	if (head == NULL)
		return;
	node* p = head;
	head = head->next;
	delete p; 
}

void xoaCuoi(node*& head)
{
	if (head == NULL)
		return;
	if (head->next == NULL)	// neu danh sach ton tai 1 node
	{
		node* p = head;
		head = NULL;
		delete p;			// xoa duy nhat 1 thang trong danh sach
		return;
	}
	// xu li 2 phan tu tro len
	for (node* i = head; ; i = i->next)
	{
		if (i->next->next == NULL)
		{
			delete i->next;
			i->next = NULL;
			break;
		}
	}
}

void xoaNodeSauQ(node*& head, node* q)
{
	for (node* i = head; i != NULL; i = i->next)
	{
		if (i->data.tuSo == q->data.tuSo && i->data.mauSo == q->data.mauSo && i->next != NULL)
		{
			node* temp = i->next;	// giu tam lien ket voi thang can xoa (nam sau thang co san)
			i->next = i->next->next;// lien ket node co san voi node sau thang xoa
			delete temp;			// xoa thang nam sau node co san
		}
	}
}

void xuatDanhSachPhanSo(node* head)
{
	for (node* i = head; i != NULL; i = i->next)
	{
		xuatPhanSo(i->data);
		cout << endl;
	}
}

void menu(node*& head)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t======== QUAN LI DANH SACH PHAN SO =========" << endl;
		cout << "\t1 - Nhap phan so." << endl;
		cout << "\t2 - Xuat danh sach phan so." << endl;
		cout << "\t3 - Xoa phan so dau tien." << endl;
		cout << "\t4 - Xoa phan so cuoi cung." << endl;
		cout << "\t5 - Them phan so P vao sau phan so Q." << endl;
		cout << "\t6 - Xoa node P sau Node Q." << endl;
		cout << "\t0 - Ket thuc.";
		cout << "\n\t\t=============== END =============" << endl;

		int luaChon;
		cout << "\nNhap vao lua chon: ";
		cin >> luaChon;

		if (luaChon < 0 || luaChon > 6)
		{
			cout << "\nLua chon cua ban khong hop le!" << endl;
		}
		else if (luaChon == 1)
		{
			phanSo x;
			nhapPhanSo(x);
			node* p = khoiTaoNode(x);
			themCuoi(head, p);
		}
		else if (luaChon == 2)
		{
			cout << "\n\t==== Danh Sach Phan So ====" << endl;
			xuatDanhSachPhanSo(head);
			system("pause");
		}
		else if (luaChon == 3)
			xoaDau(head);
		else if (luaChon == 4)
			xoaCuoi(head);
		else if (luaChon == 5)
		{
			phanSo x, y;
			cout << "\n\t***** NHAP GIA TRI PHAN SO CAN THEM *****" << endl;
			nhapPhanSo(x);
			cout << "\n\t===== NHAP GIA TRI PHAN SO CO SAN =====" << endl;
			nhapPhanSo(y);
			node* p = khoiTaoNode(y);
			themNodePSauNodeQ(head, x, p);
		}
		else if (luaChon == 6)
		{
			phanSo x;
			cout << "\n\t***** NHAP PHAN SO CO SAN *****" << endl;
			nhapPhanSo(x);
			node* q = khoiTaoNode(x);
			xoaNodeSauQ(head, q);
		}
		else
			break;
	}
}

int main()
{
	node* head = NULL;
	menu(head);
	system("pause");
	return 0;
}