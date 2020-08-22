#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct date
{
	int dd, mm, yy;
};

struct sinhVien
{
	string name, MSSV;
	float diem;
	date birth;
};

struct node
{
	sinhVien data;
	node* next;
};

struct list
{
	node* head;
	node* tail;
};

node* createNode(sinhVien x)
{
	node* p = new node;
	if (p == NULL)
	{
		cout << "\nNot enough memory allocated!" << endl;
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}

void createList(list& l)
{
	l.head = l.tail = NULL;
}

void readddmmyy(ifstream& input, date& date)
{
	input >> date.dd;
	input.seekg(1, 1);
	input >> date.mm;
	input.seekg(1, 1);
	input >> date.yy;
}

void addHead(list& l, node* p)
{
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}
}

void addTail(list& l, node* p)
{
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

void readInforStudent(ifstream& input, sinhVien& sv)
{
	getline(input, sv.name, ',');
	input.seekg(1, 1);
	getline(input, sv.MSSV, ',');
	input.seekg(1, 1);
	readddmmyy(input, sv.birth);
	input.seekg(1, 1);
	input >> sv.diem;

	string endLine;
	getline(input, endLine); // lay dau xuong dong o cuoi
}

void readListStudents(ifstream& input, list& l)
{
	while (!input.eof())
	{
		sinhVien sv;
		readInforStudent(input, sv);
		node* p = createNode(sv);
		addTail(l, p);
	}
}

void removeList(list& l)
{
	node* p = NULL;
	while (l.head != NULL)
	{
		p = l.head;
		l.head = l.head->next;
		delete p;
	}
}

void writeInforStudent(ofstream& outPut, sinhVien sv)
{
	outPut << sv.name << ", ";
	outPut << sv.MSSV << ", ";
	outPut << sv.birth.dd << "/" << sv.birth.mm << "/" << sv.birth.yy << ", ";
	outPut << sv.diem;
}

void hoanVi(sinhVien& x, sinhVien& y)
{
	sinhVien temp = x;
	x = y;
	y = temp;
}

void sortUp(list& l)
{
	for (node* i = l.head; i != NULL; i = i->next)
	{
		for (node* j = i->next; j != NULL; j = j->next)
		{
			if (j->data.diem > i->data.diem)
				hoanVi(i->data, j->data);
		}
	}
}

void writeFileScoreUp(list l)
{
	ofstream outPut;
	outPut.open("SapXepDiemTangDan.txt", ios_base::app);
	sortUp(l);
	for (node* i = l.head; i != NULL; i = i->next)
	{
		writeInforStudent(outPut, i->data);
		outPut << endl;
	}
	outPut<< "-------------------------" << endl;
	outPut.close();
}

void writeFileScoreMax(list l)
{
	float max = l.head->data.diem;
	for (node* i = l.head; i != NULL; i = i->next)
	{
		if (max < i->data.diem)
			max = i->data.diem;
	}
	ofstream outPut;
	outPut.open("DiemMax.txt", ios_base::app);
	for (node* i = l.head; i != NULL; i = i->next)
	{
		if (max == i->data.diem)
		{
			writeInforStudent(outPut, i->data);
			outPut << endl;
		}
	}
	outPut << "-------------------------" << endl;
	outPut.close();
}

void showInforStudent1(sinhVien sv)
{
	cout << "\nHo & Ten: " << sv.name << endl;
	cout << "MSSV: " << sv.MSSV << endl;
	cout << "Birth: " << sv.birth.dd << "/" << sv.birth.mm << "/" << sv.birth.yy << endl;
	cout << "Diem: " << sv.diem << endl;
}

void showInforStudent(sinhVien sv)
{
	cout << setw(13) << left << sv.name << "\t";
	cout << setw(10) << left << sv.MSSV << "\t";
	cout << setw(10) << left << sv.birth.dd << "/" << sv.birth.mm << "/" << sv.birth.yy << "\t";
	cout << setw(4) << left << sv.diem << "\t" << endl;
}

void showListStudents(list l)
{
	int dem = 1;
	for (node* i = l.head; i != NULL; i = i->next)
	{
		//cout << "\n\n\t==== SINH VIEN THU " << dem++ << " ====" << endl;
		showInforStudent(i->data);
	}
}

string nameStudent(string tenSV)
{
	int length = tenSV.length(); // duyet tu cuoi chuoi ve dau chuoi. Vd: do van kha. Duyet den chu 'k' thi dung.
	int i;
	for (i = length - 1; i >= 0; i--)
	{
		if (tenSV[i] == ' ')
			break;
	}
	return tenSV.substr(i + 1);  // cat tai vi tri i + 1 ve den cuoi chuoi. vd: cat tu chu 'k' = kha.
}

void findName(list l, string tenSV)
{
	for (node* i = l.head; i != NULL; i = i->next)
	{
		string ten = nameStudent(i->data.name);
		if (_stricmp((char*)ten.c_str(), (char*)tenSV.c_str()) == 0)
		{
			showInforStudent1(i->data);
			cout << endl;
		}
	}
}

void findMSSV(list l, string MSSV)
{
	for (node* i = l.head; i != NULL; i = i->next)
	{
		string mssv = nameStudent(i->data.MSSV);
		if (stricmp((char*)mssv.c_str(), (char*)MSSV.c_str()) == 0)
		{
			showInforStudent1(i->data);
			cout << endl;
		}
	}
}

int main()
{
	list l;
	string tenSV, MSSV;
	createList(l);
	ifstream input;
	input.open("D:\\DanhSachLienKet_Cpp\\SinhVien.txt", ios_base::in);
	readListStudents(input, l);
	cout << "\n" << setw(13) << left << "Ho & ten" << "\t" << setw(10) << left << "MSSV" << "\t" << setw(10) << left << "dd/mm/yy" << "\t\t" << setw(4) << left << "Diem" << endl;
	showListStudents(l);

	writeFileScoreUp(l);
	writeFileScoreMax(l);

	cout << "\nEnter name need look for: ";
	getline(cin, tenSV);
	findName(l, tenSV);

	cout << "\nEnter student code need look for: ";
	getline(cin, MSSV);
	findMSSV(l, MSSV);

	removeList(l);
	input.close();
	system("pause");
	return 0;
}