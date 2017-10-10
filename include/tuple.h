//
// Created by chris on 17-9-27.
//

#ifndef ORCHIDFLOW_TUPLE_H
#define ORCHIDFLOW_TUPLE_H

#include <cstdio>
#include <initializer_list>
#include <ostream>
#include "base.h"


namespace orchidflow
{
    template <typename valueType>
    class Tuple
    {
    public:
        Tuple() = default;
        ~Tuple() {
            delete [] data_;
        }

        inline Tuple(const Tuple<valueType>& s) {
            ndim_ = s.ndim();
            size_allocated_data_ = s.ndim();
            data_ = new valueType[size_allocated_data_];
            assign(s.begin(), s.end());
        }

        inline Tuple(Tuple<valueType>&& s) noexcept {
            ndim_ = s.ndim();
            size_allocated_data_ = s.size_allocated_data_;
            data_ = s.data_;

            s.data_ = nullptr;
            s.size_allocated_data_ = 0;
            s.ndim_ = 0;
        }

        inline Tuple(const std::initializer_list<valueType>& s) {
            ndim_ = s.end() - s.begin();
            size_allocated_data_ = ndim();
            data_ = new valueType[ndim()];
            assign(s.begin(), s.end());
        }


        template <typename RandomIterator>
        inline Tuple(RandomIterator begin, RandomIterator end) {
            ndim_ = end - begin;
            size_allocated_data_ = ndim();
            data_ = new valueType[ndim()];
            assign(begin, end);
        }



        inline Tuple<valueType>& operator=(const Tuple<valueType>& s) {
            ndim_ = s.ndim();
            if(size_allocated_data_ < ndim()) {
                delete [] data_;
                size_allocated_data_ = ndim();
                data_ = new valueType[size_allocated_data_];
            }
            assign(s.begin(), s.end());

            return *this;
        }

        inline Tuple<valueType>& operator=(Tuple<valueType>&& s) noexcept {
            delete [] data_;

            ndim_ = s.ndim();
            size_allocated_data_ = s.size_allocated_data_;
            data_ = s.data_;

            s.data_ = nullptr;
            s.ndim_ = 0;
            s.size_allocated_data_ = 0;

            return *this;
        }

        inline Tuple<valueType>& operator=(const std::initializer_list<valueType>& s) {
            ndim_ = s.end() - s.begin();
            if(size_allocated_data_ < ndim()) {
                delete [] data_;
                size_allocated_data_ = ndim();
                data_ = new valueType[size_allocated_data_];
            }
            assign(s.begin(), s.end());

            return *this;
        }


        bool operator==(const Tuple<valueType>& s) {
            return ((ndim() == s.ndim()) && std::equal(begin(), end(), s.begin()));
        }

        bool operator!=(const Tuple<valueType>& s) {
            return !(*this == s);
        }


        // brief the size of tuple which is dimension of tensor.
        inline size_t ndim() const {
            return ndim_;
        }



        inline valueType& operator[](const size_t i) {
            return begin()[i];
        }

        inline const valueType& operator[](const size_t i) const {
            return begin()[i];
        }

        inline valueType* begin() const {
            return data_;
        }

        inline valueType* end() const {
            return (data_ + ndim());
        }

//        friend std::ostream & operator<<(std::ostream &os, Tuple<valueType> &s);
//        friend std::istream & operator>>(std::istream &is, Tuple<valueType> &s);

    protected:

        template <typename RandomIterator>
        inline void assign(RandomIterator begin, RandomIterator end) {
            std::copy(begin, end, data_);
        }



        valueType *data_{nullptr};
        size_t size_allocated_data_{0};
        size_t ndim_{0};
    };


    class Shape: public Tuple<dim_t>
    {
    public:
        Shape() = default;
        inline Shape(const Tuple<dim_t>& s) : Tuple(s) {}
        inline Shape(Tuple<dim_t>&& s) : Tuple(std::move(s)) {}
        inline Shape(const std::initializer_list<dim_t>& s) : Tuple(s) {}

        inline Shape(const Shape& s) : Tuple(s.begin(), s.end()) {}
        inline Shape(Shape&& s) {
            data_ = s.data_;
            size_allocated_data_ = s.size_allocated_data_;
            ndim_ = s.ndim();

            s.data_ = nullptr;
            s.size_allocated_data_ = 0;
            s.ndim_ = 0;
        }

        ~Shape() {};

        template <typename RandomIterator>
        inline Shape(RandomIterator begin, RandomIterator end) : Tuple(begin, end) {}

//        inline Shape& operator=(const Tuple<dim_t>& s);
//        inline Shape& operator=(Tuple<dim_t>&& s) noexcept;
        inline Shape& operator=(const Shape& s) {
            *this = static_cast<Tuple<dim_t>>(s);
            return *this;
        }

        inline Shape& operator=(Shape &&s) noexcept {
            delete data_;
            data_ = s.data_;
            size_allocated_data_ = s.size_allocated_data_;
            ndim_ = s.ndim();

            s.data_ = nullptr;
            s.size_allocated_data_ = 0;
            s.ndim_ = 0;

            return *this;
        }
//        inline Shape& operator=(const std::initializer_list<dim_t>& s);


        inline bool operator==(const Shape& s) {
            return static_cast<Tuple<dim_t>>(*this) == static_cast<Tuple<dim_t>>(s) ;
        }
//        inline bool operator==(const Tuple<dim_t>& s);

        inline bool operator!=(const Shape& s) {
            return !(*this == s);
        }
//        inline bool operator!=(const Tuple<dim_t>& s);


        // brief the total size of the tensor.
        inline size_t num_elements() const {
            return count_num_elements();
        }

    private:
        inline size_t count_num_elements() const {
            size_t nums = 1;
            bool is_count = false;
            for(int i=0; i < ndim(); ++i) {
                nums *= data_[i];
                is_count = true;
            }
            return (is_count ? nums : 0);
        }
    };
}

#endif //ORCHIDFLOW_TUPLE_H
