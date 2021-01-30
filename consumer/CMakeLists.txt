cmake_minimum_required(VERSION 3.4)
project(clockify_consumer CXX)

if(EXISTS ${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
else()
    include(conanbuildinfo.cmake)
endif()
conan_basic_setup()

message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")

set(SOURCE_FILES src/clockify_consumer.cpp)
set(HEADER_FILES include/clockify_consumer.hpp)

#find_package(cpr CONFIG REQUIRED)
#find_package(nlohmann_json CONFIG REQUIRED)

add_library(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${HEADER_FILES}" CXX_STANDARD 14)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include)