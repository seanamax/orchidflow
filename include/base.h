//
// Created by chris on 17-9-27.
//

#ifndef ORCHIDFLOW_BASE_H
#define ORCHIDFLOW_BASE_H

namespace orchidflow
{
    using uint32_t = unsigned int;
    using int32_t = signed int;
    using uint64_t = unsigned long long;
    using int64_t = signed long long;
    using float32_t = float;
    using float64_t = double;
    using uchar_t = unsigned char;
    using char_t = char;

    using dim_t = int64_t;

    template <typename valueType>
    class Node;

    template <typename valueType>
    class Op;


    enum class DeviceMask
    {
        kCPU,
        kGPU
    };

}

#endif //ORCHIDFLOW_BASE_H
