#pragma once

#include <fstream>
#include <iostream>
#include <string>

class CFileHandler
{
	public:
		CFileHandler();
		~CFileHandler();

		void		readFileText(char* c_savedOriginalMessage, char* c_argv[2]);
		void		saveMessageForOutput(char c_inputMessage[]);
};

