#pragma once

#include <iostream>
#include "EnumReturnCode.h"
#include "EnumNewInputKeySign.h"

class CCryptHandler
{
	public:
		CCryptHandler();
		~CCryptHandler();

		EnumReturnCode		encryptMessage(char c_inputMessage[], char c_inputKey);
		EnumReturnCode		decryptMessage(char c_inputMessage[], char c_inputKey);
		char				calculateNewInputKey(char c_newInputKey, char c_inputKey, EnumNewInputKeySign c_setSign);
		char				getInputKey(char c_inputKey);
};

