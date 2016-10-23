#include <iostream>
#include <string>
#include "pocketcalculator.h"


int main(int const argc, char* const argv[]) {

	// First argument is scale, second is maxWidth
	unsigned scale{1};
	unsigned maxWidth{0};
	switch(argc){
		case 3:
			maxWidth = std::stoi(argv[2]);
		case 2:
			scale = std::stoi(argv[1]);
			break;
	}

	pocketcalculator(std::cin, std::cout, scale, maxWidth);
	return 0;
}