//
// Created by chris on 17-10-16.
//

#include "../../include/node.h"
#include "../../include/op.h"
#include <algorithm>

namespace orchidflow
{
    inline Op* Node::op() {
        return attr.op;
    }

    NodePtr Node::Create() {
        NodePtr nodeptr = std::make_shared<Node>();//std::shared_ptr<Node>(new Node);
        return nodeptr;
    }

    bool Node::is_variable() {
        return (op() == nullptr);
    }

}
