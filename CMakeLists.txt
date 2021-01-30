cmake_minimum_required(VERSION 3.1)
project(conan_workspace)

include(${CMAKE_BINARY_DIR}/conanworkspace.cmake)
conan_workspace_subdirectories()


if (BUILD_TESTING)
    add_subdirectory(test)
endif()