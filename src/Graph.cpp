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


Node* Graph::BFS(const Node &rStart, int iValue) const
{
    tNodeList aPending;
    tNodeSet aVisited;

    aPending.push_front(const_cast<Node*>(&rStart));

//    return BFS(aPending, iValue, aVisited);
}

//Node* Graph::(tNodeSet& rPendingNodes, tNodeSet& rVisited, int iValue) const
//{
//    BOOST_FOREACH(Node* pNode, rNodes)
//    {
//        std::cout << "Node: " << pNode->m_iValue << std::endl;
//        if (pNode && pNode->m_iValue != iValue)
//        {
//            tVisited::const_iterator itNode = rVisited.find(pNode);
//
//            if (itNode == rVisited.end() || itNode->second==false)
//            {
//                rVisited[pNode] = true;
//
//                BOOST_FOREACH(Node* pNextNode, pNode->m_aNeighbors)
//                {
//                    rNodes.push_back(pNextNode);
//                }
//                return BFS(rNodes, iValue, rVisited);
//            }
//        }
//        else
//        {
//            return pNode;
//        }
//    }
//
//    return NULL;
//}
