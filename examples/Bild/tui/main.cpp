#include <iostream>
#include <unistd.h>
#include "display/display.hpp"
#include "time/time.hpp"
#include "window/window.hpp"
#include "quotes/quotes.hpp"
#include "text_list/text_list.hpp"
#include "graph/graph_build.cpp"
#include "grid/grid.hpp"
#include "custom_text/custom_text.hpp"

const int time_window_Xoffset = 67;//67
const int time_window_Yoffset = 15;//15

const colors background = colors::none;
//create a new display with a default background color
display new_display(background);
//create a window (not necessary)
window main_window(81,25);

void execute()
{
	//create a timeAscii - object (with a background and a color)
	timeAscii new_time(background,colors::b_green);
	//put timeAscii - object into window
	main_window.appendWindowMask(27,8,new_time.outputMask);
	//put window into display (just char)
	new_display.appendDisplay(time_window_Xoffset
					,time_window_Yoffset
					,main_window.windowFull);
	//put window into display (just color)
	new_display.appendDisplayMask(time_window_Xoffset
					,time_window_Yoffset
					,main_window.windowFullMask);
	//display the display
	new_display.displayOut();
	//wait
	unsigned int microsecond = 1000000;
	usleep((1/60) * microsecond);
}

int main()
{
	while(1)
	{
		execute();
	}
	return 0;
}
