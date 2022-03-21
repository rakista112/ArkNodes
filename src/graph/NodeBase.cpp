#include <graph/nodes/NodeBase.hpp>
namespace ArkNodes::Graph {
      std::string NodeBase::getOutput(){
         return "";
     }
     std::ostream& operator<<(std::ostream& os,   NodeBase& node){
         os << node.getOutput();
         return os;
     }
}