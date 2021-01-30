cmake_minimum_required(VERSION 3.1)
project(test_consumer CXX)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(SOURCE_FILES test_consumer.cpp)

add_executable(${PROJECT_NAME} "${SOURCE_FILES}")
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

enable_testing()
add_custom_target(check ${CMAKE_CTEST_COMMAND} -V)
add_test(NAME TestAll
        COMMAND ${PROJECT_NAME}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_dependencies(check ${PROJECT_NAME})