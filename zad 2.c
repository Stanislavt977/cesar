
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void sha256_string(char *str, char outputBuffer[65]) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)str, strlen(str), hash);

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[64] = 0;
}

int main() {
    char target_hash[] = "5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8";
    char input[20];
    char hash[65];

    for(int pin = 0; pin <= 9999; pin++) {
        // форматиране: 0000_SEC
        sprintf(input, "%04d_SEC", pin);

        sha256_string(input, hash);

        if(strcmp(hash, target_hash) == 0) {
            printf("PIN found: %04d\n", pin);
            return 0;
        }
    }

    printf("PIN not found.\n");
    return 0;
}