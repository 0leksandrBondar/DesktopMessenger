cmake_minimum_required(VERSION 3.30)

file(GLOB_RECURSE CPP_SOURCES "*.cpp")
set_source_files_properties(${CPP_SOURCES} PROPERTIES LANGUAGE CXX)

file(GLOB_RECURSE HEADERS "*.h")

find_package(Qt6 REQUIRED COMPONENTS Widgets)
add_executable(${PROJECT_NAME} ${CPP_SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt
    Qt6::Widgets
)
