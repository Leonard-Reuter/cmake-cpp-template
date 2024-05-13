set(HEADER_FILES
        include/BlockAllocator.hpp)
set(SOURCE_FILES
        source/BlockAllocator.cpp)

add_library(allocators STATIC ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(allocators
        GTest::gtest_main)
target_include_directories(allocators
        PUBLIC include
        PRIVATE source)

add_subdirectory(tests)