#pragma once
#ifndef G_H
#define G_H
#include"list.h"
typedef struct {
	list vertices;
	int edge[MAXSIZE][MAXSIZE];
	int numofedges;
}G;
typedef struct {
	int row;
	int col;
	int weight;
}rcw;
void Glinitiate(G *h);
void inisertvertice(G *h,int x);
void deletevertice(G *h, int x);
void insertedge(G *h, int v1, int v2, int weight);
void deleteedge(G *h, int v1, int v2);
void createG(G *h, int v[], rcw w[], int x,int n);

#endif