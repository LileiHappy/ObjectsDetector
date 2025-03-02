//
// Created by 李磊 on 2025/2/27.
//

#pragma once

#include <vector>

class ParamPair {
public:
    ParamPair() = default;

    ParamPair(const int priority, const char funcFlag, const std::vector<float>& data);

    ParamPair(const ParamPair& other);

    ParamPair& operator= (const ParamPair& other);

    bool operator> (const ParamPair& other);

    ~ParamPair() = default;

    int getPriority() const;

    char getFuncFlag() const;

    const std::vector<float>& getData() const;

    void swap(ParamPair& other);

private:
    int m_priority;
    char m_funcFlag;
    std::vector<float> m_data;
};