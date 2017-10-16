//
// Created by chris on 17-9-28.
//

#ifndef ORCHIDFLOW_TENSOR_H
#define ORCHIDFLOW_TENSOR_H

#include "base.h"
#include "tuple.h"
#include "dtype.h"
#include <functional>

namespace orchidflow
{

    template <typename valueType>
    class Tensor {
    public:
        Tensor() = default;
        inline Tensor(const Shape& s) {
            shape_ = s;
            num_elements_ = s.num_elements();
            num_allocated_data_ = num_elements_;
            data_ = new valueType[num_allocated_data_];
            deviceMask_ = DeviceMask::kCPU;
            deleteFunc_ = [](valueType* d){delete [] d;};
        }

        inline Tensor(const Shape& s, DeviceMask dm,
                      std::function<valueType* (size_t)> allocated_func,
                      std::function<void (valueType* )> delete_func) {
            shape_ = s;
            num_elements_ = s.num_elements();
            num_allocated_data_ = num_elements_;
            data_ = allocated_func(num_allocated_data_);
            deviceMask_ = dm;
        }

        inline Tensor(const Tensor<valueType>& s) {
            shape_ = s.shape();
            num_elements_ = s.num_elements();
            num_allocated_data_ = s.num_elements();
            data_ = new valueType[num_allocated_data_];
            assign(s.begin(), s.end());
            deviceMask_ = DeviceMask::kCPU;
        }

        inline Tensor(const Tensor<valueType>& s, DeviceMask dm,
                        std::function<valueType* (size_t)> allocated_func,
                        std::function<void (valueType*)> deleted_func,
                        std::function<valueType* (valueType *src, valueType *dst, size_t size)> copy_mem_func) {
            shape_ = s.shape();
            num_elements_ = s.num_elements();
            num_allocated_data_ = s.num_elements();
            deleteFunc_ = deleted_func;
            deviceMask_ = dm;
            if(dm == DeviceMask::kCPU) {
                data_ = allocated_func(num_allocated_data_);
                copy_mem_func(s.data_, data_, num_allocated_data_);
            }
        }

        inline Tensor(Tensor<valueType>&& s) noexcept{
            shape_ = std::move(s.shape_);
            num_elements_ = s.num_elements();
            num_allocated_data_ = s.num_allocated_data_;
            data_ = s.data_;
            deviceMask_ = DeviceMask::kCPU;

            s.shape_ = {};
            s.num_elements_ = 0;
            s.num_allocated_data_ = 0;
            s.data_ = nullptr;
        }


        ~Tensor() {
            deleteFunc_(data_);
        }

        inline Tensor& operator=(const Tensor<valueType>& s) {
            shape_ = s.shape_;
            num_elements_ = s.num_elements();
            num_allocated_data_ = s.num_elements();
            data_ = new valueType[num_allocated_data_];
            assign(s.begin(), s.end());
            deviceMask_ = s.deviceMask_;
        }

        inline Tensor& operator=(Tensor<valueType>&& s) {
            shape_ = std::move(s.shape_);
            num_elements_ = s.num_elements();
            num_allocated_data_ = s.num_allocated_data_;
            data_ = s.data_;
            deviceMask_ = s.deviceMask_;

            s.shape_ = {};
            s.num_elements_ = 0;
            s.num_allocated_data_ = 0;
            s.data_ = nullptr;
        }

        template <typename randomType>
        inline bool operator==(const Tensor<randomType>& s) const {
            return (dtype_ == s.dtype() && shape_ == s.shape() && std::equal(s.begin(), s.end(), begin()));
        }

        template <typename randomType>
        inline bool operator!=(const Tensor<randomType>& s) const {
            return !(*this != s);
        }

        inline valueType& operator[](const size_t& index) {
            return data_[index];
        }

        inline const valueType& operator[](const size_t& index) const {
            return data_[index];
        }

        inline const Shape& shape() const {
            return shape_;
        }

        inline const DTYPE& dtype() const {
            return dtype_;
        }

        inline valueType* begin() const {
            return data_;
        }

        inline valueType* end() const {
            return data_ + num_elements();
        }

        inline const size_t num_elements() const {
            return num_elements_;
        }

    private:
        template <typename RandomIterator>
        void assign(RandomIterator begin, RandomIterator end) {
            std::copy(begin, end, begin());
        }

        valueType *data_{nullptr};
        Shape shape_{0};
        size_t num_elements_;
        size_t num_allocated_data_{0};
        DeviceMask deviceMask_{DeviceMask::kCPU};
        DTYPE dtype_{Dtype::typeinfo2DTYPE(typeid(valueType).name())};

        std::function<void (valueType*)> deleteFunc_{nullptr};
        //std::function<void (valueType*)> allocateFunc_{nullptr};
    };
}

#endif //ORCHIDFLOW_TENSOR_H
