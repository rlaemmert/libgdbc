#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

uint8_t cmd_checksum(const char* command);
uint64_t unpack_uint64(char *buff, int len);
uint64_t unpack_uint64_co(char* buff, int len);
int hex2int(int ch);

#endif
