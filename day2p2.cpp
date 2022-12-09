#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main()
{
	std::cout << "Hello World\n";

	std::map<std::string, std::string> game;
	game["Adraw"] = "X";  // X needs to played to draw against A
	game["Awin"] = "Y";  // Y needs to be played to win against A
	game["Aloss"] = "Z";  // Z needs to be playes to lose against A
	game["Bloss"] = "X";
	game["Bdraw"] = "Y";
	game["Bwin"] = "Z";
	game["Cwin"] = "X";
	game["Closs"] = "Y";
	game["Cdraw"] = "Z";

	std::map<std::string, int> points;
	points["X"] = 1;
	points["Y"] = 2;
	points["Z"] = 3;
	points["loss"] = 0;
	points["draw"] = 3;
	points["win"] = 6;

	std::map<std::string, std::string> m;
	m["X"] = "loss";
	m["Y"] = "draw";
	m["Z"] = "win";

	std::string line;
	std::ifstream myfile("C:\\Users\\SounakBhattacharya\\Desktop\\day2.txt");

	int v = 0;
	std::string p1;
	std::string p2;
	std::string s;

	while (getline(myfile, line)) {
		p1 = line.substr(0, 1);
		p2 = line.substr(line.size() - 1);

		//std::cout << m[p2] << std::endl;
		//std::cout << game[p1 + m[p2]] << std::endl;

		v += points[game[p1 + m[p2]]];
		v += points[m[p2]];
	}

	std::cout << v << std::endl;

	return 0;
}
