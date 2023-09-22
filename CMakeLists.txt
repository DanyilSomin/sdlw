cmake_minimum_required(VERSION 3.16)

project(sdlw)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(3rdParty)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 23)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/include/sdlwrap.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/window.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/moveptr.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/renderer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/font.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/surface.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/texture.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/keystates.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/frametimer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sdlwrap.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/window.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sdlassert.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sdlassert.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/font.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/surface.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/texture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/keystates.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/frametimer.cpp
)

add_library(${PROJECT_NAME}
    STATIC
    ${SOURCES}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    SDL2::SDL2
    SDL2_image::SDL2_image
    SDL2_ttf::SDL2_ttf
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(sdlw::sdlw ALIAS ${PROJECT_NAME})

