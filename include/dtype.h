//
// Created by chris on 17-10-4.
//

#ifndef ORCHIDFLOW_DTYPE_H
#define ORCHIDFLOW_DTYPE_H

#include <typeinfo>
#include <string>
#include <unordered_map>

namespace orchidflow
{
    enum class DTYPE {
        uchar8_t,
        char8_t,
        string,
        int32_t,
        uint32_t,
        int64_t,
        uint64_t,
        float32_t,
        float64_t
    };

    template <typename valueType>
    class __Dtype
    {
    public:
        static DTYPE typeinfo2DTYPE(const valueType& s) {
            return instance().keymap_[s];
        }


    private:
        static __Dtype& instance() {
            static __Dtype *s = new __Dtype();
            return *s;
        }


        __Dtype() {
            keymap_[typeid(unsigned char).name()] = DTYPE::uchar8_t;
            keymap_[typeid(signed char).name()] = DTYPE::char8_t;
            keymap_[typeid(signed int).name()] = DTYPE::int32_t;
            keymap_[typeid(unsigned int).name()] = DTYPE::uint32_t;
            keymap_[typeid(signed long long).name()] = DTYPE::int64_t;
            keymap_[typeid(unsigned long long).name()] = DTYPE::uint64_t;
            keymap_[typeid(float).name()] = DTYPE::float32_t;
            keymap_[typeid(double).name()] = DTYPE::float64_t;
            keymap_[typeid(std::string).name()] = DTYPE::string;
        }


    private:
        std::unordered_map<decltype(typeid(int).name()), DTYPE> keymap_;
    };

    using Dtype = __Dtype<decltype(typeid(int).name())>;
}

#endif //ORCHIDFLOW_DTYPE_H
