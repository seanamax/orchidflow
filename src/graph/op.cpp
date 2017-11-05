//
// Created by chris on 17-10-16.
//

#include "../../include/op.h"
#include "../../include/node.h"
#include <cassert>

namespace orchidflow
{

    inline Op& Op::describe(const std::string &descr) {
        this->description = descr;
        return *this;
    }

    inline void Op::forward_compute(NodeAttr& attr) {
        forward_compute_fn(attr);
    }

    inline void Op::set_forward_compute(std::function<void(NodeAttr& attr)>& forward_compute_fn) {
        this->forward_compute_fn = std::move(forward_compute_fn);
    }

    inline NodeAttr Op::gradient_compute(NodeAttr& attr) {
        gradient_compute_fn(attr);
    }

    inline void Op::set_gradient_compute(std::function<NodeAttr(NodeAttr& )>& gradient_compute_fn) {
        this->gradient_compute_fn = std::move(gradient_compute_fn);
    }
}