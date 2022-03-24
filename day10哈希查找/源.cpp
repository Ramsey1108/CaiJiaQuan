#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
	char* a;
	cin >> a;
	int a[] = { 0,1,1,2,2,3,1,1,2 };
	for (int i = 0; i < 9; i++)
	{
		printf("%2d", a[i]);
	}
	return 0;
}