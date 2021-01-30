cmake_minimum_required(VERSION 3.1)
project(clockify_cli CXX)

if(EXISTS ${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
else()
    include(conanbuildinfo.cmake)
endif()
conan_basic_setup()

set(SOURCE_FILES src/clockify_cli.cpp src/main.cpp)
set(HEADER_FILES include/clockify_cli.hpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} clockify_consumer ${CONAN_LIBS})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 14)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin)
