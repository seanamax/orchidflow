//
// Created by chris on 17-10-2.
//

#ifndef ORCHIDFLOW_GRAPH_H
#define ORCHIDFLOW_GRAPH_H

#include <vector>
#include <map>
#include "node.h"
#include "op.h"

namespace orchidflow
{

//    template <typename valueType>
//    class Graph
//    {
//    public:
////        Graph() = default;
////        Graph(const std::vector<Node<valueType>>& s);
////        Graph(std::vector<Node<valueType>>&& s);
////
////        Graph& operator=(const std::vector<Node<valueType>>& s);
////        Graph& operator=(std::vector<Node<valueType>>&& s) noexcept;
////        Graph& operator=(const std::vector<Node<valueType>*>& s);
////        Graph& operator=(std::vector<Node<valueType>*>&& s) noexcept;
////        Node<valueType>& operator[](size_t index);
////
////        inline Node<valueType>* begin();
////        inline Node<valueType>* end();
////
////        bool operator==(const std::vector<Node<valueType>>& s);
////        bool operator!=(const std::vector<Node<valueType>>& s);
////
////        void forward();
////        void backward();
//
//
//
//        Graph() = default;
//        Graph(const std::vector<Node>& s);
//        Graph(std::vector<Node>&& s);
//
//        Graph& operator=(const std::vector<Node>& s);
//        Graph& operator=(std::vector<Node>&& s);
//        Graph& operator=(const std::vector<Node*>& s);
//        Graph& operator=(std::vector<Node*>&& s);
//
//        inline Node* begin();
//        inline Node* end();
//
//        bool operator==(const std::vector<Node>& s);
//        bool operator!=(const std::vector<Node>& s);
//
//        void forward();
//        void backward();
//
//    private:
//        std::vector<Node<valueType>> node_list_;
//
//    };












    class Graph
    {
    public:
        Graph() = default;
        Graph(const std::vector<Node>& s);
        Graph(std::vector<Node>&& s);

        Graph& operator=(const std::vector<Node>& s);
        Graph& operator=(std::vector<Node>&& s);
        Graph& operator=(const std::vector<Node*>& s);
        Graph& operator=(std::vector<Node*>&& s);

        inline Node* begin();
        inline Node* end();

        inline bool operator==(const Graph& s);
        inline bool operator!=(const Graph& s);

        void forward();
        void backward();

    private:
        std::vector<Node> node_list_;
    };
}

#endif //ORCHIDFLOW_GRAPH_H
