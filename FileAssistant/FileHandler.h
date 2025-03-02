//
// Created by 李磊 on 2025/2/26.
//

#pragma once

#include "IFileAssistant.h"

class FileHandler : public IFileAssistant {
public:
    virtual ~FileHandler() override = default;

    bool writeContent(const string &path, const string &content) override;

    bool writeContent(const string &path, const std::vector<string> &content) override;

    bool remove(const string &path) override;

protected:
    static constexpr short SUCCESS = 0;
};