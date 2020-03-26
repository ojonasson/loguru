cmake_minimum_required(VERSION 3.1.0)

# Example build/install commands:
# cmake .. -DCMAKE_BUILD_TYPE=Release
# cmake .. -DCMAKE_BUILD_TYPE=Debug
# cmake .. -DCMAKE_INSTALL_PREFIX=.. -DCMAKE_BUILD_TYPE=Debug && make install
# cmake .. -DCMAKE_INSTALL_PREFIX=.. -DCMAKE_BUILD_TYPE=Release && make install

project(loguru CXX)

message("Compiler: ${CMAKE_CXX_COMPILER}")
message("Compiler_ID: ${CMAKE_CXX_COMPILER_ID}")

if(UNIX AND NOT APPLE)
	message(STATUS "Linux operating system detected")
	set(LINUX TRUE)
elseif(MAC)
	message(STATUS "Mac os operating system detected")
endif()

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	set(CMAKE_VERBOSE_MAKEFILE on)
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -g")
set(CMAKE_CXX_COMPILER $ENV{CXX})
add_compile_options("-Wfatal-errors")
set(CMAKE_OPT_FLAGS)
include_directories(BEFORE SYSTEM include)

if(APPLE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xpreprocessor")
elseif(UNIX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
else()
	message( FATAL_ERROR "Only Linux and Mac OS are supported")
endif()

set(HEADER_FILES
		include/loguru.hpp
		include/loguru_setup.h)

set(CC_FILES
		src/loguru.cpp)

set(EXAMPLE_CC_FILES
		sst_example/sst_example.cpp)

add_library(loguru STATIC ${CC_FILES} ${HEADER_FILES})
install(TARGETS loguru DESTINATION lib)
install(FILES ${HEADER_FILES} DESTINATION include)

add_executable(sst_example
		${EXAMPLE_CC_FILES}
		${HEADER_FILES})

target_link_libraries(sst_example loguru)
target_link_libraries(sst_example pthread)

install(TARGETS sst_example DESTINATION bin)