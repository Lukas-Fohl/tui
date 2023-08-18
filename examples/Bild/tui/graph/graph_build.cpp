#include <iostream>
#include <vector>
#include "graph.hpp"

using namespace std;

int build_graph()
{
	//get shape --> get single points --> get vectors --> put in one vector
	return 0;
}

vector<vector<string>> linearBuild(int x1, int y1, int x2, int y2)
{
	graph newGraph;
	vector<int> p1;
	p1.push_back(x1);
	p1.push_back(y1);
	vector<int> p2;
	p2.push_back(x2);
	p2.push_back(y2);
	newGraph.linear_graph(p1,p2);
	return newGraph.output;
}

vector<vector<colors>> linearBuildMask(int x1, int y1, int x2, int y2,colors backColor)
{
	graph newGraph;
	vector<int> p1;
	p1.push_back(x1);
	p1.push_back(y1);
	vector<int> p2;
	p2.push_back(x2);
	p2.push_back(y2);
	newGraph.linear_graph(p1,p2);
	for(int y2= 0; y2 < newGraph.outputMask.size(); y2++)
    {
        for(int x2 = 0; x2 < newGraph.outputMask[y2].size(); x2++)
        {
            if(newGraph.output.at(y2).at(x2) != " ")
            {
                newGraph.outputMask.at(y2).at(x2) = backColor;
            }
        }
    }
	return newGraph.outputMask;
}
