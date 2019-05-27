#include <iostream>
#include "Dijkstra.h"

using namespace std;

Dijkstra::Dijkstra(int Number)
{
	NodeNumber = Number;
	weight = -1;
}

Dijkstra::Dijkstra(const Dijkstra &ToBeCopied)
{
	NodeNumber = ToBeCopied.NodeNumber;
	weight = ToBeCopied.weight;
	Path = ToBeCopied.Path;
	checked = ToBeCopied.checked;
}

void Dijkstra::setNodeNumber(int number)
{
	NodeNumber = number;
}

double Dijkstra::getNodeNumber()
{
	return NodeNumber;
}

void Dijkstra::setWeight(double W)
{
	weight = W;
}

double Dijkstra::getWeight()
{
	return weight;
}

void Dijkstra::addNodeToPath(double Node_number)
{
	Path.push_back(Node_number);
}

void Dijkstra::changePath(Dijkstra NewPathNode)
{
	Path = NewPathNode.Path;
	Path.push_back(NewPathNode.getNodeNumber());
}

vector<double> Dijkstra::getPath()
{
	return Path;
}

void Dijkstra::printPath()
{
	for (size_t i = 0; i < Path.size(); i++)
		cout << Path[i] + 1 << " -> ";

	cout << NodeNumber + 1 << endl;

	cout << "Вес маршрута: " << weight << endl;

}