#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include "util.hpp"

using namespace std;
    
const int displayHeight = 55;
const int displayWidth  = 209;

struct point 
{
    int x,y; 
    string content;  
    colors colorContent;
};

class display
{
	public:
        vector<point> usedPoints;

        bool includeColorMask = true;
		//char displayGrid[displayWidth][displayHeight];
        vector<vector<string>> displayGrid;
        //colors displayMask[displayWidth][displayHeight];
        vector<vector<colors>> displayMask;

        colors background;

        display(colors colorIn)
        {
            printf("\033c");//clear
            printf("\033[?25l");//no cursor
            background = colorIn;
            vector<string>  stringSet;
            vector<colors>  colorSet;
            for(int x= 0; x < displayWidth;x++)
            {
                colorSet.push_back(background);
                stringSet.push_back(" ");
            }
            for(int y= 0; y < displayHeight;y++)
            {
                displayMask.push_back(colorSet);
                displayGrid.push_back(stringSet);
            }
            /*
            for(int y = displayHeight-1; y >= 0; y--)
            {
                for(int x = 0; x < displayWidth; x++)
                {
                    displayGrid.at(y).at(x) = ' ';
                    displayMask.at(y).at(x) = colors::b_blue_b;       
                }
            }
            */
        }

        void clear()
        {
            //check if point is already writen to --> else write
            string nStr = " ";
            for(int i = 0; i < usedPoints.size(); i++)
            {
                if((usedPoints.at(i).content != displayGrid.at(usedPoints.at(i).y).at(usedPoints.at(i).x)) &&
                   (usedPoints.at(i).colorContent != displayMask.at(usedPoints.at(i).y).at(usedPoints.at(i).x)))
                {
                    printf("%s",(charFind(usedPoints.at(i).x,usedPoints.at(i).y)).c_str());
                }
            }
            usedPoints.clear();
        }

        void displayOut()
        {
            //system("clear");
            //printf("\033c");//clear
            clear();
            for(int y = 0; y < displayHeight; y++)
            {
                for(int x = 0; x < displayWidth; x++)
                {
                    point nPoint;
                    if(includeColorMask == false)
                    {
                        printf("%s",displayGrid.at(y).at(x).c_str());
                    }
                    else
                    {
                        printf("%s",charFind(x,y).c_str()); 
                        nPoint.colorContent = displayMask.at(y).at(x);
                    }
                    nPoint.x = x;
                    nPoint.y = y;
                    nPoint.content = displayGrid.at(y).at(x);
                    usedPoints.push_back(nPoint);
                }
                //cout << "\n";
            }
        }

        void appendDisplay(int xIn,int yIn,vector<vector<string>> displayIn)
        {
            for(int y = 0; y < displayIn.size(); y++)
            {
                for(int x = 0; x < displayIn[y].size(); x++)
                {
                    if(displayGrid.at(y+yIn).at(x+xIn) != displayIn.at(y).at(x))
                    {
                        displayGrid.at(y+yIn).at(x+xIn) = displayIn.at(y).at(x);
                    }
                }
            }
        }

        void appendDisplayMask(int xIn,int yIn,vector<vector<colors>> displayIn)
        {
            for(int y = 0; y < displayIn.size(); y++)
            {
                for(int x = 0; x < displayIn[y].size(); x++)
                {
                    if(displayMask.at(y+yIn).at(x+xIn) != displayIn.at(y).at(x))
                    {
                        displayMask.at(y+yIn).at(x+xIn) = displayIn.at(y).at(x);
                    }
                }
            }
        }

        string charFind(int x, int y)
        {
            string sOut;
            sOut = displayGrid.at(y).at(x);
            string backGround = "";
            string forGround = "";
            //sOut.push_back(displayGrid[x][y]);
            switch(displayMask.at(y).at(x))
            {
                case colors::none :
                    return "\033[" + to_string(y) + ";" + to_string(x) + "H" + sOut;
                break;
                case colors::black :
                    backGround = "30";
                    forGround = "0";
                    //return "\x1B[30m\033[" + to_string(y) + ";" + to_string(x) + "H" + sOut + "\033[0m";
                    break;
                case colors::red :
                    backGround = "31";
                    forGround = "0";
                    //return "\x1B[31m\033[" + to_string(y) + ";" + to_string(x) + "H" + sOut + "\033[0m";
                    break;
                case colors::green :
                    backGround = "32";
                    forGround = "0";
                    //return "\x1B[32m\033[" + to_string(y) + ";" + to_string(x) + "H" + sOut + "\033[0m";
                    break;
                case colors::yellow : 
                    backGround = "32";
                    forGround = "0";
                    //return "\x1B[33m\033[" + to_string(y) + ";" + to_string(x) + "H" + sOut + "\033[0m";
                    break;
                case colors::blue :
                    backGround = "34";
                    forGround = "0";
                    //return "\x1B[34m\033[" + to_string(y) + ";" + to_string(x) + "H" + sOut + "\033[0m";
                    break;
                case colors::magenta :
                    backGround = "35";
                    forGround = "0";
                    //return "\x1B[35m\033[" + to_string(y) + ";" + to_string(x) + "H" + sOut + "\033[0m";
                    break;
                case colors::cyan :
                    backGround = "36";
                    forGround = "0";
                    //return "\x1B[36m\033[" + to_string(y) + ";" + to_string(x) + "H" + sOut + "\033[0m";
                    break;
                case colors::white :
                    backGround = "37";
                    forGround = "0";
                    //return "\x1B[37m\033[" + to_string(y) + ";" + to_string(x) + "H" + sOut + "\033[0m";
                    break;
                case colors::b_green :
                    backGround = "30";
                    forGround = "42";
                    //return "\033[3;42;30m\033[" + to_string(y) + ";" + to_string(x) + "H" + sOut + "\033[0m";
                    break;
                case colors::b_yellow :
                    backGround = "30";
                    forGround = "43";
                    //return "\033[3;43;30m\033[" + to_string(y) + ";" + to_string(x) + "H" + sOut + "\033[0m";
                    break;
                case colors::b_blue_d:
                    backGround = "30";
                    forGround = "44";
                    //return "\033[3;44;30m\033[" + to_string(y) + ";" + to_string(x) + "H" + sOut + "\033[0m";
                    break;
                case colors::b_blue_b :
                    backGround = "30";
                    forGround = "104";
                    //return "\033[3;104;30m\033[" + to_string(y) + ";" + to_string(x) + "H" + sOut + "\033[0m";
                    break;
                case colors::b_gray_b :
                    backGround = "100";
                    forGround = "0";
                    //return "\033[3;100;30m\033[" + to_string(y) + ";" + to_string(x) + "H" + sOut + "\033[0m";
                    break;
                case colors::b_gray_l :
                    backGround = "47";
                    forGround = "0";
                    break;
                case colors::b_black :
                    backGround = "40";
                    forGround = "0";
                    break;
                case colors::b_red :
                    backGround = "41";
                    forGround = "0";
                    break;
                case colors::b_magenta :
                    backGround = "45";
                    forGround = "0";
                    break;
                case colors::b_red_l :
                    backGround = "101";
                    forGround = "0";
                    break;
                case colors::b_green_l :
                    backGround = "102";
                    forGround = "0";
                    break;
                case colors::b_yellow_l :
                    backGround = "103";
                    forGround = "0";
                    break;
                case colors::b_white :
                    backGround = "107";
                    forGround = "0";
                    break;
                default:
                    return " ";
                    break;
           }
           return "\x1B[2;"+forGround+";"+backGround+"m\033[" + to_string(y) + ";" + to_string(x) + "H" + sOut + "\033[0m";
        }
};
