#pragma once
#include <vector>
#include "Dijkstra.h"

using namespace std;

class Matrix
{
private:
	vector<vector<double>> matrix;

public:
	Matrix(vector<vector<double>> m);
	Matrix(int n);
	~Matrix();
	void Fill();
	void Fill(string &Name);
	void Set();
	void Output();
	size_t getSize();
	vector<vector<double>> getMatrix();
};

extern void DijkstraAlgorithm(vector<Dijkstra> &Graph, Matrix matrix, int StartNodeNumber);