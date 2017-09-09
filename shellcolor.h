#ifndef _SHELLCOLOR_H
#define _SHELLCOLOR_H
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>


namespace salad {

	typedef enum {
		SHELL_GREY = 90,
		SHELL_RED = 91,
		SHELL_GREEN = 92,
		SHELL_YELLOW = 93,
		SHELL_BLUE = 94,
		SHELL_MAGENTA = 95,
		SHELL_CYAN = 96,
		SHELL_WHITE = 97,
		SHELL_BLACK = 30,
		SHELL_RED_DARK = 31,
		SHELL_GREEN_DARK = 32,
		SHELL_YELLOW_DARK = 33,
		SHELL_BLUE_DARK = 34,
		SHELL_MAGENTA_DARK = 35,
		SHELL_CYAN_DARK = 36,
		SHELL_LIGHT_GREY = 37,
		SHELL_RESET = 0,
		SHELL_UNDERLINE = 4,
		SHELL_SELECT = 7,
		SHELL_BG_GREY = 100,
		SHELL_BG_RED = 101,
		SHELL_BG_GREEN = 102,
		SHELL_BG_YELLOW = 103,
		SHELL_BG_BLUE = 104,
		SHELL_BG_MAGENTA = 105,
		SHELL_BG_CYAN = 106,
		SHELL_BG_WHITE = 107,
	} SHELL_COLOR;

	inline void set_shell_color(SHELL_COLOR color) {
		std::stringstream stream;
		stream << (int) color;
		std::cout << std::string("\e[" + stream.str() + "m").c_str();
	}

}

#endif
