#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum Entity : int
{
	dealer = 1,
	investor = 2,
	issuer = 3
};

class Edge
{
public:
	short int from; // index of start edge
	short int to; // index of end edge
	short int comm_chan; // communication channel
};

class Node
{
public:
	short int id;   // id of node
	string type;  // institution type of node
	short int edges; // edges of the node
	double rating; // rate of the node

};

class NodeSet
{
public:
	double cost;
	Node node;

};
int main() {

	char data;
	int count;
	ifstream nodes_world ("nodes_world.txt"), edges_world ("edges_world.clq");
	ofstream result;
	string line;

	if (edges_world.is_open())
	{
		getline (edges_world, line);
		while ( getline (edges_world, line) )
		{
			cout << line << '\n';
		}
	}
	else cout << "Unable to open file, incorrect directory" << endl;

	return 0;
}