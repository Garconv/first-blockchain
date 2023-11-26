#include "chain.h"
#include <vector>

using namespace blockchain;


Chain::Chain(int difficulty) 
{
    difficulty_ = difficulty;
    // Creating the Genises Block
    chain_.push_back(
        Block(0, 0, 0)
    );
    current_block_ = &chain_[0];    
}

void Chain::AddBlock(uint8_t previous_hash[SHA256_DIGEST_LENGTH], std::any data, uint32_t data_size)
{
    chain_.push_back(
        Block(previous_hash, data, data_size)
    );
}

Block* Chain::GetLastBlock()
{
    return current_block_;
}

std::vector<Block> Chain::GetChain()
{
    return chain_;
}