//
// Created by 李磊 on 2025/2/26.
//

#pragma once

#include <string>

class InfoShower {
public:
    virtual ~InfoShower() = default;

    virtual void showInfo() const = 0;

    virtual std::string getInfo() const = 0;
};