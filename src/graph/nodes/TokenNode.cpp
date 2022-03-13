#include <graph/nodes/TokenNode.hpp>
#include <string>
namespace ArkNodes::Graph {
    TokenNode::TokenNode(std::string token){
        _token = token;
    }
    const std::string TokenNode::getOutput(){
        return _token;
    }
}