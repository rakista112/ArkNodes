#include <iostream>
#include <Ark/Ark.hpp>

#include <Ark/Compiler/AST/Node.hpp>
#include <Ark/Compiler/AST/Parser.hpp>
#include <Ark/Compiler/Compiler.hpp>

#include <eventpp/callbacklist.h>


int main(int, char**) {
    double num = 5;
    double num2 = 19;
    Ark::internal::Node myNode = Ark::internal::Node(num);
    Ark::internal::Node node2 = Ark::internal::Node(num2);
    auto exp = "(+ 100 (/ 70 7))";
    auto emptyVec = std::vector<std::string>();
    auto compiler = Ark::Compiler(0, emptyVec, 0);
    auto parser = Ark::internal::Parser(0, 0, emptyVec);
    parser.feed(exp);
    compiler.feed(exp);
    compiler.compile();
    
    Ark::State state;
    Ark::VM vm(&state);

    std::cout << "exp: " << parser.ast() << std::endl;

    state.feed(compiler.bytecode());
    vm.run();
    state.reset();

    eventpp::CallbackList<void (const std::string &, const bool)> callbackList;
    callbackList.append([](const std::string & s, const bool b) {
        std::cout << std::boolalpha << "Got callback 1, s is " << s << " b is " << b << std::endl;
    });
    callbackList.append([](std::string s, int b) {
        std::cout << std::boolalpha << "Got callback 2, s is " << s << " b is " << b << std::endl;
    });
    callbackList("Hello world", true);
}
