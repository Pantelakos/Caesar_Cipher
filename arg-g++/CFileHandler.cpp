#include "CFileHandler.h"

//=================================================================================================

CFileHandler::CFileHandler()
{
}

//=================================================================================================

CFileHandler::~CFileHandler()
{
}

//=================================================================================================

void CFileHandler::readFileText(char* c_savedOriginalMessage, char* c_argv[2])
{
    std::ifstream readMessage;
    std::string message = c_savedOriginalMessage;

    readMessage.open(c_argv[2]);

    /*for (int i = 0; !readMessage.eof() && readMessage.is_open(); i++)
    {
        readMessage.get(c_savedOriginalMessage[i]);
        c_savedOriginalMessage[i + 1] = '\0';
    }*/

    while (getline(readMessage, message)) {
        std::cout << c_savedOriginalMessage;
    }

    readMessage.close();
}

//=================================================================================================

void CFileHandler::saveMessageForOutput(char c_inputMessage[])
{
    std::ofstream savingMessages;
    savingMessages.open("savedOutputMessages.txt", std::ios::trunc/*, ios::app*/);
    savingMessages << c_inputMessage << std::endl;
    savingMessages.close();
    std::cout << "The encryption/decryption was successful." << std::endl;
}

//=================================================================================================