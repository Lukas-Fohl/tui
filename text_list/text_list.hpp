#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include <chrono>

using namespace std;

struct time_text
{
	int min_beg;
	int hour_beg;
	int min_end;
	int hour_end;
	string text_;
};

struct normal_text
{
	string text_;
};

normal_text return_normal(int int_in)
{
	//list of all normal Text entrys 
	normal_text return_normal_text;
	switch(int_in)
	{
		case 1:
		return_normal_text.text_ = "mach was";
		break;
		default:
		return_normal_text.text_ = "test";
		break;
	}
	return return_normal_text;
}

time_text return_time(int int_in)
{
	//list of all time based Text entrys 
	time_text return_time_text;
	switch(int_in)
	{
		case 1:
		return_time_text.text_ = "test";
		return_time_text.hour_beg	= 0;
		return_time_text.min_beg 	= 0;
		return_time_text.hour_end 	= 1;
		return_time_text.min_end	= 1;
		break;
		default:
		return_time_text.text_ = "test";
		return_time_text.hour_beg	= 0;
		return_time_text.min_beg 	= 0;
		return_time_text.hour_end 	= 1;
		return_time_text.min_end	= 1;
		return_time_text.hour_end 	= 1;
		break;
	}
	return return_time_text;
}

class text
{
	public:
		vector<vector<string>> output;
		vector<time_text> time_vector;
		vector<normal_text> normal_vector;
	
	void add_text(int y_offset,string text_in)
    {
        for(int i = 0 ;i < text_in.length(); i++)
        {
            output.at(0).at(i) = text_in[i];
        }
    }

	text(bool time)
	{
		normal_vector.push_back(return_normal(1));
        int len;
		int new_len = 0;
		if(!time)
		{
			//find longest text
			for(int i = 0; i < normal_vector.size(); i++)
			{
				if(normal_vector.at(i).text_.length() > new_len)
				{
					new_len = normal_vector.at(i).text_.length();
				}
			}
			//ceartes vector with width of the longes element and height of the entrys in the vector
			vector<string> n;
        	for(int x = 0; x < new_len; x++)
        	{
        	    n.push_back(" ");
        	}
			for(int y = 0; y < normal_vector.size(); y++)
			{
				output.push_back(n);
			}
			for(int i = 0; i < normal_vector.size(); i++)
			{
				add_text(i,normal_vector.at(i).text_);
			}
			//get time add text into output vector
		}else
		{
			for(int i = 0; i < time_vector.size(); i++)
			{
				if(time_vector.at(i).text_.length() > new_len)
				{
					new_len = time_vector.at(i).text_.length();
				}
			}
			vector<string> n;
        	for(int x = 0; x < new_len; x++)
        	{
        	    n.push_back(" ");
        	}
			for(int y = 0; y < time_vector.size(); y++)
			{
				output.push_back(n);
			}
			for(int i = 0; i < time_vector.size(); i++)
			{
				std::time_t t = std::time(nullptr);
            	std::tm* now = std::localtime(&t);
            	if(time_vector.at(i).hour_beg >= now->tm_hour 
				&& time_vector.at(i).min_beg >= now->tm_min
				&& time_vector.at(i).hour_end <= now->tm_hour
				&& time_vector.at(i).min_end <= now->tm_hour)
				{
					add_text(i,time_vector.at(i).text_);
				}
			}
			//add all text to ouput
		}
	}
};
