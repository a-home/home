#include"stdafx.h"
#include"G.h"
#include"iostream"
#define MAX 10000
using namespace std;
void Glinitiate(G *h) {
	int i, j;
	for (i = 0;i < MAXSIZE;i++) {
		for (j = 0;j < MAXSIZE;j++) {
			if (i == j){
				h->edge[i][j] = 0;
			}
			else {
				h->edge[i][j] = h->edge[j][i] = MAX;
			}
		}
	}
	h->numofedges = 0;
};
void inisertvertice(G *h,int x) {
	if (h->vertices.insertlist(x) == 0) {
		cout << "插入顶点空间已满无法插入!"<<endl;
		return;
	}
};
void insertedge(G *h, int v1, int v2, int weight) {
	if (v1 != v2) {
		if (h->vertices.listget(v1+1) == 0 || h->vertices.listget(v2+1) == 0) {
			cout << "插入边时参数v1或v2发生越界错误 " << endl;
			return;
		}
		h->edge[v1][v2] = weight;
		h->edge[v2][v1] = weight;
	}
};
void deleteedge(G *h, int v1, int v2) {
	h->edge[v1][v2] = MAX;
	h->edge[v2][v1] = MAX;
	h->numofedges--;
};
void deletevertice(G *h, int x) {
	int v = x - 1,i,j;
	if (h->vertices.listget(x)==0) {
		cout << "此链路中无你想删除的路由节点" << endl;
	}
	else {
		for (i = v, j = 0;j < h->vertices.getsize()&&j!=v;j++) {
			h->edge[i][j] = MAX;
			h->edge[j][i] = MAX;
		}
		for (j = 0; j < h->vertices.getsize() - 1;j++) {
			h->edge[v][j] = h->edge[v + 1][j];
			h->edge[j][v] = h->edge[j][v + 1];
		}
		
		h->vertices.deletelist(x);
		cout << "删除节点成功" << endl;
	}
};
void createG(G *h, int v[], rcw w[], int x,int n) {
	int i, j;
	Glinitiate(h);
	for (i = 0;i < n;i++) {
		inisertvertice(h, v[i]);
	}
	for (j = 0;j < x;j++) {
		insertedge(h, w[j].row, w[j].col, w[j].weight);
	}
};