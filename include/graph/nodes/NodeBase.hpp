#ifndef GRAPH_NODEBASE_HPP
#define GRAPH_NODEBASE_HPP
#include <string>

namespace ArkNodes::Graph {
    class NodeBase {
        public: 
        virtual const std::string getOutput() = 0;
        
    };
}

#endif