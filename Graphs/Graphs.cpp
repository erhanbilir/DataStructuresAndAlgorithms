#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Graph 
{
private:
	map<int, vector<int>> adjList;

public:
	void addVertex(int vertex)
	{
		if (adjList.find(vertex) == adjList.end() )
		{
			vector<int> neighbors; // A new neighbor vector for the vertex
			adjList[vertex] = neighbors; // Add the vertex with an empty neighbor list
		}
	}
};

int main(void)
{
	Graph g;
	g.addVertex(1);
	g.addVertex(2);
	g.addVertex(3);
	g.addVertex(4);
	g.addVertex(5);

	return 0;
}