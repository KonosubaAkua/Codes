// T1.2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace std;

template<class T>
class Link
{
public:
	T data;
	Link<T> *next;
	Link(const Link<T> *nextx) {
		next = nextx;
	}
	Link() { data = 0, next = NULL; }
};

template<class T>
class InkList {
private:
	Link<T> *head;
	Link<T> *cPos; //当前节点
	Link<T> *prePos;//辅助节点
	Link<T> *setPos(const int p);
public:
	InkList(int s);
	~InkList();
	bool isEmpty();
	bool del(const int p);
};

template<class T>
InkList<T>::InkList(int defsize)
{
	Link<T>*tail;
	int i = 1;
	head = new Link<T>;
	head->data = i;
	tail = head;
	while (i < defsize)
	{
		tail->next = new Link<T>;
		tail = tail->next;
		i++;
		tail->data = i;
	}
	tail->next = head;

	cPos = head;
	prePos = tail;
}

template<class T>
InkList<T>::~InkList()
{
	Link<T>*temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

template<class T>
bool InkList<T>::isEmpty()
{
	if (head == NULL)
		return false;
	return true;
}

template<class T>
Link<T>*InkList<T>::setPos(int i)//找当前节点 传回待处理节点
{
	int count = 1;
	if (i < 0 || i == 0)
		cout << "错误"<<endl;
	else
	{
		while (count < i)
		{
			cPos = cPos->next;
			prePos = prePos->next;
			count++;//从头尾开始移动位置
		}
	}
	return cPos;
}

template<class T>
bool InkList<T>::del(const int i)
{
	Link<T>*p;
	p = setPos(i);
	if (p == NULL)
	{
		cout << "空" << endl;
		return false;
	}
	cout << cPos->data << endl;

	cPos = p->next;
	prePos->next = cPos;//新链表

	if (cPos == p)
	{
		delete p;
		head = NULL;
		cPos = prePos = NULL;
	}
	return true;
}


int main()
{
	int n, s, m;
	cout << "总人数=" << endl;
	cin >> n;
	cout << "起始位置=" << endl;
	cin >> s;
	cout << "间隔=" << endl;
	cin >> m;

	InkList<int>listfangshi(n);
	listfangshi.del(s - 2 + m);//定位删读第一个 如需保留第一个数字 则去掉-2（报数的起点不退出报数的队列
	while (listfangshi.isEmpty())//在空表之前读取删除
	{
		listfangshi.del(m);
	}
	system("pause");
	return 0;
}