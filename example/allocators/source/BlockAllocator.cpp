//
// Created by reuter on 12.05.24.
//

//#include "BlockAllocator.hpp"
#include <algorithm>  // for std::copy
#include "../include/BlockAllocator.hpp"


BlockAllocator::BlockAllocator(const std::size_t &blockSize)
    :
    blockSize_(blockSize),
    size_(0),
    vector_(blockSize) {}

void BlockAllocator::add(const std::vector<double> &vector){
    while (vector.size() + size_ > vector_.size()){
        // enlarges vector_ by one block size if r does not fit
        vector_.resize(vector_.size() + blockSize_, 0.0);
    }
    std::move(vector.begin(), vector.end(), vector_.begin() + size_);
    size_ += vector.size();
}

std::vector<double> BlockAllocator::get() {
    return {vector_.begin(), vector_.begin() + size_};
}

void BlockAllocator::destroy() {
    vector_.clear();
    size_ = 0;
}
