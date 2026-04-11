cmake_minimum_required(VERSION 3.10)

project(lithium)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Executável
add_executable(lithium
    src/lithium.cpp
    src/RenderWindow.cpp
    src/TextFonts.cpp
    src/Editor.cpp
    src/TextBuffer.cpp
)

# Incluir headers (include/)
target_include_directories(lithium PRIVATE include)

# SDL
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

target_link_libraries(lithium
    SDL2::SDL2
    SDL2_ttf::SDL2_ttf
)

# Copiar assets
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
