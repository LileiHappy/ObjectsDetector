//
// Created by 李磊 on 2025/2/26.
//

#if defined(__APPLE__) || defined(__linux__) || defined(__unix__)
#include <unistd.h>
#include <sys/stat.h>
#endif

#include "UnixOSFileAssistant.h"

bool UnixOSFileAssistant::createDirectory(const string &path) {
#if defined(__APPLE__) || defined(__linux__) || defined(__unix__)
    if (access(path.c_str(), 0) == SUCCESS) {
        return true;
    }

//    const string command = "mkdir " + path;
//    system(command.c_str());
    return mkdir(path.c_str(), S_IRWXU) == SUCCESS;
#else
    return false;
#endif
}
