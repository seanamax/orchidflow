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
    // 获得计算图的正向计算顺序
    std::vector<std::vector<NodePtr>> TopoSort(const std::vector<NodePtr>& node_list);

    // 遍历到计算图的最终输出节点并返回最终输出节点
    std::vector<NodePtr> find_final_outputs(NodePtr nodeptr);

    // 递归到最终输入节点并递归返回节点的层级。
    int find_final_inputs(std::map<NodePtr, int>& is_searched, NodePtr nodeptr);

    // 获得计算图的反向计算顺序
    std::vector<std::vector<NodePtr>> ReverseTopoSort(std::vector<std::vector<NodePtr>>& forward_compute_node_list);

    class Graph
    {
    public:
        Graph() = default;
        Graph(const std::vector<NodePtr>& s);
        Graph(std::vector<NodePtr>&& s);

        Graph& operator=(const std::vector<NodePtr>& s);
        Graph& operator=(std::vector<NodePtr>&& s);


        inline std::vector<NodePtr>::iterator begin();
        inline std::vector<NodePtr>::iterator end();

        inline bool operator==(const Graph& s);
        inline bool operator!=(const Graph& s);

        void forward_compute();
        void gradient_compute();
        void backward_compute();

    private:
        std::vector<NodePtr> node_list_;
    };




}

#endif //ORCHIDFLOW_GRAPH_H
