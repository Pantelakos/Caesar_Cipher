#pragma once

#include <vector>
#include <string>

class CUtils {
public:
    CUtils();
    ~CUtils();

    char                convertStringToCharPointer(std::vector<std::string>& c_unencryptedMessage, char a_savedOriginalMessage[]);
    std::string         getFileName(const std::string& path);
};