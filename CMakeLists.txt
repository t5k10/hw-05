cmake_minimum_required(VERSION 3.16.3)

project(statistics)

set(SOURCES
    src/min.cpp
    src/max.cpp
    src/mean.cpp
    src/std_deviation.cpp
    src/pct90.cpp
    src/pct95.cpp
    src/main.cpp
)

set(HEADERS
    headers/i_statistics.hpp
)

add_executable(statistics ${HEADERS} ${SOURCES})

target_include_directories(statistics 
    PRIVATE 
    ${PROJECT_SOURCE_DIR}/headers
)

set_target_properties(statistics PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
