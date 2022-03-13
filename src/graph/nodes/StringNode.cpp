#include <graph/nodes/StringNode.hpp>
#include <string>
namespace ArkNodes::Graph {
        StringNode::StringNode(std::string str) {
            _content = str;
        }
        const std::string StringNode::getOutput(){
            return '"' + _content + '"';
        }
    
}