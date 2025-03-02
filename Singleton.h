//
// Created by 李磊 on 2025/2/26.
//

#pragma once

template<typename T>
class Singleton {
public:
    static T& instance();

protected:
    Singleton() = default;
    virtual ~Singleton() = default;

private:
    Singleton(Singleton&& other) = delete;
    Singleton(const Singleton& other) = delete;
    Singleton& operator= (const Singleton& other) = delete;
    T* operator *() = delete;
};
#include "Singleton.inl"
