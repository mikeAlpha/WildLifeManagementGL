cmake_minimum_required(VERSION 3.10)
project(WildLifeGameGL)

set(CMAKE_CXX_STANDARD 17)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src)

# GLFW
add_subdirectory(libs/glfw)
include_directories(libs/glfw/include)

set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/libs/imgui)

add_library(imgui
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl2.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)

# GLAD
add_library(glad libs/glad/src/glad.c)
include_directories(
libs/glad/include
libs/glm/glm-master
)

# Source files
file(GLOB SRC_FILES src/*.cpp)

add_executable(WildLifeGameGL ${SRC_FILES})
target_link_libraries(WildLifeGameGL imgui glad glfw ${OPENGL_gl_LIBRARY})