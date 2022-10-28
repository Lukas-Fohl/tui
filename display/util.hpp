#include <iostream>
#include <vector>

using namespace std;

enum colors {black, red, green, yellow, blue, magenta, cyan, white, b_green, b_yellow, b_blue_d, b_blue_b, b_gray, none};

vector<vector<string>> scaling(int newXSize, int newYSize, vector<vector<string>> input)
{
	int newHeigth = newYSize;
	int newWidth   = newXSize;
	int nowXSize = input[0].size();
	int nowYSize = input.size();
	double factorX = double(newWidth)/double(nowXSize);
	double factorY = double(newHeigth)/double(nowYSize);

	vector<vector<string>> newOutput;

	//init vector
	vector<string> n;	
	for(int x = 0; x < newWidth; x++)
	{
		n.push_back(" ");
	}
	for(int y = 0; y < newHeigth; y++)
	{
		newOutput.push_back(n);
	}

	//smaller:
	//-->get value upper left
	//bigger :
	//-->copy from upper left
	for(int y = 0; y < input.size(); y++)
	{
		for(int x = 0; x < input[0].size(); x++)
		{
			newOutput.at(int(y*factorY)).at(int(x*factorX)) = input.at(y).at(x);	
		}
	}
	return newOutput;
}

vector<vector<colors>> scalingMask(int newXSize, int newYSize, vector<vector<colors>> input)
{
	int newHeigth = newYSize;
	int newWidth   = newXSize;
	int nowXSize = input[0].size();
	int nowYSize = input.size();
	double factorX = double(newWidth)/double(nowXSize);
	double factorY = double(newHeigth)/double(nowYSize);

	vector<vector<colors>> newOutput;

	//init vector
	vector<colors> n;	
	for(int x = 0; x < newWidth; x++)
	{
		n.push_back(colors::none);
	}
	for(int y = 0; y < newHeigth; y++)
	{
		newOutput.push_back(n);
	}

	//smaller:
	//-->get value upper left
	//bigger :
	//-->copy from upper left
	for(int y = 0; y < input.size(); y++)
	{
		for(int x = 0; x < input[0].size(); x++)
		{
			newOutput.at(int(y*factorY)).at(int(x*factorX)) = input.at(y).at(x);	
		}
	}
	return newOutput;
}
