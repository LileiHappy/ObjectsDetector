//
// Created by 李磊 on 2025/2/26.
//

#include <cstdio>
#include <fstream>

#include "FileHandler.h"

using std::fstream;

bool FileHandler::writeContent(const string &path, const string &content) {
    fstream fileOutStream(path.c_str(), std::ios::out);
    if (!fileOutStream.is_open()) {
        return false;
    }

    fileOutStream << content;
    fileOutStream.flush();
    fileOutStream.close();
    return true;
}

bool FileHandler::writeContent(const string &path, const std::vector<string> &content) {
    fstream fileOutStream(path.c_str(), std::ios::out);
    if (!fileOutStream.is_open()) {
        return false;
    }

    for (const auto& line : content) {
        fileOutStream << line << "\n";
    }
    fileOutStream.flush();
    fileOutStream.close();
    return true;
}

bool FileHandler::remove(const string &path) {
    return std::remove(path.c_str()) == SUCCESS;
}
