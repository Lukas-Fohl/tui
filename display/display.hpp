#include <iostream>
#include <vector>
#include "util.hpp"

using namespace std;
    
const int display_height = 55;
const int display_width  = 209;

class display
{
	public:
        bool include_color_mask = true;
		//char display_grid[display_width][display_height];
        vector<vector<string>> display_grid;
        //colors display_mask[display_width][display_height];
        vector<vector<colors>> display_mask;

        colors background;

        display(colors color_in)
        {
            background = color_in;
            vector<string>  string_set;
            vector<colors>  color_set;
            for(int x= 0; x < display_width;x++)
            {
                color_set.push_back(background);
                string_set.push_back(" ");
            }
            for(int y= 0; y < display_height;y++)
            {
                display_mask.push_back(color_set);
                display_grid.push_back(string_set);
            }
            /*
            for(int y = display_height-1; y >= 0; y--)
            {
                for(int x = 0; x < display_width; x++)
                {
                    display_grid.at(y).at(x) = ' ';
                    display_mask.at(y).at(x) = colors::b_blue_b;       
                }
            }
            */
        }

        void display_out()
        {
            system("clear");
            for(int y = 0; y < display_height; y++)
            {
                for(int x = 0; x < display_width; x++)
                {
                    if(include_color_mask == false)
                    {
                        cout << display_grid.at(y).at(x);
                    }
                    else
                    {
                        cout << char_find(x,y); 
                    }
                }
                cout << "\n";
            }
        }

        void append_display(int x_in,int y_in,vector<vector<string>> display_in)
        {
            for(int y = 0; y < display_in.size(); y++)
            {
                for(int x = 0; x < display_in[y].size(); x++)
                {
                    display_grid.at(y+y_in).at(x+x_in) = display_in.at(y).at(x);
                }
            }
        }

        void append_display_maks(int x_in,int y_in,vector<vector<colors>> display_in)
        {
            for(int y = 0; y < display_in.size(); y++)
            {
                for(int x = 0; x < display_in[y].size(); x++)
                {
                    display_mask.at(y+y_in).at(x+x_in) = display_in.at(y).at(x);
                }
            }
        }

        string char_find(int x, int y)
        {
            string s_out;
            s_out = display_grid.at(y).at(x);
            //s_out.push_back(display_grid[x][y]);
            switch(display_mask.at(y).at(x))
            {
                case colors::none :
                    return s_out;
                break;
                case colors::black :
                    //später
                    return "\x1B[30m" + s_out + "\033[0m";
                    break;
                case colors::red :
                    return "\x1B[31m" + s_out + "\033[0m";
                    break;
                case colors::green :
                    return "\x1B[32m" + s_out + "\033[0m";
                    break;
                case colors::yellow : 
                    return "\x1B[33m" + s_out + "\033[0m";
                    break;
                case colors::blue :
                    return "\x1B[34m" + s_out + "\033[0m";
                    break;
                case colors::magenta :
                    return "\x1B[35m" + s_out + "\033[0m";
                    break;
                case colors::cyan :
                    return "\x1B[36m" + s_out + "\033[0m";
                    break;
                case colors::white :
                    return "\x1B[37m" + s_out + "\033[0m";
                    break;
                case colors::b_green :
                    return "\033[3;42;30m" + s_out + "\033[0m";
                    break;
                case colors::b_yellow :
                    return "\033[3;43;30m" + s_out + "\033[0m";
                    break;
                case colors::b_blue_d:
                    return "\033[3;44;30m" + s_out + "\033[0m";
                    break;
                case colors::b_blue_b :
                    return "\033[3;104;30m" + s_out + "\033[0m";
                    break;
                case colors::b_gray :
                    return "\033[3;100;30m" + s_out + "\033[0m";
                    break;
                default:
                    return " ";
                    break;
           }
        }
};
