file(GLOB GAME_SOURCES
    src/*.cpp
)

add_executable(Game ${GAME_SOURCES})

target_link_libraries(Game PRIVATE Engine)

target_include_directories(Game PRIVATE
    ${CMAKE_SOURCE_DIR}/Engine
)
