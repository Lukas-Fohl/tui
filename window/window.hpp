#include <iostream>
#include <vector>

using namespace std;

class window
{
    public:
        vector<vector<string>> window_full;
        vector<vector<string>> window_content;
        vector<vector<colors>> window_full_mask;
        vector<vector<colors>> window_content_mask;

        string border_site = "|";
        string border_bottom = "-";

        int height;
        int width;

        window(int width_in, int height_in)
        {
            height = height_in;
            width  = width_in;

            vector<colors> color_use;
            vector<string> string_use;

            for(int x = 0; x < width_in; x++)
            {
                color_use.push_back(colors::none);
                string_use.push_back(" ");
            }
            for(int y = 0; y < height_in; y++)
            {
                window_full.push_back(string_use);
                window_full_mask.push_back(color_use);
            }

            vector<colors> color_use_content;
            vector<string> string_use_content;

            for(int x = 0; x < width_in-2; x++)
            {
                color_use_content.push_back(colors::none);
                string_use_content.push_back(" ");
            }
            for(int y = 0; y < height_in-2; y++)
            {
                window_content.push_back(string_use_content);
                window_content_mask.push_back(color_use_content);
            }

            for(int y = 1; y < height_in-1; y++)
            {
                window_full.at(y).at(0) = border_site;
                window_full.at(y).at(width_in-1) = border_site;
            }
            for(int x = 1; x < width_in-1; x++)
            {                
                window_full.at(0).at(x) = border_bottom;
                window_full.at(height_in-1).at(x) = border_bottom;
            }
        }

        void add_to_window()
        {
            for(int y = 0; y < window_content.size(); y++)
            {
                for(int x = 0; x < window_content[y].size(); x++)
                {
                    window_full.at(y+1).at(x+1) = window_content.at(y).at(x);
                }
            }
        }

        void add_to_window_mask()
        {
            for(int y = 0; y < window_content_mask.size(); y++)
            {
                for(int x = 0; x < window_content_mask[y].size(); x++)
                {
                    window_full_mask.at(y+1).at(x+1) = window_content_mask.at(y).at(x);
                }
            }
        }

        void append_window(int x_offset,int y_offset,vector<vector<string>> display_in)
        {
            for(int y = 0; y < display_in.size(); y++)
            {
                for(int x = 0; x < display_in[y].size(); x++)
                {
                    window_content.at(y+y_offset).at(x+x_offset) = display_in.at(y).at(x);
                }
            }
            add_to_window();
        }

        void append_window_maks(int x_offset,int y_offset,vector<vector<colors>> color_in)
        {
            for(int y = 0; y < color_in.size(); y++)
            {
                for(int x = 0; x < color_in[y].size(); x++)
                {
                    window_content_mask.at(y+y_offset).at(x+x_offset) = color_in.at(y).at(x);
                }
            }
            add_to_window_mask();
        }
};