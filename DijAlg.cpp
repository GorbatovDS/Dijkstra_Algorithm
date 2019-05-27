#include <iostream>
#include "Dijkstra.h"
#include "Matrix.h"

using namespace std;

int FindMin(vector<Dijkstra> Graph, size_t amount)
{
	int min;

	for (size_t i = 0; i <amount; i++)
		if ((Graph[i].getWeight() >= 0) && (!Graph[i].checked))
		{
			min = i;
			break;
		}

	for (size_t i = 0; i < amount; i++)
		if ((Graph[i].getWeight() >= 0) && (!Graph[i].checked) && (Graph[i].getWeight() < Graph[min].getWeight()))
			min = i;

	return min;
}

void DijkstraAlgorithm(vector<Dijkstra> &Graph, Matrix M, int StartNodeNumber)
{
	size_t amount = M.getSize();
	int k = StartNodeNumber - 1;
	int checked_amount = 0;

	Graph[StartNodeNumber - 1].setWeight(0);

	while (amount - checked_amount > 1)
	{
		for (size_t j = 0; j < amount; j++)
		{
			if ((M.getMatrix()[k][j] >= 0) && (!Graph[j].checked))
			{
				if ((Graph[j].getWeight() < 0) || (Graph[j].getWeight() > (Graph[k].getWeight() + M.getMatrix()[k][j])))
				{
					Graph[j].setWeight(Graph[k].getWeight() + M.getMatrix()[k][j]);
					Graph[j].changePath(Graph[k]);
				}
			}
		}

		Graph[k].checked = true;
		++checked_amount;
		k = FindMin(Graph, amount);
	}

}