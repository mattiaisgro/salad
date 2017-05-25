#include "shellcolor.h"

int main(int argc, char const *argv[]) {

	for (int i = 0; i < 128; ++i) {

		set_shell_color(SHELL_RESET);

		std::cout << "\t" << i << "\t";

		set_shell_color((SHELL_COLOR) i);

		std::cout << "Andra moi ennepe, Mousa" << std::endl;

	}


	return 0;
}
