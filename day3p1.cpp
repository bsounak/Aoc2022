#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

char find_common_character(std::string a, std::string b) {
	char c;  // common character between a and b
	for (int j = 0; j < a.length(); j++) {
		for (int i = 0; i < b.length(); i++) {
			if (a[j] == b[i]) {
				c = a[j];
				return c;
			}
		}
	}
}

int get_priority(char c) {
	// get_priority('a') -> 1
	// get_priority('A') -> 27
	if (islower(c)) {
		return int(c) - 96;
	}
	else {
		return int(c) - 38;
	}
}

int main()
{
	std::cout << "Hello World\n";

	std::string line;
	std::ifstream myfile("C:\\Users\\SounakBhattacharya\\Desktop\\day3.txt");

	std::string s1, s2;
	char common;
	int v = 0;
	while (getline(myfile, line)) {
		s1 = line.substr(0, line.length() / 2);
		s2 = line.substr(line.length() / 2);
		common = find_common_character(s1, s2);

		//std::cout << get_priority(common) << std::endl;

		v += get_priority(common);
	}

	std::cout << v << std::endl;

	return 0;
}
