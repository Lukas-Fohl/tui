#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include <chrono>

using namespace std;

struct timeText
{
	int minBeg;
	int hourBeg;
	int minEnd;
	int hourEnd;
	string text_;
};

struct normalText
{
	string text_;
};

normalText returnNormal(int intIn)
{
	//list of all normal Text entrys 
	normalText returnNormalText;
	switch(intIn)
	{
		case 1:
		returnNormalText.text_ = "mach was";
		break;
		default:
		returnNormalText.text_ = "test";
		break;
	}
	return returnNormalText;
}

timeText returnTime(int intIn)
{
	//list of all time based Text entrys 
	timeText returnTimeText;
	switch(intIn)
	{
		case 1:
		returnTimeText.text_ = "test";
		returnTimeText.hourBeg	= 0;
		returnTimeText.minBeg 	= 0;
		returnTimeText.hourEnd 	= 1;
		returnTimeText.minEnd	= 1;
		break;
		default:
		returnTimeText.text_ = "test";
		returnTimeText.hourBeg	= 0;
		returnTimeText.minBeg 	= 0;
		returnTimeText.hourEnd 	= 1;
		returnTimeText.minEnd	= 1;
		returnTimeText.hourEnd 	= 1;
		break;
	}
	return returnTimeText;
}

class text
{
	public:
		vector<vector<string>> output;
		vector<timeText> timeVector;
		vector<normalText> normalVector;
	
	void addText(int Yoffset,string textIn)
    {
        for(int i = 0 ;i < textIn.length(); i++)
        {
            output.at(0).at(i) = textIn[i];
        }
    }

	text(bool time)
	{
		normalVector.push_back(returnNormal(1));
        int len;
		int new_len = 0;
		if(!time)
		{
			//find longest text
			for(int i = 0; i < normalVector.size(); i++)
			{
				if(normalVector.at(i).text_.length() > new_len)
				{
					new_len = normalVector.at(i).text_.length();
				}
			}
			//ceartes vector with width of the longes element and height of the entrys in the vector
			vector<string> n;
        	for(int x = 0; x < new_len; x++)
        	{
        	    n.push_back(" ");
        	}
			for(int y = 0; y < normalVector.size(); y++)
			{
				output.push_back(n);
			}
			for(int i = 0; i < normalVector.size(); i++)
			{
				addText(i,normalVector.at(i).text_);
			}
			//get time add text into output vector
		}else
		{
			for(int i = 0; i < timeVector.size(); i++)
			{
				if(timeVector.at(i).text_.length() > new_len)
				{
					new_len = timeVector.at(i).text_.length();
				}
			}
			vector<string> n;
        	for(int x = 0; x < new_len; x++)
        	{
        	    n.push_back(" ");
        	}
			for(int y = 0; y < timeVector.size(); y++)
			{
				output.push_back(n);
			}
			for(int i = 0; i < timeVector.size(); i++)
			{
				std::time_t t = std::time(nullptr);
            	std::tm* now = std::localtime(&t);
            	if(timeVector.at(i).hourBeg >= now->tm_hour 
				&& timeVector.at(i).minBeg >= now->tm_min
				&& timeVector.at(i).hourEnd <= now->tm_hour
				&& timeVector.at(i).minEnd <= now->tm_hour)
				{
					addText(i,timeVector.at(i).text_);
				}
			}
			//add all text to ouput
		}
	}
};
