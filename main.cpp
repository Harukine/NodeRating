#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iterator>

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
	Edge(short from, short to, short comm_chan)
	{
		_from = from;
		_to = to;
		_comm_chan = comm_chan;
	}
	short int _from; // index of start edge
	short int _to; // index of end edge
	short int _comm_chan; // communication channel

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

Edge edgeParsed(string line){
	char type;
	short int from, to, cost;
	string comm;
	istringstream iss(line);
	iss >> type;
	iss >> from;
	iss >> to;
	iss >> comm;
	if (comm == "Phone"){
		cost = 100;
	} else if (comm == "Email") {
		cost = 80;
	} else if (comm == "Overbond") {
		cost = 50;
	} else {
		cost = 0;
	}
	return Edge(from, to, cost);
}

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
			Edge curEdge = edgeParsed(line);
			cout << curEdge._from << curEdge._to << curEdge._comm_chan << endl;
		}
	}
	else cout << "Unable to open file, incorrect directory" << endl;



	return 0;
}