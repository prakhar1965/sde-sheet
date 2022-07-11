// CodeStudio link: https://bit.ly/33BcVmE
// Leetcode link: https://leetcode.com/problems/clone-graph/
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
#include<bits/stdc++.h>
using namespace std;
graphNode *clone(graphNode *node, unordered_map<int, graphNode*> &visited)
{   
    if(!node) return NULL;
    graphNode* newNode = new graphNode(node->data);
    visited[node->data] = newNode;
    for(auto neighbour: node->neighbours) {
        if(visited.count(neighbour->data) == 0)
          newNode->neighbours.push_back(clone(neighbour, visited));
        else
          newNode->neighbours.push_back(visited[neighbour->data]);
    }
    return newNode;
}
graphNode *cloneGraph(graphNode *node)
{
    unordered_map<int, graphNode*> visited;
    return clone(node, visited);
}