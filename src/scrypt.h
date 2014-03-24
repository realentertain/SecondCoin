#ifndef SCRYPT_MINE_H
#define SCRYPT_MINE_H

#include <stdint.h>
#include <stdlib.h>

#include "util.h"
#include "net.h"

uint256 scrypt_salted_multiround_hash(const void* input, size_t inputlen, const void* salt, size_t saltlen, const unsigned int nRounds);
uint256 scrypt_salted_hash(const void* input, size_t inputlen, const void* salt, size_t saltlen);
uint256 scrypt_hash(const void* input, size_t inputlen);
uint256 scrypt_blockhash(const void* input);

const int SCRYPT_SCRATCHPAD_SIZE = 131072 + 63;


//
// PoW mining and Genesis Block generation part
// is going to be removed from the official release
//
typedef struct
{
    unsigned int version;
    uint256 prev_block;
    uint256 merkle_root;
    unsigned int timestamp;
    unsigned int bits;
    unsigned int nonce;

} block_header;

void *scrypt_buffer_alloc();
void scrypt_buffer_free(void *scratchpad);
void scrypt_1024_1_1_256_sp(const char *input, char *output, char *scratchpad);
void scrypt_1024_1_1_256(const char *input, char *output);
unsigned int scanhash_scrypt(block_header *pdata, void *scratchbuf, uint32_t max_nonce, uint32_t &hash_count, void *result, block_header *res_header);

#endif // SCRYPT_H
