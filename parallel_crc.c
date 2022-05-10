#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/stat.h>

uint8_t gencrc(uint8_t *data, size_t len)
{
    uint8_t crc = 0xff;
    size_t i, j;
    for (i = 0; i < len; i++) {
        crc ^= data[i];
        for (j = 0; j < 8; j++) {
            if ((crc & 0x80) != 0)
                crc = (uint8_t)((crc << 1) ^ 0x31);
            else
                crc <<= 1;
        }
    }
    return crc;
}
int main(int argc, char *argv[]) {
    char *fileName = "";
    uint8_t size = 0;
    struct stat stats;
    for (int i=1; i<argc; i++){
        fileName = argv[i];
        stat(fileName, &stats);
        size = gencrc(fileName,stats.st_size);
        printf("%s=%d\n", fileName, size);
    }
    return 0;
}