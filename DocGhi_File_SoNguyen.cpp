#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

/*
1. Khoi tao cau truc danh sach lien ket don cac so nguyen va doc du lieu tu file
2. Xuat cac so chinh phuong
3. Tim phan tu lon nhat va ghi vao file KetQua.txt
4. Sap xep danh sach lien ket don cac so nguyen tang dan va ghi vao file SapXepTangDan.txt
Note: Doc file tu file InPut.txt
*/
struct node
{
    int data;
    node *next;
};

node *khoiTaoNode(int n)
{
    node *p = new node;
    if (p == NULL)
    {
        cout << "\nKhong du bo nho cap phat!" << endl;
        return NULL;
    }
    p->data = n;
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

void themCuoi(node *&head, node *p)
{
    if (head == NULL)
        head = p;
    else
    {
        for (node *i = head; i != NULL; i = i->next)
        {
            if (i->next == NULL)
            {
                i->next = p;
                break;
            }
        }
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
    node *i = NULL;
    while (head != NULL)
    {
        i = head;
        head = head->next;
        delete i;
    }
}

bool ktrSoChinhPhuong(int n)
{
    int x = sqrt(n);
    if (x * x == n)
        return true;
    else
        return false;
}

void xuatCacSoChinhPhuong(node *head)
{
    for (node *i = head; i != NULL; i = i->next)
    {
        if (ktrSoChinhPhuong(i->data))
            cout << i->data << " ";
    }
}

void ghiFilePhanTuMax(node *head, ofstream &fileOut)
{
    int max = head->data;
    for (node *i = head; i != NULL; i = i->next)
    {
        if (max < i->data)
            max = i->data;
    }
    fileOut << max;
}

void sapXepTang(node *&head)
{
    for (node *i = head; i != NULL; i = i->next)
    {
        for (node *j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void ghiFileTang(node *head, ofstream &fileOut, int n)
{
    sapXepTang(head);
    fileOut << n << endl;
    for (node *i = head; i != NULL; i=i->next)
    {
        fileOut << i->data << " ";
    }
}

int main()
{
    node *head = NULL; // khoi tao con tro dau de quan li danh sach lien ket don cac so nguyen
    int n;
    ifstream fileIn;
    ofstream fileOut;

    fileIn.open("D:\\DanhSachLienKet_Cpp\\InPut.txt", ios_base::in);
    if (fileIn.fail())
    {
        cout << "\nFile khong ton tai!" << endl;
        return 0;
    }
    fileIn >> n;

    for (int i = 1; i <= n; i++)
    {
        int x;
        fileIn >> x;
        node *p = khoiTaoNode(x);
        themDau(head, p);
    }
    cout << "Danh sach cac so nguyen: ";
    xuatDanhSach(head);
    cout << "\nCac so chinh phuong la: ";
    xuatCacSoChinhPhuong(head);

    fileOut.open("D:\\DanhSachLienKet_Cpp\\KetQua.txt", ios_base::out);
    ghiFilePhanTuMax(head, fileOut);
    fileOut.close();
    fileOut.open("D:\\DanhSachLienKet_Cpp\\SapXepTang.txt", ios_base::out);
    ghiFileTang(head, fileOut, n);
    
    giaiPhongVungNho(head);
    fileOut.close();
    fileIn.close();
    system("pause");
    return 0;
}