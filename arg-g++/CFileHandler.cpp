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

void CFileHandler::readFileText(std::vector<std::string>& a_unencryptedMessage, char* c_argv[2])
{
    std::fstream fstream;
    std::string fileName;
    std::string ch;

    fileName = utils.getFileName(c_argv[2]);
    fstream.open(fileName, std::ios::in | std::ios::out);

    if (!fstream.is_open()) return;

    while (std::getline(fstream, ch, '\0'))
    {
            a_unencryptedMessage.push_back(ch);
    }
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