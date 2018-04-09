// 后缀表达式.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// Biaodashi.cpp : 定义控制台应用程序的入口点。
//


#include<iostream>
#include<stack>
#include<string>
using namespace std;


int lv(char ch) {
	switch (ch) {
	case '#':
		return 0;
		break;
	case '(':
		return 1;
		break;
	case '+':
	case '-':
		return 2;
		break;
	case '*':
	case '/':
		return 3;
		break;
	case ')':
		return 4;
		break;
	default:
		return -1;
		break;
	}

}


template<class T>
class Dueback
{
private:
	stack<double> s;
	bool GetTwo(double&opd1, double&opd2)
	{
		if (s.empty())
		{
			cerr << "missing operand" << endl;
			return false;
		}
		//		s.pop(&opd1);
		opd1 = s.top();
		s.pop();
		if (s.empty())
		{
			cerr << "missing operand" << endl;
			return false;
		}
		//		s.pop(&opd2);
		opd2 = s.top();
		s.pop();
		return true;
	}

	void compute(char op)
	{
		bool result;
		double oper1, oper2;
		result = GetTwo(oper1, oper2);
		if (result == true)
			switch (op) {
			case '+':s.push(oper2 + oper1);
				break;
			case '-':s.push(oper2 - oper1);
				break;
			case '*':s.push(oper2 * oper1);
				break;
			case '/':if (oper1 == 0.0) {
				cerr << "divide by 0" << endl;
				//		s.clear();
			}
					 else
						 s.push(oper2 / oper1);
				break;
			}
		//	else
		//		s.clear();
	}

public:
	//	Calculator(void) {};
	void Run(void) {
		char c;
		double newoper, res;
		while (cin >> c, c != '=') {
			switch (c) {
			case'+':case'-':case'*':case'/':
				compute(c);
				break;
			default:
				cin.putback(c);
				cin >> newoper;
				s.push(newoper);
				break;
			}
		}
		//	if (s.pop(&res))
		cout << s.top() << endl;
	}
};

template<class T>
class arrStack
{
private:
	int mSize;//栈的最大长度
	int top;//栈顶
	char *st;//顺序栈

public:
	arrStack()
	{
		mSize = 500;
		top = -1;
		st = new char[500];
	}

	bool push(char ch)
	{
		if (top == mSize - 1)
		{
			cout << "full" << endl;
			return false;
		}
		else
			st[++top] = ch;
		return true;
	}

	bool pop()
	{
		if (top == -1)
		{
			cout << "empty" << endl;
			return false;
		}
		else
			cout << st[top];
		--top;
		return true;
	}

	bool pop1()
	{
		if (top == -1)
		{
			cout << "enpty" << endl;
			return false;
		}
		else {
			--top;
			return true;
		}
	}

	bool sEmpty()
	{
		if (top == -1)
			return true;
		return false;
	}

	char gettop()
	{
		return st[top];
	}
};



int main()
{
	string str;
	char t;
	cout << "请输入以#结尾的中缀表达式:";
	while ((t = cin.get()) != '#')
	{
		str += t;
	}
	const int Len = str.length();
	char*p = new char(Len + 1);
	for (int i = 0; i < Len; i++)
	{
		p[i] = str[i];
	}
	p[Len] = '#';
	int i = 0;
	int flag = 0;
	int temp = -2;
	arrStack<char>f;
	cout << "得到的后缀表达式为：";
	while (temp == -2)
	{
		if (p[i] >= '0'&&p[i] <= '9' || p[i] >= 'a'&&p[i] <= 'z' || p[i] >= 'A'&&p[i] <= 'Z')
			cout << p[i];
		else
		{
			switch (lv(p[i]))
			{
			case 1:
				cout << " ";
				f.push(p[i]);
				break;
			case 4:
				cout << " ";
				if (f.sEmpty())
					break;
				else
				{
					while (f.gettop() != '(' && !f.sEmpty())
					{
						f.pop();
					}
					if (f.sEmpty())
						temp = -1;
					else f.pop1();
				}
				break;
			case 2:
				cout << " ";
				while (!f.sEmpty() && f.gettop() != '('&&lv(f.gettop()) >= 2) {
					f.pop();
					cout << " ";
				}
				if (f.sEmpty() || lv(f.gettop()) < 2)
					f.push(p[i]);
				break;
			case 3:
				cout << " ";
				while (!f.sEmpty() && f.gettop() != '('&&lv(f.gettop()) >= 3) {
					f.pop();
					cout << " ";
				}
				if (f.sEmpty() || lv(f.gettop()) < 3)
					f.push(p[i]);
				break;
			case 0:
				cout << " ";
				while (!f.sEmpty() && flag == 0) {
					if (f.gettop() == '(')
						flag = 1;
					else
					{
						f.pop();
						cout << " ";
						temp = 0;
					}
				}
				if (flag == 1)
					temp = -1;
				break;
			default:
				temp = -1;
			}
		}
		i++;
	}
	if (temp == -1)
	{
		cout << "error" << endl;
	}

	cout << "\n请将得到的后缀表达式以=结尾依次输入" << endl;
	Dueback<double>a;
	a.Run();
	system("pause");
	return 0;
}

