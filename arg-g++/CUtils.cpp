#include "CUtils.h"

//=================================================================================================

CUtils::CUtils() {

}

//=================================================================================================

CUtils::~CUtils() {

}

//=================================================================================================

char CUtils::convertStringToCharPointer(std::vector<std::string>& c_unencryptedMessage, char a_savedOriginalMessage[])
{
    for (int i = 0; i < c_unencryptedMessage.size(); i++)
    {
        for (int j = 0; j < c_unencryptedMessage[i].size(); j++)
        {
            a_savedOriginalMessage[j] = c_unencryptedMessage[i][j];
        }
    }

    return *a_savedOriginalMessage;
}

//=================================================================================================

std::string CUtils::getFileName(const std::string& path) {
    auto fileNameStart = path.find_last_of("/\\");
    auto fileName = fileNameStart == std::string::npos ? path : path.substr(fileNameStart + 1);
    return fileName;
}

//=================================================================================================