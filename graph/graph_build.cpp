#include <iostream>
#include <vector>
#include "graph.hpp"

using namespace std;

int build_graph()
{
	//get shape --> get single points --> get vectors --> put in one vector
	return 0;
}

vector<vector<string>> linear_build(int x1, int y1, int x2, int y2)
{
	graph new_graph;
	vector<int> p1;
	p1.push_back(x1);
	p1.push_back(y1);
	vector<int> p2;
	p2.push_back(x2);
	p2.push_back(y2);
	new_graph.linear_graph(p1,p2);
	return new_graph.output;
}

vector<vector<colors>> linear_build_mask(int x1, int y1, int x2, int y2,colors back_color)
{
	graph new_graph;
	vector<int> p1;
	p1.push_back(x1);
	p1.push_back(y1);
	vector<int> p2;
	p2.push_back(x2);
	p2.push_back(y2);
	new_graph.linear_graph(p1,p2);
	for(int y2= 0; y2 < new_graph.output_mask.size(); y2++)
    {
        for(int x2 = 0; x2 < new_graph.output_mask[y2].size(); x2++)
        {
            if(new_graph.output.at(y2).at(x2) != " ")
            {
                new_graph.output_mask.at(y2).at(x2) = back_color;
            }
        }
    }
	return new_graph.output_mask;
}
