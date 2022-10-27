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
	int time_window_x_offset = 67;//67
	int time_window_y_offset = 15;//15

	colors background = colors::none;

	display new_display(background);

	time_ascii new_time(background,colors::b_green);

	//new_display.append_display_mask(90,25,new_time.ascii_time_mask);

	window main_window(81,25);
	//main_window.append_window(0,0,new_time.ascii_time);
	main_window.append_window_mask(27,8,new_time.ascii_time_mask);
	
	new_display.append_display(time_window_x_offset
					,time_window_y_offset
					,main_window.window_full);
	new_display.append_display_mask(time_window_x_offset
					,time_window_y_offset
					,main_window.window_full_mask);
	
	vector<vector<colors>> newing = scaling_mask(32,10,new_time.ascii_time_mask);

	//new_display.append_display_mask(0,0,newing);

	//vector<vector<string>> newing = scaling(27,8,new_time.ascii_time); 

	//quote new_quote;

	//new_display.append_display(0,0,new_quote.final_output_quote);

	//custom_text cs_text("hi",colors::none);

	//new_display.append_display(0,0,cs_text.output);

	//new_display.append_display(0,0,new_text.output);

	//new_display.append_display(0,0,linear_build(0,0,40,10));

	//new_display.append_display_mask(0,0,linear_build_mask(0,0,40,10,colors::b_gray));

	new_display.display_out();

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
