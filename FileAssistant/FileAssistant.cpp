//
// Created by 李磊 on 2025/2/26.
//

#include "FileAssistant.h"
#include "../Util/PlatformSupporter.h"
#include "WindowsOSFileAssistant.h"
#include "UnixOSFileAssistant.h"

FileAssistant::FileAssistant() : m_fileHandler(nullptr) {
    const PlatformOSType osType = PlatformSupporter::getPlatformOSType();
    if (osType == PlatformOSType::MACOS || osType == PlatformOSType::LINUX || osType == PlatformOSType::UNIX) {
        m_fileHandler = new UnixOSFileAssistant();
    } else if (osType == PlatformOSType::WINDOWS) {
        m_fileHandler = new WindowsOSFileAssistant();
    }
}

FileAssistant::~FileAssistant() {
    if (m_fileHandler) {
        delete m_fileHandler;
        m_fileHandler = nullptr;
    }
}

bool FileAssistant::createDirectory(const string &path) {
    if (!m_fileHandler) {
        return false;
    }
    return m_fileHandler->createDirectory(path);
}

bool FileAssistant::writeContent(const string &path, const string &content) {
    if (!m_fileHandler) {
        return false;
    }
    return m_fileHandler->writeContent(path, content);
}


bool FileAssistant::writeContent(const string &path, const std::vector<string> &content) {
    if (!m_fileHandler) {
        return false;
    }
    return m_fileHandler->writeContent(path, content);
}

bool FileAssistant::remove(const string &path) {
    if (!m_fileHandler) {
        return false;
    }
    return m_fileHandler->remove(path);
}


