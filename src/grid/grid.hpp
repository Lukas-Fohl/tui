#include <iostream>
#include <vector>

using namespace std;

class grid
{
	public:
		int height;
		int widht;
		string placeHolder;
		vector<vector<string>> output;
		vector<vector<colors>> outputMask;
		grid(int heightIn, int widht_in, vector<vector<bool>> input, colors back)
		{
			placeHolder = "#";
			height = heightIn;
			widht  = widht_in;
			vector<colors> nMask;
			vector<string> n;

			for(int x = 0; x < widht; x++)
			{
				n.push_back(" ");
				nMask.push_back(colors::none);
			}
			for(int y = 0; y < height; y++)
			{
				output.push_back(n);
				outputMask.push_back(nMask);
			}
			
			for(int y = 0; y < input.size(); y++)
			{
				for(int x = 0; x < input.at(y).size(); x++)
				{
					if(input.at(y).at(x) == true)
					{
						output.at(y).at(x) = placeHolder;
						outputMask.at(y).at(x) = back;
					}
				}
			}
		}
};
