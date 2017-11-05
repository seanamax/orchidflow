//
// Created by chris on 17-10-2.
//

#ifndef ORCHIDFLOW_OP_H
#define ORCHIDFLOW_OP_H

#include "base.h"
#include "node.h"
#include <string>
#include <vector>
#include <functional>
#include <limits>

namespace orchidflow
{
    class Op;
    class Node;

    class Op
    {
    public:
        std::string name;
        std::string description;


        std::function<void(NodeAttr& attr)> gradient_compute_fn{nullptr};
        std::function<void(NodeAttr& attr)> forward_compute_fn{nullptr};

        Op& describe(const std::string& descr);

        void forward_compute(NodeAttr& attr);
        void set_forward_compute(std::function<void(NodeAttr& attr)> &forward_compute_fn);

        NodeAttr gradient_compute(NodeAttr& attr);
        void set_gradient_compute(std::function<NodeAttr(NodeAttr& )> &gradient_compute_fn);
    };
}

#endif //ORCHIDFLOW_OP_H
