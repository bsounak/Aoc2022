#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main()
{
	std::cout << "Hello World\n";

	std::map<std::string, std::string> game;
	game["A X"] = "draw";
	game["A Y"] = "win";
	game["A Z"] = "loss";
	game["B X"] = "loss";
	game["B Y"] = "draw";
	game["B Z"] = "win";
	game["C X"] = "win";
	game["C Y"] = "loss";
	game["C Z"] = "draw";

	std::map<std::string, int>points;
	points["X"] = 1;
	points["Y"] = 2;
	points["Z"] = 3;
	points["loss"] = 0;
	points["draw"] = 3;
	points["win"] = 6;

	std::string line;
	std::ifstream myfile("C:\\Users\\SounakBhattacharya\\Desktop\\day2.txt");

	int v = 0;
	while (getline(myfile, line))
	{
		v += points[line.substr(line.size() - 1)];
		v += points[game[line]];
	}

	std::cout << v << std::endl;

	return 0;
}
