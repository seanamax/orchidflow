//
// Created by chris on 17-10-16.
//

#include "../../include/node.h"
#include "../../include/op.h"
#include <algorithm>

namespace orchidflow
{
    inline const Op* Node::op() const {
        return this->attrs.op;
    }

    inline bool Node::is_variable() const {
        return this->op() == nullptr;
    }

    uint32_t Node::num_outputs() const {
        if(is_variable()) {
            return 1;
        }

        if(this->op()->get_num_outputs == nullptr) {
            return this->op()->num_outputs;
        } else {
            return this->op()->get_num_outputs(this->attrs);
        }
    }

    uint32_t Node::num_inputs() const {
        if(is_variable()) {
            return 1;
        }
        if(this->op()->get_num_inputs == nullptr) {
            return this->op()->num_inputs;
        } else {
            return this->op()->get_num_inputs(this->attrs);
        }
    }

    NodePtr Node::Create() {
        NodePtr nodeptr = std::make_shared<Node>();//std::shared_ptr<Node>(new Node);
        return nodeptr;
    }

}
