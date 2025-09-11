cmake_minimum_required(VERSION 3.30)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

add_library(Qt INTERFACE)

target_link_libraries(Qt INTERFACE
        Qt6::Core
        Qt6::Widgets)
