#include <iostream>
#include <locale.h>
#include "Dijkstra.h"
#include "Matrix.h"

using namespace std;

string Name_In = "SampleIn.txt";

int main()
{
	setlocale(LC_ALL, "rus");
	setlocale(LC_NUMERIC, "eng");

	int buf;
	vector<Dijkstra> Graph;
	int n = 0;
	



	Matrix m(n);
	//cout << "¬ведите количество вершин графа: ";
	//cin >> n;
	//m.Fill();
	m.Fill(Name_In);
	m.Set();
	m.Output();
	n = m.getSize();

	for (int i = 0; i < n; i++)
	{
		Dijkstra Node(i);
		Graph.push_back(Node);
	}

	cout << "¬ведите номер начальной вершины: ";
	cin >> buf;

	DijkstraAlgorithm(Graph, m, buf);

	for(int i = 0; i < n; i++)
		Graph[i].printPath();

	system("pause");
	return 0;
}
