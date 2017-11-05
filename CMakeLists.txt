cmake_minimum_required(VERSION 3.8)
project(orchidflow)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_INCLUDE include/base.h include/dtype.h include/graph.h include/node.h include/op.h include/tensor.h include/tuple.h include/variate.h)
set(SOURCE_FILES src/graph/node.cpp src/graph/op.cpp src/graph/main.cpp src/graph/graph.cpp)
set(TEST_FILES src/graph/main.cpp test/unittest/test_node_op.cpp test/unittest/test_dtype.cpp test/unittest/test_tuple.cpp test/unittest/test_tensor.cpp test/unittest/test_graph.cpp)

add_executable(orchidflow ${SOURCE_INCLUDE} ${SOURCE_FILES} ${TEST_FILES})

