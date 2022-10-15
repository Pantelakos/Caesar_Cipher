#include <iostream>
#include <vector>
#include "CCryptHandler.h"
#include "CFileHandler.h"


    int main(int argc, char* argv[])
    {
        // argv[1] = (E)ncryption or (D)ecryption
        // argv[2] = Path of a text file
        // argv[3] = Key (A-Z, a-z)
        CFileHandler fileHandler;
        CCryptHandler cryptHandler;

        char cInputKey;
        char* savedOriginalMessage = new char[100000];
        std::vector<std::string> unencryptedMessage;
        CUtils* util = NULL;

        fileHandler.readFileText(unencryptedMessage, argv);

        *savedOriginalMessage = util->convertStringToCharPointer(unencryptedMessage, savedOriginalMessage);

        cInputKey = cryptHandler.getInputKey(*argv[3]);

        if (*argv[1] == 'E' || *argv[1] == 'e')
        {
            cryptHandler.encryptMessage(savedOriginalMessage, cInputKey);
        }
        else if (*argv[1] == 'D' || *argv[1] == 'd')
        {
            cryptHandler.decryptMessage(savedOriginalMessage, cInputKey);
        }
        else
        {
            std::cout << std::endl << "Error: Wrong input [argv 1] " << std::endl;
            return -1;
        }

        if ((*argv[3] >= 97 && *argv[3] <= 122 || *argv[3] >= 65 && *argv[3] <= 90))
        {
            fileHandler.saveMessageForOutput(savedOriginalMessage);
        }

        return RC_OK;
    }

