#pragma once
#ifndef LIST_H
#define LIST_H
#define MAXSIZE 10
class list {
private:
	int seqlist[MAXSIZE];
	int size;
public:
	list();
	list(int a[],int n);
	int getsize();
	int islistempty();
	int islistfull();
	int insertlist(int x);
	int deletelist(int i);
	int listget(int x);
	int getv(int x);
};
#endif
