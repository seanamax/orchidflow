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

    using NodePtr = std::shared_ptr<Node>;

    struct NodeEntry {
        NodePtr node;
        uint32_t index;
        uint32_t version;
    };

    struct NodeAttrs {
        const Op *op{nullptr};
        std::string name;
        std::vector<double> scalars;                        // 标量
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
        inline Node(const Node&);
        inline Node(Node&&) noexcept;

        inline Node& operator=(const Node&);
        inline Node& operator=(Node&&) noexcept;
        ~Node();
    };


}

#endif //ORCHIDFLOW_NODE_H
