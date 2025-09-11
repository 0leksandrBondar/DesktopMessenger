cmake_minimum_required(VERSION 3.30)

file(GLOB SOURCES
        "*.h"
        "*.cpp"
        "MessageView/*.h"
        "MessageView/*.cpp"
        "ClientsSidebar/*.h"
        "ClientsSidebar/*.cpp"
)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(Messenger PRIVATE Qt6::Widgets)

target_link_libraries(${PROJECT_NAME} PUBLIC
        Qt
)
