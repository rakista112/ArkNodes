#ifndef GRAPH_NODEBASE_HPP
#define GRAPH_NODEBASE_HPP
#include <string>
#include <iostream>
#include <compare>
namespace ArkNodes::Graph {
    class NodeBase {
        public: 
        std::string getOutput();
        friend std::ostream& operator<<(std::ostream& os, NodeBase& dt);
        /*
        bool operator<(const NodeBase& node) const{
            return true;
        };
        */
       auto operator<=>(const NodeBase& node) const = default;
    };
}

#endif