// 路由表生成.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"iostream"
#include"list.h"
#include"G.h"
#include"OSPF.h"
using namespace std;
G g;
int a[MAXSIZE];
rcw x[100];
void menu() {
	int p;
	void putlist();
	void Deletevertex();
	void Deleteedge();
	void lnsertedge();
	void lnsertvertex();
	cout << "****************请选择相应功能****************" << endl;
	cout << "****************1.路由表输出****************" << endl;
	cout << "****************2.删除节点****************" << endl;
	cout << "****************3.删除边****************" << endl;
	cout << "****************4.添加边****************" << endl;
	cout << "****************5.添加点****************" << endl;
	cout << "****************6.退出****************" << endl;
	cout << "请输入你的选择(1~6)" << endl;
	cin >> p;
	if (p < 1 || p > 6) {
		cout << endl << "输入序号不属于菜单,请重新输入" << endl;
		p = 7;
	}
	switch (p) {
	case 1:putlist();break;
	case 2:Deletevertex();break;
	case 3:Deleteedge();break;
	case 4:lnsertedge();break;
	case 5:lnsertvertex();break;
	case 6:exit(0);break;
	case 7:menu();
	}
}
void putlist() {
	int i, j;
	cout << "请输入你要生成的路由表的启示路由" << endl;
	cin >> i;
	i--;
	dijkstra(&g, i);
	menu();
}
void Deletevertex() {
	int i;
	cout << "请输入你要删除的是第几个顶点" << endl;
	cin >> i;
	deletevertice(&g, i);
	menu();
}
void Deleteedge() {
	int i, j;
	cout << "请输入你要删除的边的两个顶点v1,v2" << endl;
	cin >> i;
	cin >> j;
	deleteedge(&g, i-1, j-1);
	menu();
}
void lnsertedge() {
	int i, j, w;
	cout << "请输入你要加入的边的两个顶点和权值" << endl;
	cin >> i;
	cin >> j;
	cin >> w;
	insertedge(&g, i, j, w);
	menu();
}
void lnsertvertex() {
	int i;
	cout << "请输入你想加入的节点" << endl;
	cin >> i;
	inisertvertice(&g, i);
	menu();
}

int main()
{
	int i, j, k;
	FILE *fp;
	 fopen_s(&fp,"d:\\101.txt", "r");
	 fscanf_s(fp, "%d", &i);
	for (k = 0;k < i;k++) {
		fscanf_s(fp, "%d", &a[k]);
	}
	fscanf_s(fp, "%d", &j);
	for (int k = 0;k < j;k++) {
		fscanf_s(fp, "%d %d %d", &x[k].row, &x[k].col, &x[k].weight);
	}
	fclose(fp);
	Glinitiate(&g);
	createG(&g, a, x, j, i);
	menu();
	

    return 0;
}

