#include "PCH.h"

#include "Graph.h"

Node::Node(int iValue)
: m_iValue(iValue)
, m_aNeighbors()
{
}

Node::~Node()
{

}

void Node::addEdge(Node& rOtherNode, bool bDirected)
{
    std::list<Node*>::iterator itNode = std::find(m_aNeighbors.begin(), m_aNeighbors.end(), &rOtherNode);

    if (itNode ==  m_aNeighbors.end())
    {
        m_aNeighbors.push_front(&rOtherNode);
        if (this != &rOtherNode && !bDirected)
        {
            rOtherNode.addEdge(*this, false);
        }
    }
}


Graph::Graph(bool bDirected)
: m_bDirected(bDirected)
{
}

Graph::~Graph()
{
    BOOST_FOREACH(Node* pNode, m_aNodes)
    {
        delete pNode;
    }
}

Node& Graph::addNode(int iValue)
{
    Node* pNode = new Node(iValue);
    m_aNodes.push_back(pNode);
    return *pNode;
}

void Graph::addEdge(Node& rNodeA, Node& rNodeB)
{
    rNodeA.addEdge(rNodeB, m_bDirected);
}

template <Graph::tSearchMethod SEARCHMETHOD>
Node* Graph::search(const Node &rStart, int iValue) const
{
    tNodeList aNodeList;
    tNodeSet aVisited;

    aNodeList.push_front(const_cast<Node*>(&rStart));

    return search<SEARCHMETHOD>(aNodeList, aVisited, iValue);
}

template <Graph::tSearchMethod SEARCHMETHOD>
Node* Graph::search(tNodeList& rNodeList, tNodeSet& rVisited, int iValue) const
{
    while (!rNodeList.empty())
    {
        Node* pNode = SEARCHMETHOD == BFS ? rNodeList.front() : rNodeList.back();
        if (SEARCHMETHOD == BFS)
            rNodeList.pop_front();
        else if (SEARCHMETHOD == DFS)
            rNodeList.pop_back();
        
        
        if (pNode && rVisited.find(pNode) == rVisited.end())
        {
            std::cout << pNode->m_iValue << ", ";
            if (pNode->m_iValue == iValue)
            {
                return pNode;
            }
            rVisited.insert(pNode);
            
            BOOST_FOREACH(Node* pNextNode, pNode->m_aNeighbors)
            {
                if (pNextNode && rVisited.find(pNextNode) == rVisited.end())
                {
                    rNodeList.push_back(pNextNode);
                }
            }
        }
    }

    return NULL;
}


template Node* Graph::search<Graph::BFS>(const Node &rStart, int iValue) const;
template Node* Graph::search<Graph::BFS>(tNodeList& rNodeList, tNodeSet& rVisited, int iValue) const;

template Node* Graph::search<Graph::DFS>(const Node &rStart, int iValue) const;
template Node* Graph::search<Graph::DFS>(tNodeList& rNodeList, tNodeSet& rVisited, int iValue) const;

