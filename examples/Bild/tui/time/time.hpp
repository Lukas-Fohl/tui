#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>
#include <sstream>
#include "numbs_def.hpp"

//5 * array (4 * time && null if lower 10 +  ":") --> make single  --> combine
//overlay with enum color --> create same array but with enum color append enum color array

/*
I could have put all the "sprites" in one single array and then just put in the number in and
return the corresponding elment of the array but i didn't and I dont't know why anyways I'm 
not going to change it  
*/

class timeAscii
{
    public:
        std::vector<std::vector<colors>> outputMask;
        std::vector<std::vector<std::string>> output;

        colors backColor;
        colors timeColor;

        int hour = 0;
        int minute = 0;

        std::vector<std::vector<string>> swi(int i)
        {
            switch(i)
            {
                case 0 :
                {
                    return zero;
                    break;
                }
                case 1 :
                {
                    return one;
                    break;
                }
                case 2 :
                {
                    return two;
                    break;
                }
                case 3 :
                {
                    return three;
                    break;
                }
                case 4 :
                {
                    return four;
                    break;
                }
                case 5 :
                {
                    return five;
                    break;
                }
                case 6 :
                {
                    return six;
                    break;
                }
                case 7 :
                {
                    return seven;
                    break;
                }
                case 8 :
                {
                    return eighth;
                    break;
                }
                case 9 :
                {
                    return nine;
                    break;
                }
                case 10 :
                {
                    return double_point;
                    break;
                }
                default :
                {
                    return zero;
                    break;
                }
            }
        }

        void insert(int place,int insNumb)
        {
            int Xoffset = (place*5);
            if(place >1)
            {
                Xoffset += 3;
            }
            std::vector<std::vector<std::string>> ff = swi(insNumb);
            for(int y = 0; y < ff.size();y++)
            {
                for(int x = 0; x < ff[y].size();x++)
                {
                    output.at(y).at(x+Xoffset) = ff.at(y).at(x);
                }    
            }
            /*
            if(place ==3)
            {
                for(int y2= 0; y2 < 7; y2++)
                {
                    for(int x2 = 0; x2 < 23; x2++)
                    {
                        std::cout << output.at(y2).at(x2);
                    }
                    std::cout << "\n";
                }
            }
            */
        }

        void fill()
        {
            if(hour < 10)
            {
                char ch = std::to_string(hour)[0];
                std::stringstream strm;
                strm << ch;
                int hour1 = std::stoi(strm.str());
                insert(0,0);
                insert(1,hour1);
            }else
            {
                char ch = std::to_string(hour)[0];
                std::stringstream strm;
                strm << ch;
                int hour1 = std::stoi(strm.str());

                char ch2 = std::to_string(hour)[1];
                std::stringstream strm2;
                strm2 << ch2;
                int hour2 = std::stoi(strm2.str());
                insert(0,hour1);
                insert(1,hour2);
            }
            //point
            std::vector<std::vector<std::string>> ff = swi(10);
            for(int y = 0; y < ff.size();y++)
            {
                for(int x = 0; x < ff[y].size();x++)
                {
                    output.at(y).at(10+x) = ff.at(y).at(x);
                }    
            }
            if(minute < 10)
            {
                char ch = std::to_string(minute)[0];
                std::stringstream strm;
                strm << ch;
                int minute1 = std::stoi(strm.str());

                insert(2,0);
                insert(3,minute1);
            }else
            {
                char ch = std::to_string(minute)[0];
                std::stringstream strm;
                strm << ch;
                int minute1 = std::stoi(strm.str());

                char ch2 = std::to_string(minute)[1];
                std::stringstream strm2;
                strm2 << ch2;
                int minute2 = std::stoi(strm2.str());
                insert(2,minute1);
                insert(3,minute2);
            }
        }

        void makeMask()
        {
            for(int y2= 0; y2 < output.size(); y2++)
            {
                for(int x2 = 0; x2 < output[y2].size(); x2++)
                {
                    if(output.at(y2).at(x2) != " ")
                    {
                        outputMask.at(y2).at(x2) = timeColor;
                    }
                    else
                    {
                        outputMask.at(y2).at(x2) == backColor;
                    }
                }
            }
        }

        timeAscii(colors backColorIn, colors timeAsciiColorIn)
        {
            backColor = backColorIn;
            timeColor = timeAsciiColorIn;    
            std::vector<std::string>    displayMake;
            std::vector<colors>         colorMaskMake;
            for(int x= 0; x < 23;x++)
            {
                colorMaskMake.push_back(backColor);
                displayMake.push_back(".");
            }
            for(int y= 0; y < 7;y++)
            {
                outputMask.push_back(colorMaskMake);
                output.push_back(displayMake);
            }
            std::time_t t = std::time(nullptr);
            std::tm* now = std::localtime(&t);
            hour = now->tm_hour;
            minute = now->tm_min;
            fill();
            makeMask();
        }
};