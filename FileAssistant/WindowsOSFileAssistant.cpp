//
// Created by 李磊 on 2025/2/26.
//
#include <fstream>

#if defined(WIN64) || defined(_WIN64) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <direct.h>
#include <io.h>
#endif

#include "WindowsOSFileAssistant.h"

using std::fstream;

bool WindowsOSFileAssistant::createDirectory(const string &path) {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    if (_access(path.c_str(), 0) == 0) {
        return true;
    }

//    string command = "mkdir -p " + path;
//    system(command.c_str());
    return _mkdir(path.c_str());
#else
    return false;
#endif
}
