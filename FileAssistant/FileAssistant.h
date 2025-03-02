//
// Created by 李磊 on 2025/2/26.
//

#pragma once

#include "../Singleton.h"
#include "IFileAssistant.h"

class FileAssistant final : public IFileAssistant, public Singleton<FileAssistant> {
public:
    ~FileAssistant() override;

    bool createDirectory(const string &path) override;

    bool writeContent(const string& path, const string& content) override;

    bool writeContent(const string &path, const std::vector<string> &content) override;

    bool remove(const string& path) override;

private:
    FileAssistant();

private:
    friend Singleton;
    IFileAssistant* m_fileHandler;
};
