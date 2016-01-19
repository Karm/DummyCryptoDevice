cmake_minimum_required(VERSION 3.3)
project(DummyCryptoDevice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=C99")

FIND_PACKAGE(OpenSSL REQUIRED)

set(SOURCE_FILES "src/e_dummy.c")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "bin/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")
add_library(libdummy SHARED ${SOURCE_FILES})