#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iterator>
#include <map>

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
	Edge(int from, int to, int comm_chan)
	{
		_from = from;
		_to = to;
		_comm_chan = comm_chan;
	}
	int _from; // index of start edge
	int _to; // index of end edge
	int _comm_chan; // communication channel

};
class Node
{
public:
	Node(int key, int inst_type){
		_key = key;
		_inst_type = inst_type;
	}
	int _key;   // key of node
	int _inst_type;  // institution type of node
};

class NodeSet
{
public:
	double cost;
	Node node;

};

Node nodeParsed(string line){
	int key, inst_type;
	string inst;
	istringstream iss(line);
	iss >> key;
	iss >> inst;
	if (inst == "Dealer"){
		inst_type = 1;
	} else if (inst == "Investor") {
		inst_type = 2;
	} else if (inst == "Issuer") {
		inst_type = 3;
	} else {
		inst_type = 0;
	}
	return Node(key, inst_type);
}
Edge edgeParsed(string line){
	char type;
	int from, to, cost;
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

	map<int, int> world_nodes;
	ifstream nodes_world ("nodes_world.txt"), edges_world ("edges_world.clq");
	ofstream result;
	string line;

	/**
	 * Reads all nodes from text and adds it to a map
	 */
	if(nodes_world.is_open())
	{
		while ( getline (nodes_world, line) )
		{
			Node curNode = nodeParsed(line);
			world_nodes[curNode._key] = curNode._inst_type;
		}
	}
	else cout << "Unable to open file" << endl;
	nodes_world.close();

	/**
	 * Reads all the edges and sorts it
	 */
	if (edges_world.is_open())
	{
		getline (edges_world, line);
		while ( getline (edges_world, line) )
		{
			Edge curEdge = edgeParsed(line);
//			cout << curEdge._from << curEdge._to << curEdge._comm_chan << endl;
		}
	}
	else cout << "Unable to open file, incorrect directory" << endl;
	edges_world.close();

	cout << world_nodes.size();

	return 0;
}