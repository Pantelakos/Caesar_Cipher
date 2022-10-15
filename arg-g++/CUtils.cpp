#include "CUtils.h"

//=================================================================================================

CUtils::CUtils() {

}

//=================================================================================================

CUtils::~CUtils() {

}

//=================================================================================================

/**
    * FUNCTION: getFileName
    * USE: Returns the file name from a given file path
    * @param path: The path of the file
    * @return: The file name from the given file path
    */
std::string CUtils::getFileName(const std::string& path) {
    auto fileNameStart = path.find_last_of("/\\");
    auto fileName = fileNameStart == std::string::npos ? path : path.substr(fileNameStart + 1);
    return fileName;
}

//=================================================================================================