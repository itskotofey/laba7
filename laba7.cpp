#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <iostream>
using namespace std;
int** a;
int i, j, n;
bool* visited;
//поиск в глубину
void DFS(int st)
{
	int r;
	cout << st + 1 << " ";
	visited[st] = true;
	for (r = 0; r <= n; r++)
		if ((a[st][r] != 0) && (!visited[r]))
			DFS(r);
}
//главная функция
int main()
{
	system("chcp 1251");
	system("cls");
	printf("Введите количество вершин: ");
	scanf("%d", &n);
	visited = new bool[n];
	a = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(n * sizeof(int));
	}
	srand(time(NULL));

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (i != j) {
				a[i][j] = rand() % 2;
				a[j][i] = a[i][j];
			}
			else a[i][j] = 0; // 
		}

	printf("\n");
	setlocale(LC_ALL, "Rus");
	int start;
	cout << "Матрица смежности графа: " << endl;
	for (i = 0; i < n; i++)
	{
		visited[i] = false;
		for (j = 0; j < n; j++)
			cout << " " << a[i][j];
		cout << endl;
	}
	cout << "Стартовая вершина >> "; cin >> start;
	//массив посещенных вершин
	//bool* vis = new bool[n];
	cout << "Порядок обхода: ";
	DFS(start - 1);
	delete[]visited;
	free(a);
	system("pause");
}
