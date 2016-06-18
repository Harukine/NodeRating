#include <iostream>
#include <string>
using namespace std;


class Node
{
public:
	int index;   // index of node
	string institution;  // institution type of node
	int edges; // edges of the node
	double rating; // rate of the node

};

class Edge
{
public:
	int from; // index of start edge
	int to; // index of end edge
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}