//
// Created by chris on 17-10-2.
//

#ifndef ORCHIDFLOW_VARIATE_H
#define ORCHIDFLOW_VARIATE_H

#include "tensor.h"


namespace orchidflow
{

    template <typename valueType>
    struct Variate
    {
        Tensor<valueType>* input_{nullptr};
        Tensor<valueType>* grad_{nullptr};
        valueType constAttr_;
        bool isConstAttr_{true};
        bool havedgrad_{false};
        bool isgradzero_{true};
    };

}

#endif //ORCHIDFLOW_VARIATE_H
