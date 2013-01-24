#pragma once

class Node
{

public:

    Node(int iValue = -1);
    ~Node();

private:

    void addEdge(Node& rOtherNode, bool bDirected);
    Node& operator= (const Node&) {return *this;} //avoid warning

    const int m_iValue;
    std::list<Node*> m_aNeighbors;

    friend class Graph;
};

class Graph
{

public:

    Graph(bool bDirected);
    ~Graph();

    Node& addNode(int iValue);
    void addEdge(Node& rNodeA, Node& rNodeB);

    Node* BFS(const Node& rStart, int iValue) const;
    Node* DFS(const Node& rStart, int iValue) const;

private:

    typedef std::vector<Node*> tNodes;
    typedef std::set<Node*> tNodeSet;
    typedef std::list<Node*> tNodeList;

    tNodes      m_aNodes;
    const bool  m_bDirected;

    Graph& operator=(const Graph&) {return *this;}


    Node* BFS(tNodeSet& rPendingNodes, tNodeSet& rVisited, int iValue) const;
    //Node* DFS(tNodeSet& rPendingNodes, int iValue, tVisited& rVisited) const;


};

