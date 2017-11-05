//
// Created by chris on 17-11-5.
//

#include "../lib/catch.h"
#include "../../include/graph.h"

using namespace std;
using namespace orchidflow;

TEST_CASE("test_graph", "graph_test") {
    NodePtr a = make_shared<Node>();
    NodePtr b = make_shared<Node>();
    NodePtr c = make_shared<Node>();
    NodePtr d = make_shared<Node>();
    NodePtr e = make_shared<Node>();

    Op* op = new Op();
    a->attr.op = op;
    b->attr.op = op;
    c->attr.op = op;

    a->attr.inputs.push_back(b);
    b->attr.inputs.push_back(c);
    b->attr.inputs.push_back(d);
    c->attr.inputs.push_back(e);

    vector<NodePtr> node_list;
    node_list.push_back(a);
    Graph graph(node_list);
    auto node_level_list = TopoSort(node_list);

    REQUIRE(a->is_variable() == false);
    REQUIRE(node_level_list.size() == 4);
    REQUIRE(node_level_list[0].size() == 2);
    REQUIRE(node_level_list[1][0] == c);
    REQUIRE(node_level_list[2][0] == b);
    REQUIRE(node_level_list[3][0] == a);

    delete op;
}