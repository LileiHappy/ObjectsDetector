//
// Created by 李磊 on 2025/2/27.
//

#include "PlatformSupporter.h"

PlatformSupporter::PlatformSupporter() {
    getPlatformOSType();
}

PlatformOSType PlatformSupporter::getPlatformOSType() {
    static PlatformOSType osType = PlatformOSType::UNKNOWN;

    if (osType == PlatformOSType::UNKNOWN) {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
        osType = PlatformOSType::WINDOWS;
#elif __APPLE__
        osType = PlatformOSType::MACOS;
#elif __linux__
        osType = PlatformOSType:::LINUX;
#elif __unix__
        osType = PlatformOSType::UNIX;
#else
        osType = PlatformOSType::NOT_SUPPORT;
#endif
    }

    return osType;
}

char PlatformSupporter::getFilePathSeparator() {
    return getPlatformOSType() == PlatformOSType::WINDOWS ? '\\' : '/';
}
