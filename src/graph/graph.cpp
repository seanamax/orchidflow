//
// Created by chris on 17-11-3.
//

#include <algorithm>
#include "../../include/graph.h"

namespace orchidflow {

    Graph::Graph(const std::vector<NodePtr>& s) {
        node_list_ = s;
    }

    Graph::Graph(std::vector<NodePtr>&& s) {
        node_list_ = std::move(s);
    }

    Graph& Graph::operator=(const std::vector<NodePtr>& s) {
        node_list_ = s;
        return *this;
    }

    Graph& Graph::operator=(std::vector<NodePtr>&& s) {
        node_list_ = std::move(s);
        return *this;
    }


    std::vector<NodePtr>::iterator Graph::begin() {
        return node_list_.begin();
    }

    std::vector<NodePtr>::iterator Graph::end() {
        return node_list_.end();
    }


    // 获得计算图的正向计算顺序
    std::vector<std::vector<NodePtr>> TopoSort(const std::vector<NodePtr>& node_list) {
        using node_level = std::pair<NodePtr, int>;

        std::vector<std::vector<NodePtr>> node_level_list;
        std::map<NodePtr, int> map_node_level;

        for(auto& nodeptr : node_list) {
            map_node_level[nodeptr] = std::max(map_node_level[nodeptr], find_final_inputs(map_node_level, nodeptr) + 1);
        }


        // 将map结构转成数组序列结构
        std::vector<std::pair<NodePtr, int>> node_;
        for(auto n : map_node_level) {
            node_.emplace_back(n);
        }

        // 进行排序，按照输入到输出的序列进行排序。
        std::sort(node_.begin(), node_.end(), [](const node_level& x, const node_level& y) {
           return x.second < y.second;
        });

        // 一维数组转成二维数组，将同一层次的节点归并成一个数组。
        int iterate_level = 0;
        for(auto& n : node_) {
            if(n.second > iterate_level) {
                node_level_list.emplace_back(std::vector<NodePtr>());
                iterate_level = n.second;
            }

            node_level_list.back().push_back(n.first);
        }

        return node_level_list;
    }

    // 遍历到计算图的最终输出节点并返回最终输出节点
    std::vector<NodePtr> find_final_outputs(NodePtr nodeptr) {
        std::vector<NodePtr> v;
        return v;
    }



    // 递归到最终输入节点并递归返回节点的层级。
    // 需要注意的是，该代码没有对回环进行处理。
    int find_final_inputs(std::map<NodePtr, int>& is_searched, NodePtr nodeptr) {
        // 判断是否为输入节点
        if(nodeptr->is_variable()) {
            is_searched[nodeptr] = 1;
        }

        // 若节点未遍历，进行遍历，然后确定节点的层级
        else if(is_searched[nodeptr] < 1){
            for(auto& nptr : nodeptr->attr.inputs) {
                is_searched[nodeptr] = std::max(is_searched[nodeptr], find_final_inputs(is_searched, nptr) + 1);
            }
        }

        return is_searched[nodeptr];
    }

    // 获得计算图的反向计算顺序
    std::vector<std::vector<NodePtr>> ReverseTopoSort(std::vector<std::vector<NodePtr>>& forward_compute_node_list) {
        auto backward_compute_node_list = forward_compute_node_list;
        std::reverse(backward_compute_node_list.begin(), backward_compute_node_list.end());
        return backward_compute_node_list;
    }

}