// T1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template < class T>
class arrList {
private:
	T *aList;
	int maxSize;
	int position;

public:
	arrList(const int size) {
		maxSize = size;
		aList = new T[maxSize];
		for (int i = 0; i < maxSize; i++)
			aList[i] = i + 1;
	}

	bool outnum() {
		cout << "s=";
		int s;
		cin >> s;
		s = s - 1;
		cout << "m=";
		int m;
		cin >> m;
		int k = 1;
//		cout << aList[s]<<",";
//		aList[s] = 0;
		//若开始报数者也退出队列 则
		while (1)
		{
			for (int j = 0; j < m;) {
				s = (s + 1) % maxSize;
				if (aList[s] != 0)
					j++;
			}
			if (k == maxSize) {
				cout << aList[s] << endl;
				break;
			}
			cout << aList[s] << ",";
			aList[s] = 0;
			k++;
		}
		return true;
	};
};

int main() {
	int n;
	cout << "n=" << endl;
	cin >> n;
	arrList<int>data(n);
	 data.outnum();
	 system("pause");
		return 0;
}