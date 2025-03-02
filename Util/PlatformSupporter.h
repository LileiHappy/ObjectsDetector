//
// Created by 李磊 on 2025/2/27.
//

#pragma once

enum class PlatformOSType {
    UNKNOWN = 0,
    MACOS,
    LINUX,
    WINDOWS,
    UNIX,
    NOT_SUPPORT
};

class PlatformSupporter {
public:
    ~PlatformSupporter() = default;

    static PlatformOSType getPlatformOSType();

    static char getFilePathSeparator();

private:
    PlatformSupporter();
    PlatformSupporter(const PlatformSupporter &other) = delete;
    PlatformSupporter& operator= (const PlatformSupporter &other) = delete;
};
