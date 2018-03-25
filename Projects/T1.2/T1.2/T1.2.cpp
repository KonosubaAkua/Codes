// T1.2.cpp : �������̨Ӧ�ó������ڵ㡣
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
	Link<T> *cPos; //��ǰ�ڵ�
	Link<T> *prePos;//�����ڵ�
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
Link<T>*InkList<T>::setPos(int i)//�ҵ�ǰ�ڵ� ���ش�����ڵ�
{
	int count = 1;
	if (i < 0 || i == 0)
		cout << "����"<<endl;
	else
	{
		while (count < i)
		{
			cPos = cPos->next;
			prePos = prePos->next;
			count++;//��ͷβ��ʼ�ƶ�λ��
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
		cout << "��" << endl;
		return false;
	}
	cout << cPos->data << endl;

	cPos = p->next;
	prePos->next = cPos;//������

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
	cout << "������=" << endl;
	cin >> n;
	cout << "��ʼλ��=" << endl;
	cin >> s;
	cout << "���=" << endl;
	cin >> m;

	InkList<int>listfangshi(n);
	listfangshi.del(s - 2 + m);//��λɾ����һ�� ���豣����һ������ ��ȥ��-2����������㲻�˳������Ķ���
	while (listfangshi.isEmpty())//�ڿձ�֮ǰ��ȡɾ��
	{
		listfangshi.del(m);
	}
	system("pause");
	return 0;
}