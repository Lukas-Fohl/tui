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

void execute()
{
	colors background = colors::none;

	display new_display(background);

	time_ascii new_time(background,colors::b_green);

	//new_display.append_display_mask(90,25,new_time.ascii_time_mask);

	window big_window(display_width/2,display_height);

	window tiny_window(display_width/2,display_height/2+1);

	window time_window(display_width/2,display_height/2);
	//main_window.append_window(0,0,new_time.ascii_time);
	time_window.append_window_mask(36,10,new_time.ascii_time_mask);

	new_display.append_display(0,display_height/2,tiny_window.window_full);
	new_display.append_display(display_width/2,0,big_window.window_full);
	new_display.append_display(0,0,time_window.window_full);
	new_display.append_display_mask(0,0,time_window.window_full_mask);

	//custom_text cs_text("hi",colors::none);

	//new_display.append_display(0,0,cs_text.output);

	new_display.display_out();

	unsigned int microsecond = 1000000;
	usleep(5 * microsecond);
}

int main()
{
	while(1)
	{
		execute();
	}
	return 0;
}