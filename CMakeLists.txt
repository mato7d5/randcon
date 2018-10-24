cmake_minimum_required(VERSION 3.10)

project(cpprak C CXX)
set(APPNAME randcon)

set(CMAKE_CXX_STANDARD 17)

if (APPLE)
    set(CLANG_BREW_LDFLAGS "-L/usr/local/opt/llvm/lib -Wl,-rpath,/usr/local/opt/llvm/lib")
else()
set(CLANG_BREW_LDFLAGS "")
endif()

find_package(Boost REQUIRED COMPONENTS program_options)

include_directories(${Boost_INCLUDE_DIR})
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB APP_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(${APPNAME} ${APP_SRCS})
target_link_libraries(${APPNAME} ${CLANG_BREW_LDFLAGS} c++experimental ${Boost_LIBRARIES}) 
