//
// Created by 李磊 on 2025/2/27.
//
#include "ParamPair.h"

ParamPair::ParamPair(const int priority, const char funcFlag, const std::vector<float> &data) :
    m_priority(priority), m_funcFlag(funcFlag), m_data(data) {}

ParamPair::ParamPair(const ParamPair &other) : m_priority(other.m_priority), m_funcFlag(other.m_funcFlag),
    m_data(other.m_data) {}

ParamPair &ParamPair::operator=(const ParamPair &other) {
    m_priority = other.m_priority;
    m_funcFlag = other.m_funcFlag;
    m_data = other.m_data;
    return *this;
}

bool ParamPair::operator>(const ParamPair &other) {
    return m_priority > other.m_priority;
}

int ParamPair::getPriority() const {
    return m_priority;
}

char ParamPair::getFuncFlag() const {
    return m_funcFlag;
}

const std::vector<float> &ParamPair::getData() const {
    return m_data;
}

void ParamPair::swap(ParamPair &other) {
    std::swap(m_priority, other.m_priority);
    std::swap(m_funcFlag, other.m_funcFlag);
    std::swap(m_data, other.m_data);
}
