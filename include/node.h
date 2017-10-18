//
// Created by chris on 17-10-2.
//

#ifndef ORCHIDFLOW_NODE_H
#define ORCHIDFLOW_NODE_H

#include <vector>
#include <bits/shared_ptr.h>
#include "variate.h"
#include "op.h"

namespace orchidflow
{
    // Forward declare node.
    class Node;

    using NodePtr = std::shared_ptr<Node>;

    struct NodeEntry {
        NodePtr node;
        uint32_t index;
        uint32_t version;
    };

    struct NodeAttrs {
        const Op *op{nullptr};
        std::string name;
        std::vector<double> scalars;
        std::unordered_map<std::string, std::string> dict;
    };

    class Node {
    public:
        NodeAttrs attrs;
        std::vector<NodeEntry> inputs;
        std::vector<NodePtr> control_deps;
        ~Node();
        inline const Op* op() const;
        inline bool is_variable() const;
        inline uint32_t num_outputs() const;
        inline uint32_t num_inputs() const;
        static NodePtr Create();
    };


}

#endif //ORCHIDFLOW_NODE_H
