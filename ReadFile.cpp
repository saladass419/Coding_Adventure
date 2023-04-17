#include "ReadFile.h"
#include "memtrace.h"

std::string Reader::read(char symbol) {
	std::ifstream file;
	file.open("abilities.txt");
	std::string text;
	std::string *data = new std::string[2];
	while (std::getline(file, text)){
		if (text[0] == symbol) {
			break;
		}
	}
	std::stringstream iss(text);
	int i = 0;
	while (std::getline(iss, data[i++], '\t'));
	file.close();
	return data[1];
}