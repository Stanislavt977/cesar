#include <stdio.h>
#include <string.h>
#include <ctype.h>


void vigenere_encrypt(const char *plaintext, const char *key, char *output) {
    int key_len = strlen(key);
    int key_index = 0;
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char p = toupper(plaintext[i]);

        if (isalpha(p)) {
            char k_char = toupper(key[key_index % key_len]);
            int shift = k_char - 'A';
            output[i] = ((p - 'A' + shift) % 26) + 'A';
            key_index++;
        } else {
            output[i] = plaintext[i];

                    }
    }

    output[strlen(plaintext)] = '\0';
    return 0;
