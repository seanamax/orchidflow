//
// Created by chris on 17-10-2.
//

#ifndef ORCHIDFLOW_NODE_H
#define ORCHIDFLOW_NODE_H

#include <vector>
#include <memory>
#include <functional>
#include "variate.h"

namespace orchidflow
{
    class Node;
    class Op;

    using NodePtr = std::shared_ptr<Node>;

    struct NodeAttr
    {
        std::vector<NodePtr> inputs;
        std::vector<NodePtr> outputs;
        std::string name;
        std::string description;
        Op* op{nullptr};
    };

    class Node
    {
    public:
        NodeAttr attr;
        bool is_variable();
        Op* op();
        static NodePtr Create();
    };
}

#endif //ORCHIDFLOW_NODE_H
