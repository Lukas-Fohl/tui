#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

enum graph_kind {linear, custom};

class graph
{
	public:
		vector<vector<string>> output;
		vector<vector<colors>> outputMask;
		graph()
		{
		}	

		void linear_graph(vector<int> AP,vector<int> BP)
		{
			int Xdiff 	= abs(AP.at(0) - BP.at(0));
			int Ydiff 	= abs(AP.at(1) - BP.at(1));

			vector<string> n;
			vector<colors> nMask;

			for(int x = 0; x < Xdiff; x++ )
			{
				n.push_back(" ");
				nMask.push_back(colors::none);
			}
			for(int y = 0; y < Ydiff; y++ )
			{
				output.push_back(n);
				outputMask.push_back(nMask);
			}

			for(int Xloop = 0;Xloop < Xdiff; Xloop++)
			{
				double per = double(Xloop) / double(Xdiff);
				int newY = per*Ydiff;
				output.at(newY).at(Xloop) = "#";
			}
		}
	//find point A and B
	//get difference between x foreach and y foreach
	//go through size of required points and get point --> map points
};
