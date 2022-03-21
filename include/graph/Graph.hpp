#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <digraph.hh>
#include <digraphop.hh>
#include <graph/nodes/NodeBase.hpp>
#include <graph/ConnectionBase.hpp>
namespace ArkNodes::Graph {
    template<typename NodeT, typename ConnectionT>
    class Graph
    {
        private:
        digraph<NodeT, ConnectionT> _graph;
        public:
        Graph() = default;
        void add(NodeT nodeSrc, NodeT nodeDest, ConnectionT conn){
            _graph.add(nodeSrc, nodeDest, conn);
        };
        digraph<NodeT, ConnectionT> print(){
            return _graph;
        };
    };
    
}

#endif