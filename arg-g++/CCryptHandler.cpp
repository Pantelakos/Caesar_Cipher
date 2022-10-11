#include "CCryptHandler.h"

//=================================================================================================

CCryptHandler::CCryptHandler()
{
}

//=================================================================================================

CCryptHandler::~CCryptHandler()
{
}

//=================================================================================================

char CCryptHandler::getInputKey(char c_inputKey)
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

char CCryptHandler::calculateNewInputKey(char c_newInputKey, char c_inputKey, EnumNewInputKeySign c_setSign)
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

EnumReturnCode CCryptHandler::encryptMessage(char c_inputMessage[], char c_inputKey)
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

EnumReturnCode CCryptHandler::decryptMessage(char c_inputMessage[], char c_inputKey)
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
