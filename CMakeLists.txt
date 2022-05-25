cmake_minimum_required(VERSION 3.22)
project(web_client)

set(CMAKE_CXX_STANDARD 23)

add_library(web_client library.cpp type/request_type.cpp type/request_type.hpp commons/commons.cpp commons/commons.hpp)