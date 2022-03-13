#ifndef GRAPH_NODE_STRINGNODE
#define GRAPH_NODE_STRINGNODE
#include <string>
#include <graph/nodes/NodeBase.hpp>

namespace ArkNodes::Graph {
    class StringNode: public NodeBase{
        public:
        StringNode(std::string str);
        const std::string getOutput();
        private:
        std::string _content;
    };
}

#endif