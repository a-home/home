// ConsoleApplication63.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int b() { return 5; }
int main()
{
	int *a ;
	a = new int[5];
	int i = 0;
	while (i < 5) {
		a[i] = i;
		
	}
    return 0;
}

