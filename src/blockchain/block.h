#ifndef __C_BLOCK_INCLUDED__
#define __C_BLOCK_INCLUDED__
#include <string>
#include <openssl/sha.h>
#include <any>

namespace blockchain
{
    class Block
    {
        private:
            uint8_t hash_[SHA256_DIGEST_LENGTH];
            uint8_t previous_hash_[SHA256_DIGEST_LENGTH];
            std::any data_;
            uint32_t data_size_;
            time_t time_stamp_;
            uint32_t nonce_;
        public:
            Block(uint8_t previous_hash[SHA256_DIGEST_LENGTH], std::any data, uint32_t data_size); // Constructor
            void CalculateHash();
            uint8_t* GetHash();
            std::string GetHashString(); // get the string representation of current_hash_
            // bool IsDificulty(int difficulty);
            // void mine(int difficulty);
            uint32_t GetNonce();

    };
}

#endif