#ifndef READFILE_H
#define READFILE_H

#include <fstream>
#include <string>
#include <sstream>
#include "memtrace.h"

class Reader {
public:
	std::string read(char symbol);
};

#endif // !READFILE_H
