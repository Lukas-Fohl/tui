#include <iostream>
#include <vector>

using namespace std;

class customText
{
	public:
		vector<vector<string>> output;
		vector<vector<colors>> outputMask;
		customText(string input,colors colorIn)
		{
			vector<string> n;
			vector<colors> nMask;
			for(int i = 0; i < input.length(); i++)
			{
				string bet(1,input[i]);
				n.push_back(bet);
				nMask.push_back(colorIn);
			}
			output.push_back(n);
			outputMask.push_back(nMask);
		}
};
