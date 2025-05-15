cmake_minimum_required(VERSION 3.31)
project(stb)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PRIVATE
    stb/stb_image.cpp
    stb/stb_image.h
)

target_include_directories(${PROJECT_NAME} PUBLIC .)