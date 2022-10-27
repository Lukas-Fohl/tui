#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include "util.hpp"

using namespace std;
    
const int display_height = 55;
const int display_width  = 209;

struct point {int x,y;};

class display
{
	public:
        vector<point> usedPoints;
        bool include_color_mask = true;
		//char display_grid[display_width][display_height];
        vector<vector<string>> display_grid;
        //colors display_mask[display_width][display_height];
        vector<vector<colors>> display_mask;

        colors background;

        display(colors color_in)
        {
            printf("\033[?25l");//no cursor
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

        void clear()
        {
            //TODO get different points --> just change the difference
            string n_str = " ";
            for(int i = 0; i < usedPoints.size(); i++)
            {
                printf("%s",(("\x1B[30m\033[" + to_string(usedPoints.at(i).y) + ";" + to_string(usedPoints.at(i).x) + "H" + n_str + "\033[0m").c_str()));
            }
            usedPoints.clear();
        }

        void display_out()
        {
            //system("clear");
            //printf("\033c");//clear
            clear();
            for(int y = 0; y < display_height; y++)
            {
                for(int x = 0; x < display_width; x++)
                {
                    if(include_color_mask == false)
                    {
                        printf("%s",display_grid.at(y).at(x).c_str());
                    }
                    else
                    {
                        printf("%s",char_find(x,y).c_str()); 
                    }
                    point nPoint;
                    nPoint.x = x;
                    nPoint.y = y;
                    usedPoints.push_back(nPoint);
                }
                //cout << "\n";
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

        void append_display_mask(int x_in,int y_in,vector<vector<colors>> display_in)
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
                    return "\033[" + to_string(y) + ";" + to_string(x) + "H" + s_out;
                break;
                case colors::black :
                    //später
                    return "\x1B[30m\033[" + to_string(y) + ";" + to_string(x) + "H" + s_out + "\033[0m";
                    break;
                case colors::red :
                    return "\x1B[31m\033[" + to_string(y) + ";" + to_string(x) + "H" + s_out + "\033[0m";
                    break;
                case colors::green :
                    return "\x1B[32m\033[" + to_string(y) + ";" + to_string(x) + "H" + s_out + "\033[0m";
                    break;
                case colors::yellow : 
                    return "\x1B[33m\033[" + to_string(y) + ";" + to_string(x) + "H" + s_out + "\033[0m";
                    break;
                case colors::blue :
                    return "\x1B[34m\033[" + to_string(y) + ";" + to_string(x) + "H" + s_out + "\033[0m";
                    break;
                case colors::magenta :
                    return "\x1B[35m\033[" + to_string(y) + ";" + to_string(x) + "H" + s_out + "\033[0m";
                    break;
                case colors::cyan :
                    return "\x1B[36m\033[" + to_string(y) + ";" + to_string(x) + "H" + s_out + "\033[0m";
                    break;
                case colors::white :
                    return "\x1B[37m\033[" + to_string(y) + ";" + to_string(x) + "H" + s_out + "\033[0m";
                    break;
                case colors::b_green :
                    return "\033[3;42;30m\033[" + to_string(y) + ";" + to_string(x) + "H" + s_out + "\033[0m";
                    break;
                case colors::b_yellow :
                    return "\033[3;43;30m\033[" + to_string(y) + ";" + to_string(x) + "H" + s_out + "\033[0m";
                    break;
                case colors::b_blue_d:
                    return "\033[3;44;30m\033[" + to_string(y) + ";" + to_string(x) + "H" + s_out + "\033[0m";
                    break;
                case colors::b_blue_b :
                    return "\033[3;104;30m\033[" + to_string(y) + ";" + to_string(x) + "H" + s_out + "\033[0m";
                    break;
                case colors::b_gray :
                    return "\033[3;100;30m\033[" + to_string(y) + ";" + to_string(x) + "H" + s_out + "\033[0m";
                    break;
                default:
                    return " ";
                    break;
           }
        }
};
