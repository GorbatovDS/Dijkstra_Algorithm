#pragma once
#include <vector>

using namespace std;

class Dijkstra
{
private:
	int NodeNumber;
	double weight;//-1 for infinity, 0 if it's starting node, else - >0 value
	vector<double> Path;//node numbers from start to current node


public:
	bool checked = false;

	Dijkstra(int Number);
	Dijkstra(const Dijkstra &ToBeCopied);
	~Dijkstra() {};

	void setNodeNumber(int number);
	double getNodeNumber();
	double getWeight();
	void setWeight(double W);
	void addNodeToPath(double Node_number);
	void changePath(Dijkstra NewPathNode);
	vector<double> getPath();
	void printPath();
};