add_executable(
        BlockAllocator_test
        BlockAllocator_test.cpp
)
target_link_libraries(
        BlockAllocator_test
        GTest::gtest_main
        allocators
)

include(GoogleTest)
gtest_discover_tests(BlockAllocator_test)