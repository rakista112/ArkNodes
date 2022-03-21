#ifndef GRAPH_CONNECTIONBASE_HPP
#define GRAPH_CONNECTIONBASE_HPP
namespace ArkNodes::Graph {
    class ConnectionBase {
        public:
        // the slot in the argument list for 
        // the destination node
        int slot;
        ConnectionBase() {}
    };
}
#endif
