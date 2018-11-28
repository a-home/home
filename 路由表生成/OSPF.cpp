#include"stdafx.h"
#include"OSPF.h"
#include"iostream"
#define MAX 10000
using namespace std;
void dijkstra(G *h, int v) {
	int n = h->vertices.getsize();
	int *S = new int [n];
	int *distance = new int[n];
	int *path = new int[n];
	for (int i = 0;i < n;i++) {
		distance[i] = h->edge[v][i];
		S[i] = 0;
		if (i != v&&distance[i] < MAX)path[i] = v;
		else path[i] = -1;
	}
	S[v] = 1;
	for (int i = 1;i < n;i++) {
		int min = MAX;
		int x;
		for (int j = 0;j < n;j++) {
			if (S[j] == 0 && distance[j] < min) {
				x = j;
				min = distance[j];
			}
		}
			if (min == MAX) { 
				break; }
			S[x] = 1;
			for (int j = 0;j < n;j++) {
				if (S[j] == 0 && h->edge[x][j] < MAX&&distance[x] + h->edge[x][j] < distance[j]) {
					distance[j] = distance[x] + h->edge[x][j];
					path[j] = x;
				}
			}
		}
	
	cout << "目的路由"<<"\t"<<"下一跳路由" << endl;
	for (int i = 0;i < n;i++) {
		if (i == v)continue;
		int j = i;
		while (path[j] != v) {
			j = path[j];
			if (j == -1)break;
		}
		cout << "   "<< h->vertices.getv(i) << "\t\t    " << h->vertices.getv(j)<<endl;
	}
};