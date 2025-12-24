#pragma once
#include <iostream>

class AssetManager
{
public:
    template<typename T>
    static T* Load(const std::string& path)
    {
        std::cout << "[AssetManager] Load: " << path << "\n";
        return new T(path);
    }
};