#include "PCH.h"

#include "Graph.h"

int main (int, char*[])
{
    Graph aGraph(false);

    Node& rNode1 = aGraph.addNode(1);
    Node& rNode2 = aGraph.addNode(2);
    Node& rNode3 = aGraph.addNode(3);
    Node& rNode4 = aGraph.addNode(4);
    Node& rNode5 = aGraph.addNode(5);
    Node& rNode6 = aGraph.addNode(6);

    aGraph.addEdge(rNode1, rNode1);
    aGraph.addEdge(rNode1, rNode2);
    aGraph.addEdge(rNode1, rNode5);

    aGraph.addEdge(rNode2, rNode1);
    aGraph.addEdge(rNode2, rNode3);
    aGraph.addEdge(rNode2, rNode5);

    aGraph.addEdge(rNode3, rNode2);
    aGraph.addEdge(rNode3, rNode4);

    aGraph.addEdge(rNode4, rNode3);
    aGraph.addEdge(rNode4, rNode5);
    aGraph.addEdge(rNode4, rNode6);

    aGraph.addEdge(rNode5, rNode1);
    aGraph.addEdge(rNode5, rNode2);
    aGraph.addEdge(rNode5, rNode4);

    aGraph.addEdge(rNode6, rNode4);

    std::cout << "Breadth first search: ";
    aGraph.search<Graph::BFS>(rNode1, 54);
    std::cout << std::endl;

    std::cout << "Depth first search: ";
    aGraph.search<Graph::DFS>(rNode1, 54);
    std::cout << std::endl;


    return 0;
}