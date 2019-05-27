#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

Matrix::Matrix(vector<vector<double>> m)
{
	matrix = m;
}

Matrix::Matrix(int n)
{
	vector<double> line;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			line.push_back(-1);

		matrix.push_back(line);
		line.clear();
	}
}

Matrix::~Matrix()
{

}

void Matrix::Fill()
{
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = i + 1; j < matrix.size(); j++)
		{
			double k;

			cout << "Введите вес ребра (" << i + 1 << ", " << j + 1 << ").\n" <<
				"Если такое ребро отсутствует, введите -1." << endl;

			cin >> k;
			if (k < 0)
				k = -1;
			matrix[i][j] = matrix[j][i] = k;
		}
	}
}

void Matrix::Fill(string &Name)
{
	size_t size;
	matrix.clear();

	ifstream inp(Name);

	inp >> size;

	matrix.resize(size);
	for (size_t i = 0; i < size; i++)
	{
		matrix[i].resize(size);
	}
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			inp >> matrix[i][j];
		}
	}
}

void Matrix::Set()
{
	for (size_t i = 0; i < matrix.size(); i++)
		matrix[i][i] = -1;
}

void Matrix::Output()
{
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix.size(); j++)
		{
			cout << setw(5) << matrix[i][j] << "  ";
		}
		cout << "\n";
	}
}

size_t Matrix::getSize()
{
	return matrix.size();
}

vector<vector<double>> Matrix::getMatrix()
{
	return matrix;
}