#include <unistd.h>
#include <iostream>
#include <vector>
#include "tui/include.hpp"

enum size {big,small};

size ThisSize = size::big;

display ThisDisplay(colors::none);
//collider
int Height = 26;//50      //26
int Width  = 102;//203    //102
//screen
int Height_w = 30;//30    //53
int Width_w  = 106;//106  //207
//blop
const int BlopX  = 9;
const int BlopY  = 5;
vector<float> velocity = {1,1};
//at 0,0
vector<float> position = {20,20};

void corner(){
    //check for next step --> change velocity
    if(position.at(0)+velocity.at(0)+BlopX > Width || position.at(0)+velocity.at(0) < -1)
    {
        velocity.at(0) = velocity.at(0)*-1;
    }
    if(position.at(1)+velocity.at(1)+BlopY > Height || position.at(1)+velocity.at(1) < -1)
    {
        velocity.at(1) = velocity.at(1)*-1;
    }
}

int main(int argc, char *argv[]){
    if(argc == 2)
    {
        ThisSize = size::small;
    }
    if(ThisSize == size::big)
    {
        Height = 50;//50      //26
        Width  = 203;//203    //102
        Height_w = 53;//30    //53
        Width_w  = 207;//106  //207
    }
    //place for point
    window nn(Width_w,Height_w);

    customText n("  ",colors::b_magenta);
    customText n_blank("  ",colors::none);
    unsigned int microsecond = 1000000;

    while(true)
    {
        corner();

        position.at(0) += velocity.at(0);
        position.at(1) += velocity.at(1);

        //clear last
        for(int x = 0; x < BlopX; x++)
        {
            for(int y = 0; y < BlopY; y++)
            {
                nn.appendWindow(position.at(0)+x+1-velocity.at(0),position.at(1)+y+1-velocity.at(1),n_blank.output);
                nn.appendWindowMask(position.at(0)+x+1-velocity.at(0),position.at(1)+y+1-velocity.at(1),n_blank.outputMask);
            }    
        }

        for(int x = 0; x < BlopX; x++)
        {
            for(int y = 0; y < BlopY; y++)
            {
                nn.appendWindow(position.at(0)+x+1,position.at(1)+y+1,n.output);
                nn.appendWindowMask(position.at(0)+x+1,position.at(1)+y+1,n.outputMask);
            }    
        }
       
        //display all of it
        if(ThisSize == size::big)
        {
            ThisDisplay.appendDisplay(2,2,nn.windowFull);
            //ThisDisplay.appendDisplay(2,2,nn.windowContent);
            ThisDisplay.appendDisplayMask(2,2,nn.windowFullMask);
        }else
        {
            ThisDisplay.appendDisplay(position.at(0)+8,position.at(1)+4,nn.windowFull);
            ThisDisplay.appendDisplayMask(position.at(0)+8,position.at(1)+4,nn.windowFullMask);
        }
        ThisDisplay.displayOut();   
        usleep((1/24)*microsecond);
    }
    return 0;
}
