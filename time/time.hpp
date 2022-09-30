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

class time_ascii
{
    public:
        std::vector<std::vector<colors>> ascii_time_mask;
        std::vector<std::vector<std::string>> ascii_time;

        colors back_color;
        colors time_color;

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

        void insert(int place,int ins_numb)
        {
            int x_offset = (place*5);
            if(place >1)
            {
                x_offset += 3;
            }
            std::vector<std::vector<std::string>> ff = swi(ins_numb);
            for(int y = 0; y < ff.size();y++)
            {
                for(int x = 0; x < ff[y].size();x++)
                {
                    ascii_time.at(y).at(x+x_offset) = ff.at(y).at(x);
                }    
            }
            /*
            if(place ==3)
            {
                for(int y2= 0; y2 < 7; y2++)
                {
                    for(int x2 = 0; x2 < 23; x2++)
                    {
                        std::cout << ascii_time.at(y2).at(x2);
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
                    ascii_time.at(y).at(10+x) = ff.at(y).at(x);
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

        void make_mask()
        {
            for(int y2= 0; y2 < ascii_time.size(); y2++)
            {
                for(int x2 = 0; x2 < ascii_time[y2].size(); x2++)
                {
                    if(ascii_time.at(y2).at(x2) != " ")
                    {
                        ascii_time_mask.at(y2).at(x2) = time_color;
                    }
                    else
                    {
                        ascii_time_mask.at(y2).at(x2) == back_color;
                    }
                }
            }
        }

        time_ascii(colors back_color_in, colors time_ascii_color_in)
        {
            back_color = back_color_in;
            time_color = time_ascii_color_in;    
            std::vector<std::string>    display_make;
            std::vector<colors>         color_mask_make;
            for(int x= 0; x < 23;x++)
            {
                color_mask_make.push_back(back_color);
                display_make.push_back(".");
            }
            for(int y= 0; y < 7;y++)
            {
                ascii_time_mask.push_back(color_mask_make);
                ascii_time.push_back(display_make);
            }
            std::time_t t = std::time(nullptr);
            std::tm* now = std::localtime(&t);
            hour = now->tm_hour;
            minute = now->tm_min;
            fill();
            make_mask();
        }
};