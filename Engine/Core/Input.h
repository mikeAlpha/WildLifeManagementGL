#pragma once

#include <unordered_map>

class Input
{
public:
    static void SetKey(int key, bool pressed)
    {
        s_Keys[key] = pressed;
    }

    static bool IsKeyPressed(int key)
    {
        auto it = s_Keys.find(key);
        return it != s_Keys.end() && it->second;
    }

    static void AddMouseDelta(float dx, float dy)
    {
        s_MouseDX += dx;
        s_MouseDY += dy;
    }

    static float GetMouseDX() { return s_MouseDX; }
    static float GetMouseDY() { return s_MouseDY; }

    static void EndFrame()
    {
        s_MouseDX = 0.0f;
        s_MouseDY = 0.0f;
    }

private:
    inline static std::unordered_map<int, bool> s_Keys{};
    inline static float s_MouseDX = 0.0f;
    inline static float s_MouseDY = 0.0f;
};
