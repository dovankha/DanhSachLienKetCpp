#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

string getPhanTu(string& bieuThuc)
{
	int size = bieuThuc.size();
	string kqua;
	if (bieuThuc[0] == '(' || bieuThuc[0] == ')')
	{
		kqua.resize(1);
		kqua = bieuThuc[0];
		bieuThuc.erase(0, 1);
		return kqua;
	}
	if (bieuThuc[0] == '+' || bieuThuc[0] == '-' || bieuThuc[0] == '*' || bieuThuc[0] == '/')
	{
		kqua.resize(1);
		kqua = bieuThuc[0];
		bieuThuc.erase(0, 1);
		return kqua;
	}
	int i = 0;
	while (i < size)
	{
		if (bieuThuc[i] >= '0' && bieuThuc[i] <= '9' || bieuThuc[i] == '.')
		{
			kqua.resize(i++);
			kqua[i] = bieuThuc[i];
		}
		else
			break;
		i++;
	}
	bieuThuc.erase(0, i);
	return kqua;
}

int checkPhanTu(string temp)
{
	if (temp == "+" || temp == "-" || temp == "*" || temp == "/")
		return 1;
	else
	{
		if (temp == "(" || temp == ")")
			return -1;
		else
			return 0;
	}
}

int giaTri(string o)
{
	if (o == "*" || o == "/")
		return 2;
	if (o == "+" || o == "-")
		return 1;
}

void chuyenBaLan(string bieuThuc, stack<string>& myStack, queue<string>& myQueue)
{
	while (!bieuThuc.empty())
	{
		string temp = getPhanTu(bieuThuc);
		if (checkPhanTu(temp) == 0)
			myQueue.push(temp);
		else
		{
			if (checkPhanTu(temp) == 1)
			{
				while (!myStack.empty())
				{
					if (checkPhanTu(myStack.top()) == 1 && giaTri(myStack.top()) >= giaTri(temp))
					{
						myQueue.push(myStack.top());
						myStack.pop();
					}
					else
						break;
				}
				myStack.push(temp);
			}
			else
			{
				if (temp == "(")
					myStack.push(temp);
				else
				{
					if (temp == ")")
					{
						while (!myStack.empty())
						{
							if (myStack.top() != "(")
							{
								myQueue.push(myStack.top());
								myStack.pop();
							}
							else
								break;
						}
						myStack.pop();
					}
				}
			}
		}
	}
	while (!myStack.empty())
	{
		myQueue.push(myStack.top());
		myStack.pop();
	}
}

float tinhKqua(string dau, float a, float b)
{
	if (dau == "+")
		return a + b;
	if (dau == "-")
		return a - b;
	if (dau == "*")
		return a * b;
	if (dau == "/")
		return a / b;
}

float ketQua(queue<string> myQueue, stack<float> myStack2)
{
	float kqua = 0;
	while (!myQueue.empty())
	{
		string tmp = myQueue.front();
		myQueue.pop();
		if (checkPhanTu(tmp) == 0)
			myStack2.push(stof(tmp));
		else
		{
			if (myStack2.size() <= 2)
			{
				cout << "\nLoi bieu thuc." << endl;
				return 0;
			}
			else
			{
				float num1 = myStack2.top();
				myStack2.pop();
				float num2 = myStack2.top();
				myStack2.pop();
				kqua = tinhKqua(tmp, num2, num1);
				myStack2.push(kqua);
			}
		}
	}
	return kqua;
}

int main()
{
	string bieuThuc;
	cout << "\nMoi nhap vao bieu thuc: ";
	getline(cin, bieuThuc);
	stack<string> myStack1;
	queue<string> myQueue;
	chuyenBaLan(bieuThuc, myStack1, myQueue);
	stack<float> myStack2;
	float kq = ketQua(myQueue, myStack2);
	cout << "\nKet qua la: " << kq << endl;

	system("pause");
	return 0;
}