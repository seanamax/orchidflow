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
        Tensor<valueType> input_;
        Tensor<valueType> grad_;
        bool havedgrad_{false};
        bool isgradzero_{true};
    };


//    template <typename valueType>
//    class Variate
//    {
//    public:
//        Variate() = default;
//        inline Variate(const Tensor<valueType>& input, const Tensor<valueType>& grad);
//        inline Variate(Tensor<valueType>&& input, Tensor<valueType>&& grad);
//
//        ~Variate() = default;
//
//        inline Variate& operator=(const Variate& s);
//        inline Variate& operator=(Variate&& s);
//
//        inline bool operator==(const Variate& s);
//        inline bool operator!=(const Variate& s);
//
//        inline Tensor<valueType>& input();
//        inline Tensor<valueType>& grad();
//
//        inline Tensor<valueType>& input(const Tensor<valueType>& s);
//        inline Tensor<valueType>& grad(const Tensor<valueType>& s);
//        inline Tensor<valueType>& input(Tensor<valueType>&& s);
//        inline Tensor<valueType>& grad(Tensor<valueType>&& s);
//
//    private:
//        Tensor<valueType> input_;
//        Tensor<valueType> grad_;
//    };
}

#endif //ORCHIDFLOW_VARIATE_H
