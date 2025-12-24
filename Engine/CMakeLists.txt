file(GLOB_RECURSE ENGINE_SOURCES
    Core/*.cpp
    Platform/*.cpp
    Renderer/*.cpp
    Scene/*.cpp
)

add_library(Engine STATIC ${ENGINE_SOURCES})

target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
