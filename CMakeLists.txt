cmake_minimum_required(VERSION 3.0.0)
project(ArkNodes VERSION 0.1.0)
include(CTest)
enable_testing()

add_executable(ArkNodes main.cpp)
set_target_properties(ArkNodes PROPERTIES CXX_STANDARD 17)
add_subdirectory(ArkReactor)
add_subdirectory(libs/eventpp)
target_include_directories(ArkNodes PUBLIC "ArkReactor/include")
target_include_directories(ArkNodes PUBLIC "libs/eventpp/include")

target_link_libraries(${PROJECT_NAME} PUBLIC ArkReactor)
target_link_libraries(${PROJECT_NAME} PUBLIC eventpp::eventpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
