#include <iostream>
#include <vector>

using namespace std;

class custom_text
{
	public:
		vector<vector<string>> output;
		vector<vector<colors>> output_mask;
		custom_text(string input,colors color_in)
		{
			vector<string> n;
			vector<colors> n_mask;
			for(int i = 0; i < input.length(); i++)
			{
				string bet(1,input[i]);
				n.push_back(bet);
				n_mask.push_back(color_in);
			}
			output.push_back(n);
			output_mask.push_back(n_mask);
		}
};
