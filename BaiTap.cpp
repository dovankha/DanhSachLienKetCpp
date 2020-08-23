#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *khoiTaoNODE(int x)
{
    node *p = new node;
    if (p == NULL)
        return NULL;
    p->data = x;
    p->next = NULL;
    return p;
}

void themDau(node *&head, node *p)
{
    if (head == NULL)
        head = p;
    else
    {
        p->next = head;
        head = p;
    }
}

void xuatDanhSach(node *head)
{
    for (node *i = head; i != NULL; i = i->next)
    {
        cout << i->data << " ";
    }
}

void giaiPhongVungNho(node *head)
{
    node *i = head;
    while (head != NULL)
    {
        i = head;
        head = head->next;
        delete i;
    }
}

void xoaDau(node *&head)
{
    if (head == NULL)
        return;
    node *p = head;
    head = head->next;
    delete p;
}

void hoanVi(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void sapXepGiam(node *&head)
{
    for (node *i = head; i != NULL; i = i->next)
    {
        for (node *j = i->next; j != NULL; j = j->next)
        {
            if (i->data < j->data)
                hoanVi(i->data, j->data);
        }
    }
}

void xoaNODESauQ(node *&head, int x)
{
    if (head == NULL)
        return;
    else
    {
        node *g = NULL;
        for (node *i = head; i != NULL; i = i->next)
        {
            if (i->data == x)
            {
                g->next = i->next;
                delete i;
                break; // chuong trinh dang loi khuc nay.
                // node *i = head;
            }
            g = i;
        }
    }
}

bool ktrSoDoiXung(int n)
{
    int ktr = 0, temp = n;
    while (n != 0)
    {
        int i = n % 10;
        ktr = ktr * 10 + i;
        n /= 10;
    }
    if (ktr == temp)
        return true;
    else
        return false;
}

void xuatSoDoiXung(node *head)
{
    for (node *i = head; i != NULL; i = i->next)
    {
        if (ktrSoDoiXung(i->data))
            cout << i->data << " ";
    }
}

void menu(node *&head)
{
    int luaChon;
    while (true)
    {
        system("cls");
        cout << "\t\t======== MENU ========" << endl;
        cout << "\t1 - Them NODE" << endl;
        cout << "\t2 - Xuat danh sach NODE" << endl;
        cout << "\t3 - Sap xep danh sach GIAM DAN" << endl;
        cout << "\t4 - Xuat danh sach cac so doi xung" << endl;
        cout << "\t5 - Xoa Dau" << endl;
        cout << "\t6 - Xoa NODE sau P" << endl;
        cout << "\t0 - Thoat chuong chinh" << endl;
        cout << "\t\t========= END =========" << endl;

        cout << "\n+ Nhap vao lua chon: ";
        cin >> luaChon;

        if (luaChon < 0 || luaChon > 6)
        {
            cout << "\n[Error] Lua chon cua ban khong dung!" << endl;
            system("pause");
        }
        else if (luaChon == 1)
        {
            int x;
            cout << "\n+ Nhap vao so nguyen duong: ";
            cin >> x;
            node *p = khoiTaoNODE(x);
            themDau(head, p);
        }
        else if (luaChon == 2)
        {
            cout << "\nDanh sach NODE: ";
            xuatDanhSach(head);
            system("pause");
        }
        else if (luaChon == 3)
        {
            sapXepGiam(head);
        }
        else if (luaChon == 4)
        {
            xuatSoDoiXung(head);
            system("pause");
        }
        else if (luaChon == 5)
            xoaDau(head);
        else if (luaChon == 6)
        {
            int x;
            cout << "\n+ Nhap vao node x can xoa: ";
            cin >> x;
            xoaNODESauQ(head, x);
        }
        else
            return;
    }
}

int main()
{
    node *head = NULL;
    menu(head);
    system("pause");
    return 0;
}