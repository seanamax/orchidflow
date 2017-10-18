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

    inline Op& Op::set_num_inputs(uint32_t n) {
        this->num_inputs = n;
        return *this;
    }

    inline Op& Op::set_num_inputs(std::function<uint32_t (const NodeAttrs &attr)> fn) {
        this->get_num_inputs = fn;
        return *this;
    }

    inline Op& Op::set_num_outputs(uint32_t n) {
        this->num_outputs = n;
        return *this;
    }

    inline Op& Op::set_num_outputs(std::function<uint32_t (const NodeAttrs &attr)> fn) {
        this->get_num_outputs = fn;
        return *this;
    }

    inline Op& Op::set_attr_parser(std::function<void (NodeAttrs* attrs)> fn) {
        this->attr_parser = fn;
        return *this;
    }

    template <typename value_type>
    inline Op& Op::set_attr(const std::string& attr_name,
                            const value_type &value,
                            int plevel) {
        assert(plevel > 0 && "pleval in set_attr must be greater than 0");


    }

}