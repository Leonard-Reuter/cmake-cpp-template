//
// Created by reuter on 12.05.24.
//

#ifndef MY_PROJECT_BLOCKALLOCATOR_HPP
#define MY_PROJECT_BLOCKALLOCATOR_HPP

#include <vector>
#include <cstddef> // for std::size_t
#include <gtest/gtest.h>

class BlockAllocator {

public:
    BlockAllocator(const std::size_t &blockSize);
    void add(const std::vector<double> &vector);
    std::vector<double> get();
    void destroy();

private:
    std::size_t blockSize_, size_;
    std::vector<double> vector_;

    FRIEND_TEST(BlockAllocatorTest, Construct);
    FRIEND_TEST(BlockAllocatorTest, Add);
    FRIEND_TEST(BlockAllocatorTest, Get);
    FRIEND_TEST(BlockAllocatorTest, Reallocate);
};


#endif //MY_PROJECT_BLOCKALLOCATOR_HPP
