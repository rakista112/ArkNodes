cmake_minimum_required(VERSION 3.0.0)
project(ArkNodes VERSION 0.1.0)
include(CTest)
enable_testing()

add_executable(ArkNodes 
    main.cpp 
    ${CMAKE_SOURCE_DIR}/src/graph/Node.cpp
    ${CMAKE_SOURCE_DIR}/src/graph/Graph.cpp
    ${CMAKE_SOURCE_DIR}/src/graph/NodeBase.cpp
    ${CMAKE_SOURCE_DIR}/src/graph/ConnectionBase.cpp
    ${CMAKE_SOURCE_DIR}/src/graph/nodes/TokenNode.cpp
    ${CMAKE_SOURCE_DIR}/src/graph/nodes/StringNode.cpp

    )
set_target_properties(ArkNodes PROPERTIES CXX_STANDARD 20)
add_subdirectory(ArkReactor)
add_subdirectory(libs/eventpp)
target_include_directories(ArkNodes PUBLIC "include")
target_include_directories(ArkNodes PUBLIC "ArkReactor/include")
target_include_directories(ArkNodes PUBLIC "libs/eventpp/include")
target_include_directories(ArkNodes PUBLIC "libs/digraph/dglib")

target_link_libraries(${PROJECT_NAME} PUBLIC ArkReactor)
target_link_libraries(${PROJECT_NAME} PUBLIC eventpp::eventpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
