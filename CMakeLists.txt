cmake_minimum_required(VERSION 3.15)
project(Perceptron)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCE_FILES
    src/Perceptron/main.cpp
    src/Perceptron/Function.cpp
    src/Perceptron/Perceptron.cpp
    src/Perceptron/PerceptronTraits.cpp
)

set(HEADER_FILES
    src/Perceptron/Function.h
    src/Perceptron/Perceptron.h
    src/Perceptron/PerceptronTraits.h
    src/Perceptron/Helper.h
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE src)
