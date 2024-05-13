add_subdirectory(allocators)

add_executable(main.bin main.cpp)
target_link_libraries(main.bin allocators)