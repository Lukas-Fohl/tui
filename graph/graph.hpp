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
		vector<vector<colors>> output_mask;
		graph()
		{
		}	

		void linear_graph(vector<int> AP,vector<int> BP)
		{
			int x_diff 	= abs(AP.at(0) - BP.at(0));
			int y_diff 	= abs(AP.at(1) - BP.at(1));

			vector<string> n;
			vector<colors> n_mask;

			for(int x = 0; x < x_diff; x++ )
			{
				n.push_back(" ");
				n_mask.push_back(colors::none);
			}
			for(int y = 0; y < y_diff; y++ )
			{
				output.push_back(n);
				output_mask.push_back(n_mask);
			}

			for(int x_loop = 0;x_loop < x_diff; x_loop++)
			{
				double per = double(x_loop) / double(x_diff);
				int new_y = per*y_diff;
				output.at(new_y).at(x_loop) = "#";
			}
		}
	//find point A and B
	//get difference between x foreach and y foreach
	//go through size of required points and get point --> map points
};
