cmake_minimum_required(VERSION 3.10)
project(example)

set(SRC
    examples.cpp
)

set(CMAKE_CXX_STANDARD 14)
add_executable(${PROJECT_NAME} ${SRC})
find_library(CRYREPO_LIB NAMES CryRepo PATHS /usr/local/lib)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CRYREPO_LIB})
target_include_directories(${PROJECT_NAME} PRIVATE "/usr/local/include")
