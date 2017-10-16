//
// Created by chris on 17-10-2.
//

#ifndef ORCHIDFLOW_NODE_H
#define ORCHIDFLOW_NODE_H

#include <vector>
#include "variate.h"
#include "op.h"

namespace orchidflow
{
    class Node
    {
    public:
        Node() = default;
//        Node(const std::vector<Node*> &inputs, const std::string& name);
//        Node(const Node& s);
//        Node(Node &&s) noexcept;
//        template <typename RandomType>
//        inline Node(const std::initializer_list<RandomType>& s);
//        ~Node() {}
//
//        inline std::vector<Node*>& inputs();
//        inline const std::vector<Node*>& inputs() const;
//
//        inline Node& operator=(const Node& s);
//        inline Node& operator=(Node&& s) noexcept;
//
//        inline Node& operator+(const Node& s);
//        inline Node& operator-(const Node& s);
//        inline Node& operator*(const Node& s);
//        inline Node& operator/(const Node& s);
//        inline Node& operator-();
//        inline Node& log();
//        inline Node& exp();
//        inline Node& sin();
//        inline Node& cos();
//        inline Node& tan();
//        inline Node& acos();
//        inline Node& asin();
//        inline Node& tanh();
//
//        inline const Op& op() const;
//        inline void setOp(const Op& op);

    private:
        std::vector<Node> inputs_;
        std::string name_;
        Op op_;
    };

//
//    // forward declared
//    template <typename valueType>
//    class Node;
//
//    // forward declared
//    template <typename valueType>
//    class Op;
//
//
//    template <typename valueType>
//    class Node
//    {
//    public:
//        Node() = default;
////        Node(const Tuple<Variate<valueType>*> &inputs, const std::string& name);
////        Node(const Node& s);
////        Node(Tuple<Variate<valueType>*> &&inputs, const std::string& name) noexcept;
////        Node(Node&& s);
////        Node(const valueType& s, const std::string& name);
////        template <typename RandomType>
////        Node(const std::initializer_list<RandomType>& s);
//
//
////        Node(const std::vector<Variate<valueType>*> &inputs, const std::string &name);
////        Node(const Node<valueType>& s);
////        Node(std::vector<Variate<valueType>*> &&inputs, const std::string &name);
////        Node(Node &&s);
////        Node(const valueType& s, const std::string& name);
////        template <typename RandomType>
////        Node(const std::initializer_list<RandomType>& s);
////
////        virtual ~Node() {};
////
////        inline Variate<valueType>* begin() const {
////            return inputs_.begin();
////        }
////
////        inline Variate<valueType>* end() const {
////            return inputs_.end();
////        }
////
////        inline std::vector<Variate<valueType>*>& inputs();
////        inline const std::vector<Variate<valueType>*>& inputs() const;
////
////        inline const Op<valueType>& op() const;
////        inline Op<valueType>& op();
////
////
////        inline Node<valueType>& operator=(const Node<valueType>& s);
////        inline Node<valueType>& operator=(Node<valueType>&& s);
////
////        template <typename RandomType>
////        inline Node<valueType>& operator+(const RandomType& s);
////
////        template <typename RandomType>
////        inline Node<valueType>& operator-(const RandomType& s);
////
////        template <typename RandomType>
////        inline Node<valueType>& operator*(const RandomType& s);
////
////        template <typename RandomType>
////        inline Node<valueType>& operator/(const RandomType& s);
////
////        template <typename RandomType>
////        inline Node<valueType>& operator-();
////
////        template <typename RandomType>
////        inline Node<valueType>& log(const RandomType& s);
////
////        template <typename RandomType>
////        inline Node<valueType>& exp(const RandomType& s);
////
////        template <typename RandomType>
////        inline Node<valueType>& sin();
////
////        template <typename RandomType>
////        inline Node<valueType>& cos();
////
////        template <typename RandomType>
////        inline Node<valueType>& tan();
////
////
////        template <typename RandomType>
////        inline Node<valueType>& tanh();
////
////        template <typename RandomType>
////        inline Node<valueType>& acos();
////
////        template <typename RandomType>
////        inline Node<valueType>& asin();
//
//        Op<valueType>& op() {
//            return op_;
//        }
//
//        void setOp(const Op<valueType>& s) {
//            op_ = s;
//        }
//
//    private:
//        std::vector<Node> inputs_{nullptr};
//        std::string name_;
//        Op<valueType> op_;
//
//        template <typename RandomType>
//        void assign(RandomType begin, RandomType end) {
//            std::copy(begin, end, begin());
//        }
//    };


}

#endif //ORCHIDFLOW_NODE_H
