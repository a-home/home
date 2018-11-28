#include"stdafx.h"
#include"list.h"
#include"iostream"
using namespace std;
¼Ö´ó½ã´ó½ãµÄ
list::list() {
	for (int i = 0;i < MAXSIZE;i++) {
		seqlist[i] = 0;
	}
	size = 0;
}
list::list(int a[],int n) {
	size = 0;
	for (int i = 0;i < n;i++) {
		seqlist[i] = a[i];
		size++;
	}
}
int list::islistempty() {
	if (size == 0) { return 1; }
	else { return 0; }
}
int list::islistfull() {
	if (size == MAXSIZE) { return 1; }
	else { return 0; }
}
int list::insertlist(int x) {
	if (islistfull() == 0) {
		seqlist[size] = x;
		size++;
		return 1;
	}
	else {
		return 0;
	}
}
int list::deletelist(int x) {
	if (islistempty() == 0) {
		int j = 0;
		while (seqlist[j] != x&&j<size) {
			j++;
		}
		if (j < size) {
			while (j < size) {
				seqlist[j] = seqlist[j + 1];
				j++;
			}
			size--;
			return 1;
		}
		else { return 0; }
	}
	else {
		return 0;
	}
}
int list::listget(int x) {
	int j = 0;
	while (seqlist[j] != x&&j<size) {
		j++;
	}
	if (j < size) { return 1; }
	else { return 0; }
}
int list::getsize() { return size; }
int list::getv(int v) { return seqlist[v]; }