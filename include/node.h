//
// Created by chris on 17-10-2.
//

#ifndef ORCHIDFLOW_NODE_H
#define ORCHIDFLOW_NODE_H

#include <vector>
#include "variate.h"

namespace orchidflow
{
    template <typename valueType>
    class Node
    {
    public:
        Variate<valueType>& variate();
        

    private:
        Variate<valueType> variate_;
        std::vector<Node<valueType>> inputs_;
        std::string name_;
        valueType constAttr_;
        bool isConstAttr_;
    };
}

#endif //ORCHIDFLOW_NODE_H
