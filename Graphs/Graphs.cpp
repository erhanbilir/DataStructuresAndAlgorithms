#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Graph 
{
private:
	map<int, vector<int>> adjList;

public:
	// Function to add an edge between two vertices
	void addVertex(int vertex)
	{
		// Check if the vertex already exists in the adjacency list then do nothing
		if (adjList.find(vertex) == adjList.end() )
		{
			vector<int> neighbors; // A new neighbor vector for the vertex
			adjList[vertex] = neighbors; // Add the vertex with an empty neighbor list
		}
	}

	// Function to add an edge between two vertices
	void addEdge(int fromVertex, int toVertex)
	{
		// Add edge between two vertices
		// First check if the vertices exist in the adjacency list
		// if not, add them
		addVertex(fromVertex);
		addVertex(toVertex);

		// Now add the edge
		adjList[fromVertex].push_back(toVertex); // Add toVertex to the neighbors of fromVertex
		adjList[toVertex].push_back(fromVertex); // Add fromVertex to the neighbors of toVertex
	}


	void removeVertex(int vertex)
	{
		// Check if the vertex exists in the adjacency list
		if (adjList.find(vertex) != adjList.end())
		{
			// Get the neighbors of the vertex to be removed
			vector<int> neighbors = adjList[vertex]; // Get the neighbors of the vertex
			
			// Remove the vertex from the adjacency list
			adjList.erase(vertex); 

			// Iterate through each neighbor and remove the vertex from their neighbor list
			for (int neighborVertex : neighbors)
			{
				vector<int>& neighborList = adjList[neighborVertex];
				vector<int>::iterator vecIt = neighborList.begin();
				while (vecIt != neighborList.end())
				{
					if (*vecIt == vertex)
					{
						// erase() and insert() operations return an iterator to the next element
						vecIt = neighborList.erase(vecIt); // Remove the vertex from the neighbor list
					}
					else
					{
						++vecIt; // Move to the next neighbor
					}
				}
			}
		}
		else
		{
			cout << "Vertex " << vertex << " does not exist in the graph." << endl;
		}
	}

	void removeEdge(int fromVertex, int toVertex)
	{
		// Check if both vertices exist in the adjacency list
		if (adjList.find(fromVertex) != adjList.end() && adjList.find(toVertex) != adjList.end())
		{
			vector<int>& fromNeighbors = adjList[fromVertex];
			vector<int>& toNeighbors = adjList[toVertex];
			// Remove vertex2 from vertex1's neighbor list
			vector<int>::iterator it1 = fromNeighbors.begin();
			while (it1 != fromNeighbors.end())
			{
				if (*it1 == toVertex)
				{
					it1 = fromNeighbors.erase(it1); // Remove vertex2 from vertex1's neighbor list
				}
				else
				{
					++it1; // Move to the next neighbor
				}
			}

			// Remove vertex1 from vertex2's neighbor list
			vector<int>::iterator it2 = toNeighbors.begin();
			while (it2 != toNeighbors.end())
			{
				if (*it2 == fromVertex)
				{
					it2 = toNeighbors.erase(it2); // Remove vertex1 from vertex2's neighbor list
				}
				else
				{
					++it2; // Move to the next neighbor
				}
			}
		}
	}

	void printGraph()
	{
		// Print the adjacency list representation of the graph
		for (auto& pair : adjList)
		{
			cout << "Adjacent to vertex " << pair.first << " -> [" << pair.second.size() << "]: ";
			for (int& neighbor : pair.second)
			{
				cout << neighbor << ", ";
			}
			cout << endl;
		}
	}
};

int main(void)
{
	Graph g;
	// Create a graph with 5 vertices and some edges
	g.addVertex(1);
	g.addVertex(2);
	g.addVertex(3);
	g.addVertex(4);
	g.addVertex(5);

	// Add edges between the vertices
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 5);
	g.addEdge(4, 5);

	g.printGraph();

	g.removeVertex(1);
	cout << "------------\n After remove vertex 1 \n------------" << endl;
	g.printGraph();

	g.removeEdge(2, 4);
	cout << "------------\n After remove edge 2, 4 \n------------" << endl;
	g.printGraph();

	g.addVertex(8);
	g.addEdge(8, 2);
	g.addEdge(8, 4);
	cout << "------------\n After add vertex 8 and edges 8, 2 and 8, 4 \n------------" << endl;
	g.printGraph();

	return 0;
}