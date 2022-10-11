#include <iostream>
#include <fstream>
#include <string>
#include "EnumReturnCode.h"
#include "EnumNewInputKeySign.h"

    //=================================================================================================

    char calculateNewInputKey(char c_newInputKey, char c_inputKey, EnumNewInputKeySign c_setSign)
    {
        if (c_newInputKey != c_inputKey)
        {
            if (c_setSign == NIKS_ADD)
            {
                return c_inputKey = c_inputKey + c_newInputKey;
            }
            else if (c_setSign == NIKS_SUBTRACT)
            {
                return c_inputKey = c_inputKey - c_newInputKey;
            }
        }

        return c_inputKey;
    }

    //=================================================================================================

    void saveMessageForOutput(char c_inputMessage[])
    {
        std::ofstream savingMessages;
        savingMessages.open("savedOutputMessages.txt", std::ios::trunc/*, ios::app*/);
        savingMessages << c_inputMessage << std::endl;
        savingMessages.close();
        std::cout << "The encryption/decryption was successful." << std::endl;
    }

    //=================================================================================================

    char getInputKey(char c_inputKey)
    {
        char cInputKey = c_inputKey;

        if (cInputKey >= 97 && cInputKey <= 122)
        {
            cInputKey = (int)cInputKey - 96;
        }
        else if (cInputKey >= 65 && cInputKey <= 90)
        {
            cInputKey = (int)cInputKey - 64;
        }
        else
        {
            std::cout << std::endl << "Error: Wrong input [argv 3]  " << std::endl;
        }

        return cInputKey;
    }

    //=================================================================================================

    void readFileText(char* c_savedOriginalMessage, char* c_argv[2])
    {
        std::ifstream readMessage;
        std::string message = c_savedOriginalMessage;

        std::cout << c_argv[2];
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

    EnumReturnCode encryptMessage(char c_inputMessage[], char c_inputKey)
    {
        char newInputKey = 0;

        for (int i = 0; i < 100000; i++)
        {
            if ((c_inputMessage[i] >= 65 && c_inputMessage[i] <= 90) || (c_inputMessage[i] >= 97 && c_inputMessage[i] <= 122))
            {
                if ((c_inputMessage[i] + c_inputKey > 122) && (c_inputMessage[i] >= 97 && c_inputMessage[i] <= 122))
                {
                    newInputKey = 122 - c_inputMessage[i];
                    newInputKey = calculateNewInputKey(newInputKey, c_inputKey, NIKS_SUBTRACT);
                    c_inputMessage[i] = 64 + newInputKey;
                }
                else if ((c_inputMessage[i] + c_inputKey > 90) && (c_inputMessage[i] >= 65 && c_inputMessage[i] <= 90))
                {
                    newInputKey = 90 - c_inputMessage[i];
                    newInputKey = calculateNewInputKey(newInputKey, c_inputKey, NIKS_SUBTRACT);
                    c_inputMessage[i] = 96 + newInputKey;
                }
                else
                {
                    c_inputMessage[i] = c_inputMessage[i] + c_inputKey;
                }
            }
        }

        return RC_OK;
    }

    //=================================================================================================

    EnumReturnCode decryptMessage(char c_inputMessage[], char c_inputKey)
    {
        char newInputKey = 0;

        for (int i = 0; i < 100000; i++)
        {
            if ((c_inputMessage[i] >= 65 && c_inputMessage[i] <= 90) || (c_inputMessage[i] >= 97 && c_inputMessage[i] <= 122))
            {
                if ((c_inputMessage[i] - c_inputKey < 97) && (c_inputMessage[i] >= 97 && c_inputMessage[i] <= 122))
                {
                    newInputKey = 97 - c_inputMessage[i];
                    newInputKey = calculateNewInputKey(newInputKey, c_inputKey, NIKS_ADD);
                    c_inputMessage[i] = 91 - newInputKey;
                }
                else if ((c_inputMessage[i] - c_inputKey < 65) && (c_inputMessage[i] >= 65 && c_inputMessage[i] <= 90))
                {
                    newInputKey = 65 - c_inputMessage[i];
                    newInputKey = calculateNewInputKey(newInputKey, c_inputKey, NIKS_ADD);
                    c_inputMessage[i] = 123 - newInputKey;
                }
                else
                {
                    c_inputMessage[i] = c_inputMessage[i] - c_inputKey;
                }
            }
        }

        return RC_OK;
    }

    //=================================================================================================

    int main(int argc, char* argv[])
    {
       // argv[1] = (E)ncryption or (D)ecryption
       // argv[2] = Path of a text file
       // argv[3] = Key (A-Z, a-z)

       char cInputKey;
       char* savedOriginalMessage = new char[100000];

       readFileText(savedOriginalMessage, argv);

       cInputKey = getInputKey(*argv[3]);

       if (*argv[1] == 'E' || *argv[1] == 'e')
       {
           encryptMessage(savedOriginalMessage, cInputKey);
       }
       else if (*argv[1] == 'D' || *argv[1] == 'd')
       {
           decryptMessage(savedOriginalMessage, cInputKey);
       }
       else
       {
           std::cout << std::endl << "Error: Wrong input [argv 1] " << std::endl;
           return -1;
       }

       if ((*argv[3] >= 97 && *argv[3] <= 122 || *argv[3] >= 65 && *argv[3] <= 90))
       {
          saveMessageForOutput(savedOriginalMessage);
       }

        return RC_OK;
    }

