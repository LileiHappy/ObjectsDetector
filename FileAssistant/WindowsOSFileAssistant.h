//
// Created by 李磊 on 2025/2/26.
//

#pragma once

#include "FileHandler.h"

class WindowsOSFileAssistant final : public FileHandler {
public:
    ~WindowsOSFileAssistant() override = default;

    bool createDirectory(const string &path) override;
};
