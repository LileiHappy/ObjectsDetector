//
// Created by 李磊 on 2025/2/26.
//

template<typename T>
T& Singleton<T>::instance() {
    static T instance;
    return instance;
}