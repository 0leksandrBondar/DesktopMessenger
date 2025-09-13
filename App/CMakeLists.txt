add_subdirectory(UI)

set(CPP_SOURCES main.cpp)
set_source_files_properties(${CPP_SOURCES} PROPERTIES LANGUAGE CXX)

add_executable(${PROJECT_NAME} ${CPP_SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC
    DM::UI
)
