#include <iostream>
#include <vector>

using namespace std;

class grid
{
	public:
		int height;
		int widht;
		string place_holder;
		vector<vector<string>> output;
		vector<vector<colors>> output_mask;
		grid(int height_in, int widht_in, vector<vector<bool>> input, colors back)
		{
			place_holder = "#";
			height = height_in;
			widht  = widht_in;
			vector<colors> n_mask;
			vector<string> n;

			for(int x = 0; x < widht; x++)
			{
				n.push_back(" ");
				n_mask.push_back(colors::none);
			}
			for(int y = 0; y < height; y++)
			{
				output.push_back(n);
				output_mask.push_back(n_mask);
			}

			for(int x = 0; x < input.size(); x++)
			{
				for(int y = 0; y < input[x].size(); y++)
				{
					if(input.at(y).at(x) == true)
					{
						output.at(y).at(x) = place_holder;
						output_mask.at(y).at(x) = back;
					}
				}
			}
		}

};
