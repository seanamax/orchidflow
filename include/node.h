//
// Created by chris on 17-10-2.
//

#ifndef ORCHIDFLOW_NODE_H
#define ORCHIDFLOW_NODE_H

#include <vector>
#include <memory>
#include "variate.h"


namespace orchidflow
{
    // Forward declare node.
    class Node;
    class Op;

    // By default, NodePtr is a std::shared_ptr of node
    using NodePtr = std::shared_ptr<Node>;

    // brief an entry that represents output data from node.
    struct NodeEntry {
        // brief the source node of this data
        NodePtr node;
        // brief index of output from the source.
        uint32_t index;

        // brief version of input Variable.
        // This field can only by nonzero when this->node is a Variable node.
        // version is increased by one each time a Variable get composed to a mutation Op.
        // This information can be helpfule to decide order of operations when sequence of mutation happens.
        uint32_t version;
    };

    // brief The attributes of the current operation node.
    // Usually are additional parameters like axis
    struct NodeAttrs {
        // brief The attributes of the current operation node.
        // For place holder variable, op == nullptr.
        const Op *op{nullptr};

        // brief name of the node.
        std::string name;

        // brief The dictionary representation of attributes.
        std::unordered_map<std::string, std::string> dict;
    };

    class Node {
    public:
        NodeAttrs attrs;
        std::vector<NodeEntry> inputs;
        std::vector<NodePtr> control_deps;

        inline const Op* op() const;
        inline bool is_variable() const;
        inline uint32_t num_outputs() const;
        inline uint32_t num_inputs() const;
        static NodePtr Create();

        Node() = default;

        ~Node() {};
    };
}

#endif //ORCHIDFLOW_NODE_H
