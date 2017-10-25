//
// Created by chris on 17-10-14.
//

#include "../lib/catch.h"
#include "../../include/node.h":
#include "../../include/op.h"
#include <thread>

using namespace orchidflow;
using namespace std;

TEST_CASE("test_node_op", "test_all_unit")
{
    REQUIRE(std::thread::hardware_concurrency() == 8);

}