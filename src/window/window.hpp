#include <iostream>
#include <vector>

using namespace std;

class window
{
    public:
        vector<vector<string>> windowFull;
        vector<vector<string>> windowContent;
        vector<vector<colors>> windowFullMask;
        vector<vector<colors>> windowContentMask;

        string borderSite = "┃";// |
        string borderBottom = "━";// /

        int height;
        int width;

        window(int widthIn, int heightIn)
        {
            height = heightIn;
            width  = widthIn;

            vector<colors> colorUse;
            vector<string> stringUse;

            for(int x = 0; x < widthIn; x++)
            {
                colorUse.push_back(colors::none);
                stringUse.push_back(" ");
            }
            for(int y = 0; y < heightIn; y++)
            {
                windowFull.push_back(stringUse);
                windowFullMask.push_back(colorUse);
            }

            vector<colors> colorUseContent;
            vector<string> stringUseContent;

            for(int x = 0; x < widthIn-2; x++)
            {
                colorUseContent.push_back(colors::none);
                stringUseContent.push_back(" ");
            }
            for(int y = 0; y < heightIn-2; y++)
            {
                windowContent.push_back(stringUseContent);
                windowContentMask.push_back(colorUseContent);
            }

            for(int y = 1; y < heightIn-1; y++)
            {
                windowFull.at(y).at(0) = borderSite;
                windowFull.at(y).at(widthIn-1) = borderSite;
            }
            for(int x = 1; x < widthIn-1; x++)
            {                
                windowFull.at(0).at(x) = borderBottom;
                windowFull.at(heightIn-1).at(x) = borderBottom;
            }

            windowFull.at(heightIn-1).at(widthIn-1)  = "┛";
            windowFull.at(heightIn-1).at(0)           = "┗";
            windowFull.at(0).at(widthIn-1)            = "┓";
            windowFull.at(0).at(0)                     = "┏";
        }

        void addToWindow()
        {
            for(int y = 0; y < windowContent.size(); y++)
            {
                for(int x = 0; x < windowContent[y].size(); x++)
                {
                    windowFull.at(y+1).at(x+1) = windowContent.at(y).at(x);
                }
            }
        }

        void addToWindowMask()
        {
            for(int y = 0; y < windowContentMask.size(); y++)
            {
                for(int x = 0; x < windowContentMask[y].size(); x++)
                {
                    windowFullMask.at(y+1).at(x+1) = windowContentMask.at(y).at(x);
                }
            }
        }

        void appendWindow(int Xoffset,int Yoffset,vector<vector<string>> displayIn)
        {
            for(int y = 0; y < displayIn.size(); y++)
            {
                for(int x = 0; x < displayIn[y].size(); x++)
                {
                    windowContent.at(y+Yoffset).at(x+Xoffset) = displayIn.at(y).at(x);
                }
            }
            addToWindow();
        }

        void appendWindowMask(int Xoffset,int Yoffset,vector<vector<colors>> colorIn)
        {
            for(int y = 0; y < colorIn.size(); y++)
            {
                for(int x = 0; x < colorIn[y].size(); x++)
                {
                    windowContentMask.at(y+Yoffset).at(x+Xoffset) = colorIn.at(y).at(x);
                }
            }
            addToWindowMask();
        }
};
