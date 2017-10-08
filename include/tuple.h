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
        ~Tuple();

        inline Tuple(const Tuple<valueType>& s);
        inline Tuple(Tuple<valueType>&& s) noexcept;
        inline Tuple(std::initializer_list<valueType>& s);


        template <typename RandomIterator>
        inline Tuple(RandomIterator begin, RandomIterator end);


        inline Tuple<valueType>& operator=(const Tuple<valueType>& s);
        inline Tuple<valueType>& operator=(Tuple<valueType>&& s) noexcept;
        inline Tuple<valueType>& operator=(const std::initializer_list<valueType>& s);


        bool operator==(const Tuple<valueType>& s);
        bool operator!=(const Tuple<valueType>& s);


        // brief the size of tuple which is dimension of tensor.
        inline size_t ndim() const;

        // brief the total size of the tensor.
        inline size_t num_elements() const;

        inline valueType& operator[](const size_t i);
        inline const valueType& operator[](const size_t i) const;

        inline valueType * begin() const {
            return data_;
        }

        inline valueType * end() const {
            return (data_ + ndim_);
        }

        friend std::ostream & operator<<(std::ostream &os, Tuple<valueType> &s);
        friend std::istream & operator>>(std::istream &is, Tuple<valueType> &s);

    protected:

        template <typename RandomIterator>
        void assign(RandomIterator begin, RandomIterator end);


        valueType *data_{nullptr};
        size_t size_allocated_data_{0};
        size_t ndim_{0};
        size_t num_elements_{0};
    };


    template <typename valueType>
    Tuple<valueType>::~Tuple() {
        delete [] data_;
    }

    template <typename valueType>
    inline Tuple<valueType>::Tuple(const Tuple<valueType>& s) {
        delete[] data_;

        data_ = new valueType[s.ndim_];
        size_allocated_data_ = s.size_allocated_data_;
        ndim_ = s.ndim_;
        num_elements_ = s.num_elements_;
        this->assign(s.data_, s.data_ + s.ndim_);
    }

    template <typename valueType>
    inline size_t Tuple<valueType>::ndim() const {
        return ndim_;
    }

    template <typename valueType>
    inline Tuple<valueType>::Tuple(Tuple<valueType> &&s) noexcept {
        data_ = s.data_;
        size_allocated_data_ = s.size_allocated_data_;
        ndim_ = s.ndim_;
        num_elements_ = s.num_elements_;

        s.data_ = nullptr;
        s.size_allocated_data_ = 0;
        s.ndim_ = 0;
        s.num_elements_ = 0;
    }

    template <typename valueType>
    inline Tuple<valueType>::Tuple(std::initializer_list<valueType> &s) {
        ndim_ = s.end() - s.begin();
        size_allocated_data_ = ndim_;
        data_ = new valueType[size_allocated_data_];

        assign(s.begin(), s.end());
        num_elements_ = 1;
        for(int i=0; i < size_allocated_data_; ++i) {
            num_elements_ *= data_[i];
        }
    }

    template <typename valueType>
    template <typename RandomIterator>
    inline Tuple<valueType>::Tuple(RandomIterator begin, RandomIterator end) {
        ndim_ = end - begin;
        size_allocated_data_ = ndim_;
        data_ = new valueType[size_allocated_data_];

        assign(begin, end);
        num_elements_ = 1;
        for(int i=0; i < size_allocated_data_; ++i) {
            num_elements_ *= data_[i];
        }
    }


    template <typename valueType>
    inline Tuple<valueType>& Tuple<valueType>::operator=(const Tuple<valueType>& s) {
        delete [] data_;

        ndim_ = s.ndim_;
        size_allocated_data_ = ndim_;
        num_elements_ = s.num_elements_;
        data_ = new valueType[ndim_];
        assign(s.begin(), s.end());

        return *this;
    }


    template <typename valueType>
    inline Tuple<valueType>& operator=(Tuple<valueType>&& s) noexcept {
        delete [] data_;

        ndim_ = s.ndim_;
        size_allocated_data_ = ndim_;
        num_elements_ = s.num_elements_;
        data_ = s.data_;

        s.data_ = nullptr;
        s.ndim_ = 0;
        s.size_allocated_data_ = 0;
        s.num_elements_ = 0;

        return *this;
    }

    template <typename valueType>
    inline Tuple<valueType>& Tuple<valueType>::operator=(const std::initializer_list<valueType>& s) {
        delete [] data_;

        ndim_ = s.end() - s.begin();
        size_allocated_data_ = ndim_;
        data_ = new valueType[size_allocated_data_];

        assign(s.begin(), s.end());
        num_elements_ = 1;
        for(int i=0; i < size_allocated_data_; ++i) {
            num_elements_ *= data_[i];
        }

        return *this;
    }


    template <typename valueType>
    inline bool Tuple<valueType>::operator==(const Tuple<valueType>& s) {
        return (ndim_ == s.ndim_ && std::equal(s.begin(), s.end(), begin()));
    }

    template <typename valueType>
    inline bool Tuple<valueType>::operator!=(const Tuple<valueType>& s) {
        return !(*this == s);
    }


    template <typename valueType>
    inline size_t Tuple<valueType>::ndim() const {
        return ndim_;
    }

    template <typename valueType>
    inline size_t Tuple<valueType>::num_elements() const {
        return num_elements_;
    }


    template <typename valueType>
    inline valueType& Tuple<valueType>::operator[](const size_t i) {
        return begin()[i];
    }

    template <typename valueType>
    inline const valueType& Tuple<valueType>::operator[](const size_t i) const {
        return begin()[i];
    }



    template <typename valueType>
    friend std::ostream & Tuple<valueType>::operator<<(std::ostream &os, Tuple<valueType> &s) {

    }


    template <typename valueType>
    friend std::istream & Tuple<valueType>::operator>>(std::istream &is, Tuple<valueType> &s) {

    }



    class Shape: public Tuple<dim_t>
    {
    public:
        Shape() = default;
        ~Shape() = default;
        inline Shape(const Shape& s);
        inline Shape(Shape&& s);
        inline Shape(const std::initializer_list<dim_t> s);


        inline Shape& operator=(const Shape& s);
        inline Shape& operator=(Shape&& s);
        inline Shape& operator=(const std::initializer_list<dim_t>& s);

        template <typename RandomIterator>
        inline Shape& operator=(const RandomIterator begin, const RandomIterator end);


        inline bool operator==(const Shape& s);
        inline bool operator!=(const Shape& s);

    };
}

#endif //ORCHIDFLOW_TUPLE_H
