#ifndef GRAPH_NODE_TOKENNODE_HPP
#define GRAPH_NODE_TOKENNODE_HPP
#include <graph/nodes/NodeBase.hpp>
namespace ArkNodes::Graph {
    class TokenNode: public NodeBase {
        public:
        TokenNode(std::string token);
        const std::string getOutput();
        private:
        std::string _token;
    };
}
#endif