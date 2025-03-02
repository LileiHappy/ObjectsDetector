//
// Created by 李磊 on 2025/2/26.
//

#pragma once

#include <string>
#include <vector>

using std::string;

class IFileAssistant {
public:
    virtual ~IFileAssistant() = default;

    virtual bool createDirectory(const string& path) = 0;

    virtual bool writeContent(const string& path, const string& content) = 0;

    virtual bool writeContent(const string& path, const std::vector<string>& content) = 0;

    virtual bool remove(const string& path) = 0;
};