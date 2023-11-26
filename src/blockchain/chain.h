#ifndef  __C_CHAIN_INCLUDED__
#define __C_CHAIN_INCLUDED__
#include "block.h"
#include <vector>

namespace blockchain 
{
    class Chain
    {
        private:
            std::vector<Block> chain_;
            Block* current_block_; // Latest defined block
            int difficulty_;
        public:
            Chain(int difficulty);
            void AddBlock(uint8_t previous_hash[SHA256_DIGEST_LENGTH], std::any data, uint32_t data_size);
            Block* GetLastBlock();
            std::vector<Block> GetChain();

    };
}

#endif
