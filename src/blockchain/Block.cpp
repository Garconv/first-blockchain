#include "block.h"
#include <stdio.h>
#include <string.h>
#include <any>

using namespace blockchain;

Block::Block(uint8_t previous_hash[SHA256_DIGEST_LENGTH], std::any data, uint32_t data_size)
{
    memset(hash_, SHA256_DIGEST_LENGTH, 0); // Initialize hash_ to nulls
    memcpy(previous_hash_, previous_hash, SHA256_DIGEST_LENGTH); // Copy the previous hash
    data_ = data;
    data_size_ = data_size;
    time_stamp_ = time(0);
    nonce_ = 0;
}

void Block::CalculateHash()
{   // Payload size = previous_hash + time_stamp + data + nonce (Sze of all of them)
    uint32_t payload_size = (SHA256_DIGEST_LENGTH * sizeof(uint8_t)) + sizeof(time_t) + data_size_ + sizeof(uint32_t);
    uint8_t* buf = new uint8_t[payload_size];
    uint8_t* ptr = buf;
    // Writing the data to the buffer
    memcpy(ptr, previous_hash_, SHA256_DIGEST_LENGTH * sizeof(uint8_t));
    ptr += SHA256_DIGEST_LENGTH * sizeof(uint8_t);

    memcpy(ptr, &time_stamp_, sizeof(time_t));
    ptr += sizeof(time_t);

    memcpy(ptr, &data_, data_size_);
    ptr += data_size_;

    memcpy(ptr, &nonce_, sizeof(uint32_t));
    ptr += sizeof(uint32_t);

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, buf, payload_size);
    SHA256_Final(hash_, &sha256);
}

uint8_t* Block::GetHash()
{
    return hash_;
}

// Hex format of hash
std::string Block::GetHashString()
{
    char buf[SHA256_DIGEST_LENGTH * 2 + 1];
    for(uint32_t n = 0; n < SHA256_DIGEST_LENGTH; n++) {
        sprintf(buf + (n * 2), "%02x", hash_[n]);
    }
    buf[SHA256_DIGEST_LENGTH * 2] = 0;
    return std::string(buf);
}

uint32_t Block::GetNonce()
{
    return nonce_;
}