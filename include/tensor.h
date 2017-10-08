//
// Created by chris on 17-9-28.
//

#ifndef ORCHIDFLOW_TENSOR_H
#define ORCHIDFLOW_TENSOR_H

#include "base.h"
#include "tuple.h"
#include "dtype.h"

namespace orchidflow
{

    template <typename valueType>
    class Tensor {
    public:
        Tensor() = default;
        inline Tensor(const Shape& shape);
        inline Tensor(const Tensor<valueType>& s);
        inline Tensor(Tensor<valueType>&& s);
        inline Tensor(Shape& shape, valueType* data);

        ~Tensor();

        inline Tensor& operator=(const Tensor<valueType>& s);
        inline Tensor& operator=(Tensor<valueType>&& s);

        inline bool operator==(Tensor<valueType>& s);
        inline bool operator!=(Tensor<valueType>& s);

        inline valueType operator[](const Shape& s);
        inline valueType operator[](const std::initializer_list<valueType>& s);
        inline valueType * data();

        inline Shape& shape();

        inline DTYPE dtype();

    private:
        valueType data_{nullptr};
        Shape shape_{0};
        size_t num_allocated_data_{0};
        DeviceMask deviceMask_{DeviceMask::kCPU};
        DTYPE dtype_{Dtype::typeinfo2DTYPE(typeid(valueType).name())};
    };


//    Tensor() = default;
//    inline Tensor(const Shape& shape);
//    inline Tensor(const Tensor<valueType>& s);
//    inline Tensor(Tensor<valueType>&& s);
//    inline Tensor(Shape& shape, valueType* data);
//
//    ~Tensor();
//
//    inline Tensor& operator=(const Tensor<valueType>& s);
//    inline Tensor& operator=(Tensor<valueType>&& s);
//
//    inline bool operator==(Tensor<valueType>& s);
//    inline bool operator!=(Tensor<valueType>& s);
//
//    inline valueType operator[](const Shape& s);
//    inline valueType operator[](const std::initializer_list<valueType>& s);
//    inline valueType * data();
//
//    inline Shape& shape();
//
//    inline DTYPE dtype();

}

#endif //ORCHIDFLOW_TENSOR_H
