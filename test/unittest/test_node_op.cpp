//
// Created by chris on 17-10-14.
//

#include "../lib/catch.h"
#include "../../include/node.h"
#include "../../include/op.h"

using namespace std;
using namespace orchidflow;

TEST_CASE("test_node_op", "node_op_all_case") {
    auto node = Node::Create();
    REQUIRE(node->is_variable() == true);
}