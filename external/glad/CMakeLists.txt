cmake_minimum_required(VERSION 4.0)
project(glad)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PRIVATE
    glad/glad.c
    glad/glad.h
    glad/khrplatform.h
)

target_include_directories(${PROJECT_NAME} PUBLIC .)