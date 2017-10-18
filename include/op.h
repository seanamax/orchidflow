//
// Created by chris on 17-10-2.
//

#ifndef ORCHIDFLOW_OP_H
#define ORCHIDFLOW_OP_H

#include <limits>
#include "node.h"

namespace orchidflow
{

    template <typename value_type>
    class Registry;

    static const uint32_t kVarg = std::numeric_limits<uint32_t>::max();

    using ParamFieldInfo = std::string;

    class Op {
    public:
        std::string name;
        std::string description;
        std::vector<ParamFieldInfo> arguments;

        uint32_t num_inputs = 1;
        uint32_t num_outputs = 1;

        std::function<uint32_t(const NodeAttrs& attrs)> get_num_outputs = nullptr;
        std::function<uint32_t(const NodeAttrs& attrs)> get_num_inputs = nullptr;
        std::function<void (NodeAttrs* attrs)> attr_parser = nullptr;

        inline Op& describe(const std::string& descr);

        inline Op& add_argument(const std::string &name,
                                const std::string &type,
                                const std::string &description);

        inline Op& set_num_inputs(uint32_t n);

        inline Op& set_num_inputs(std::function<uint32_t(const NodeAttrs& attrs)> fn);

        inline Op& set_num_outputs(uint32_t n);

        inline Op& set_num_outputs(std::function<uint32_t (const NodeAttrs& attr)> fn);

        inline Op& set_attr_parser(std::function<void (NodeAttrs* attrs)> fn);


        template <typename value_type>
        inline Op& set_attr(const std::string& attr_name,
                            const value_type& value,
                            int plevel = 10);


        Op& add_alias(const std::string& alias);

        Op& include(const std::string& group_name);

        static const Op* Get(const std::string& op_name);

//        template <typename value_type>
//        static const OpMap<value_type>& GetAttr(const std::string& attr_name);

    private:
        template <typename value_type>
        friend class OnMap;
        friend class OpGroup;
        friend class Registry<Op>;

        uint32_t index_{0};

        Op();
//
//        static const any* GetAttrMap(const std::string& key);
//
//        static void UpdateAttrMap(const std::string &key,
//                                std::function<void(any*)> updater);
//
//        static void AddGroupTrigger(const std::string &group_name,
//                                    std::function<void(Op*)> trigger);
    };

//
//    template <typename value_type>
//    class OpMap {
//    public:
//
//        inline const value_type& operator[](const Op* op) const;
//
//        inline const value_type& get(const Op* op, const value_type& def_value) const;
//
//        inline int count(const Op* op) const;
//
//
//    private:
//        friend class Op;
//        std::string attr_name_;
//        std::vector<std::pair<value_type, int>> data_;
//        //OnMap() = default;
//    };
//
//
//
//    class OpGroup {
//    public:
//        std::string group_name;
//
//        template <typename value_type>
//        inline OpGroup& set_attr(const std::string& attr_name,
//                                 const value_type &value,
//                                 int plevel = 1);
//    };
}

#endif //ORCHIDFLOW_OP_H
