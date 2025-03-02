//
// Created by 李磊 on 2025/2/26.
//

#pragma once

#include "FileHandler.h"

class UnixOSFileAssistant final : public FileHandler {
public:
    ~UnixOSFileAssistant() override = default;

    bool createDirectory(const string &path) override;
};
