#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <digraph.hh>
#include <graph/nodes/NodeBase.hpp>
#include <graph/ConnectionBase.hpp>
namespace ArkNodes::Graph {
    class Graph
    {
        private:
        digraph<NodeBase, ConnectionBase> _graph;
    };
    
}

#endif