project(minicsv_tests)

add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'googletest_run' is the target name
add_executable(minicsv_tests minicsv.h test_minicsv.cpp)
target_link_libraries(minicsv_tests gtest gtest_main)