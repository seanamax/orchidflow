cmake_minimum_required(VERSION 3.8)
project(orchidflow)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/graph/main.cpp include/tuple.h include/base.h include/tensor.h include/variate.h include/graph.h include/op.h include/node.h test/catch.h include/dtype.h)

add_executable(orchidflow ${SOURCE_FILES})
