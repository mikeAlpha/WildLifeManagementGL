file(GLOB_RECURSE ENGINE_SOURCES
    Assets/*.cpp
    Core/*.cpp
    Platform/*.cpp
    Renderer/*.cpp
    Scene/*.cpp
)

file(GLOB_RECURSE ENGINE_HEADERS
    Assets/*.h
    Core/*.h
    Platform/*.h
    Renderer/*.h
    Scene/*.h
)

find_package(OpenGL REQUIRED)

set(IMGUI_DIR libs/imgui)
set(GLAD libs/glad)
set(GLM libs/glm)
set(GLFW libs/glfw)
set(ASSIMP libs/assimp)

add_library(Engine STATIC 
                ${ENGINE_SOURCES}
                ${IMGUI_DIR}/imgui.cpp
                ${IMGUI_DIR}/imgui_demo.cpp
                ${IMGUI_DIR}/imgui_draw.cpp
                ${IMGUI_DIR}/imgui_tables.cpp
                ${IMGUI_DIR}/imgui_widgets.cpp
                ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
                ${IMGUI_DIR}/backends/imgui_impl_opengl2.cpp
                ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
                ${GLAD}/src/glad.c
                ${ENGINE_HEADERS}
)

target_include_directories(Engine PUBLIC 
            ${CMAKE_CURRENT_SOURCE_DIR}
            ${IMGUI_DIR}
            ${IMGUI_DIR}/backends
            ${ASSIMP}
            ${ASSIMP}/include
            ${GLFW}
            ${GLFW}/include
            ${GLAD}/include
            ${GLM}/glm-master
)

add_subdirectory(${GLFW})
add_subdirectory(${ASSIMP})

target_link_libraries(Engine
    PUBLIC
        assimp
        glfw
        OpenGL::GL
)
