#ifndef CRC_H
#define CRC_H

#include <stddef.h>

#include "crchack.h"
#include "bigint.h"

struct crc_params {
    int width;             /* Width of the CRC register in bits */
    struct bigint poly;    /* Generator polynomial */
    struct bigint init;    /* Initial CRC register value */
    struct bigint xor_out; /* Final CRC register XOR mask */
    int reflect_in;        /* Reverse input bits (LSB first instead of MSB) */
    int reflect_out;       /* Reverse the final CRC register bits */
};

/**
 * Calculate CRC checksum using parameters defined in *config.
 *
 * The result is written to *out which must point to an initialized bigint
 * structure.
 */
void crc(const u8 *msg, size_t length, struct crc_params *config,
        struct bigint *out);

#endif
