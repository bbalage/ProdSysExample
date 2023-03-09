enable_testing()

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.hpp *.h *.cpp)
file(GLOB_RECURSE LIB_SOURCES LIST_DIRECTORIES true *.hpp *.h *.cpp)
# list(REMOVE_ITEM LIB_SOURCES "main.cpp")
list(FILTER LIB_SOURCES EXCLUDE REGEX ".*main\\.cpp$")

set(LIB_NAME ${CMAKE_PROJECT_NAME}_lib)
add_library(${LIB_NAME} STATIC ${LIB_SOURCES} )

set(MAIN_EXECUTABLE_NAME ${CMAKE_PROJECT_NAME})
add_executable(${MAIN_EXECUTABLE_NAME} "main.cpp")
target_link_libraries(${MAIN_EXECUTABLE_NAME}
    ${LIB_NAME})