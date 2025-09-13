get_filename_component(MAIN_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(TARGET_NAME "__DM_${MAIN_NAME}")

file(GLOB_RECURSE CPP_SOURCES "*.cpp")
set_source_files_properties(${CPP_SOURCES} PROPERTIES LANGUAGE CXX)

file(GLOB_RECURSE HEADERS "*.h")

# Library name the same as the containing folder name. I.e. DM::UI
add_library(${TARGET_NAME} STATIC ${CPP_SOURCES} ${HEADERS})
add_library(DM::${MAIN_NAME} ALIAS ${TARGET_NAME})

target_link_libraries(${TARGET_NAME} PUBLIC
    Qt
)
target_include_directories(${TARGET_NAME} PUBLIC ../)

DMAddCompileOptionsTo(${TARGET_NAME})
