cmake_minimum_required(VERSION 4.0.2)

project(poc_plugin_linking)

set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 17)

add_library(lnk_interface INTERFACE)
target_include_directories(
        lnk_interface
        INTERFACE linking_interface/include
)

add_executable(poc_plugin_linking)
target_sources(
        poc_plugin_linking
        PRIVATE main_exec/src/main.cc
        main_exec/src/LnkInterfaceImpl.cc
)

target_include_directories(
        poc_plugin_linking
        PRIVATE main_exec/include
)

target_link_libraries(
        poc_plugin_linking
        PRIVATE lnk_interface
)


add_library(sub_plugin SHARED)
target_sources(
        sub_plugin
        PRIVATE sub_plugin/src/plugin_impl.cc
)
target_include_directories(
        sub_plugin
        PRIVATE sub_plugin/include
)
target_link_libraries(
        sub_plugin
        PRIVATE lnk_interface
)
