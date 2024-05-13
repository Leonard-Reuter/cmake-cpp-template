#include <iostream>
#include "BlockAllocator.hpp"

int main() {
    BlockAllocator blockAllocator(10);

    std::vector<double> ref;
    for (int i = 1; i <= 7; i++){
        ref.push_back(double(i));
    }

    blockAllocator.add(ref);
    blockAllocator.add(ref);

    auto ref2 = blockAllocator.get();

    for (auto d : ref2){
        std::cout << d << " ";
    }
    std::cout << std::endl;

    ref2.clear();
    blockAllocator.destroy();
    return 0;
}
