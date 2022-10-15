#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "CUtils.h"

class CFileHandler
{
	public:
		CFileHandler();
		~CFileHandler();

		void		readFileText(std::vector<std::string>& a_unencryptedMessage, char* c_argv[2]);
		void		saveMessageForOutput(char c_inputMessage[]);

		CUtils		utils;
};

