include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b9d2e1f62f3d93c1c3197900ba7170fa5177ad23.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES true *.hpp *.cpp)

add_executable(
  ${CMAKE_PROJECT_NAME}_test
  ${TEST_SOURCES}
)

target_link_libraries(
  ${CMAKE_PROJECT_NAME}_test
  PRIVATE ${CMAKE_PROJECT_NAME}_lib
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(${CMAKE_PROJECT_NAME}_test)