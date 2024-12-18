project(cppUtilsLib)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} STATIC
        sort.cpp
)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}
)