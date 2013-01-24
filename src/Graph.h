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
    
    enum tSearchMethod
    {
        BFS,
        DFS
    };

    Graph(bool bDirected);
    ~Graph();

    Node& addNode(int iValue);
    void addEdge(Node& rNodeA, Node& rNodeB);

    template<tSearchMethod SEARCHMETHOD>
    Node* search(const Node& rStart, int iValue) const;

    
private:
    

    typedef std::vector<Node*> tNodes;
    typedef std::set<Node*> tNodeSet;
    typedef std::list<Node*> tNodeList;

    tNodes      m_aNodes;
    const bool  m_bDirected;

    Graph& operator=(const Graph&) {return *this;}

    template<tSearchMethod SEARCHMETHOD>
    Node* search(tNodeList& rNodeList, tNodeSet& rVisited, int iValue) const;

};

