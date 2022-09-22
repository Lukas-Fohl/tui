#include <iostream>
#include <vector>

using namespace std;

enum colors {black, red, green, yellow, blue, magenta, cyan, white, b_green, b_yellow, b_blue_d, b_blue_b, b_gray, none};

vector<vector<string>> scaling(int new_x_size, int new_y_size, vector<vector<string>> input)
{
	int new_heigth = new_y_size;
	int new_width   = new_x_size;
	int now_x_size = input[0].size();
	int now_y_size = input.size();
	double factor_x = double(new_width)/double(now_x_size);
	double factor_y = double(new_heigth)/double(now_y_size);

	vector<vector<string>> new_output;

	//init vector
	vector<string> n;	
	for(int x = 0; x < new_width; x++)
	{
		n.push_back(" ");
	}
	for(int y = 0; y < new_heigth; y++)
	{
		new_output.push_back(n);
	}

	//smaller:
	//-->get value upper left
	//bigger :
	//-->copy from upper left
	for(int y = 0; y < input.size(); y++)
	{
		for(int x = 0; x < input[0].size(); x++)
		{
			//cout << "y: " << int(y*factor_y) << ";;" << "x: " << int(x*factor_x) << "\n";
			new_output.at(int(y*factor_y)).at(int(x*factor_x)) = input.at(y).at(x);	
		}
	}
	return new_output;
}

vector<vector<colors>> scaling_mask(int new_x_size, int new_y_size, vector<vector<colors>> input)
{
	int new_heigth = new_y_size;
	int new_width   = new_x_size;
	int now_x_size = input[0].size();
	int now_y_size = input.size();
	double factor_x = double(new_width)/double(now_x_size);
	double factor_y = double(new_heigth)/double(now_y_size);

	vector<vector<colors>> new_output;

	//init vector
	vector<colors> n;	
	for(int x = 0; x < new_width; x++)
	{
		n.push_back(colors::none);
	}
	for(int y = 0; y < new_heigth; y++)
	{
		new_output.push_back(n);
	}

	//smaller:
	//-->get value upper left
	//bigger :
	//-->copy from upper left
	for(int y = 0; y < input.size(); y++)
	{
		for(int x = 0; x < input[0].size(); x++)
		{
			//cout << "y: " << int(y*factor_y) << ";;" << "x: " << int(x*factor_x) << "\n";
			new_output.at(int(y*factor_y)).at(int(x*factor_x)) = input.at(y).at(x);	
		}
	}
	return new_output;
}
