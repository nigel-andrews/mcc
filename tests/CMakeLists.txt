enable_testing()

add_executable(testsuite)

subdirs(misc)

target_include_directories(testsuite PUBLIC ${CMAKE_SOURCE_DIR}/src src)
target_link_libraries(testsuite PRIVATE asan GTest::gtest_main misc)

include(GoogleTest)
gtest_discover_tests(testsuite)
