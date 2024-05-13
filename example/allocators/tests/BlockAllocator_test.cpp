#include <gtest/gtest.h>
#include "BlockAllocator.hpp"


class BlockAllocatorTest : public testing::Test {};

TEST(BlockAllocatorTest, Construct) {
    BlockAllocator blockAllocator(10);

    EXPECT_EQ(0, blockAllocator.size_);
    EXPECT_EQ(10, blockAllocator.vector_.size());
}

TEST(BlockAllocatorTest, Add) {
    BlockAllocator blockAllocator(10);
    std::vector<double> ref;
    for (int i = 1; i <= 7; i++){
        ref.push_back(double(i));
    }

    blockAllocator.add(ref);
    EXPECT_EQ(7, blockAllocator.size_);
}

TEST(BlockAllocatorTest, Get) {
    BlockAllocator blockAllocator(10);
    std::vector<double> ref;
    for (int i = 1; i <= 7; i++){
        ref.push_back(double(i));
    }

    blockAllocator.add(ref);
    auto ref2 = blockAllocator.get();
    EXPECT_EQ(ref, ref2);
}

TEST(BlockAllocatorTest, Reallocate) {
    BlockAllocator blockAllocator(10);
    std::vector<double> ref;
    for (int i = 1; i <= 7; i++){
        ref.push_back(double(i));
    }

    blockAllocator.add(ref);
    blockAllocator.add(ref);

    auto ref2 = blockAllocator.get();
    EXPECT_EQ(ref, std::vector<double>(ref2.begin(), ref2.begin() + 7));
    EXPECT_EQ(ref, std::vector<double>(ref2.begin() + 7, ref2.end()));
    EXPECT_EQ(14, blockAllocator.size_);
    EXPECT_EQ(20, blockAllocator.vector_.size());
}
