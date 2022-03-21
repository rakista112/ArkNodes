#define NOMINMAX

#include <iostream>
#include <Ark/Ark.hpp>
#include <Ark/Compiler/AST/Node.hpp>
#include <Ark/Compiler/AST/Parser.hpp>
#include <Ark/Compiler/Compiler.hpp>
#include <digraph.hh>
#include <digraphop.hh>
#include <eventpp/eventqueue.h>
#include <graph/nodes/Node.hpp>
#include <graph/Graph.hpp>
#include <graph/ConnectionBase.hpp>
#include <graph/nodes/NodeBase.hpp>
#include <graph/ConnectionBase.hpp>
#include <graph/nodes/TokenNode.hpp>
#include <graph/nodes/StringNode.hpp>

eventpp::EventQueue<int, void (const int &)> queue;

enum ArkEvent {
    OUTPUT_VAL = 1
};

Ark::Value emit_output(std::vector<Ark::Value>& args, Ark::VM* vm)
{
     // checking argument number
    if (args.size() != 1)
        throw std::runtime_error("my_function needs 1 argument!");

    auto num = args[0];
    if(num.valueType() == Ark::ValueType::Number){
        queue.enqueue(ArkEvent::OUTPUT_VAL, num.number());
        return num;
    } else {
        return Ark::Nil;
    }
    
   return Ark::Nil;
}

int main(int, char**) {
    std::unique_ptr<ArkNodes::Graph::Graph<ArkNodes::Graph::NodeBase, int>> graph(new ArkNodes::Graph::Graph<ArkNodes::Graph::NodeBase, int>());   
    auto tokenNode = ArkNodes::Graph::TokenNode("print");
    auto strNode = ArkNodes::Graph::StringNode("tes3ti3ng");
    graph->add(tokenNode, strNode, 0);
    std::cout << graph << std::endl;
    double num = 5;
    double num2 = 19;
    Ark::internal::Node myNode = Ark::internal::Node(num);
    Ark::internal::Node node2 = Ark::internal::Node(num2);
    Ark::internal::Node emitNode = Ark::internal::Node("emit_output");
    emitNode.push_back(node2);
    queue.appendListener(ArkEvent::OUTPUT_VAL, [](const int num){
        std::cout << "emitted number: " << num << std::endl;
    });

    Ark::State state;

    state.loadFunction("emit_output", emit_output);

    auto exp = "(emit_output (+ 100 (/ 70 7)))";
    auto emptyVec = std::vector<std::string>();
    auto compiler = Ark::Compiler(0, emptyVec, 0);
    auto parser = Ark::internal::Parser(0, 0, emptyVec);
    parser.feed(exp);

    //std::cout << "exp: " << parser.ast() << std::endl;
    std::cout << "exp: " << emitNode << std::endl;
    state.doString(exp);
    Ark::VM vm(&state);

    vm.run();
    state.reset();
    
    queue.process();
    
}
