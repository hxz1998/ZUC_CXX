cmake_minimum_required(VERSION 3.17)
project(ZUC_CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(ZUC-test ZUC-test.cpp include/ZUC.h)

add_executable(key-pool-test key-pool-test.cpp include/key-pool.h include/ZUC.h)