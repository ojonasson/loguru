cmake_minimum_required(VERSION 2.8)

project(loguru)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
      "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif(NOT CMAKE_BUILD_TYPE)

MESSAGE(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

add_compile_options(-std=c++11 -Wall -Wextra -Wextra)

file(GLOB source
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)
file(GLOB headers
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

add_library(loguru STATIC ${source})

target_link_libraries(loguru)

install(TARGETS loguru     DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(FILES   ${headers} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/loguru)