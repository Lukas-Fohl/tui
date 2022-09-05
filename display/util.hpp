#include <iostream>
#include <vector>

using namespace std;

enum colors {black, red, green, yellow, blue, magenta, cyan, white, b_green, b_yellow, b_blue_d, b_blue_b, b_gray, none};

vector<vector<string>> scaling(float factor, vector<vector<string>> input)
{
	vector<vector<string>> output;
	int new_heigth = input.size();
	int new_widh   = input.at(0).size();
		new_heigth*= factor;
		new_widh  *= factor;
	//blure if smaller one
	//add top left
	if(factor >= 1)
	{
	
	}else if(factor < 1 && factor > 0)
	{
	
	}else
	{
		return input;
	}
}
