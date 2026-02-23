#include <stdio.h>
#include <string.h>
#include <stlib.h>

void xor_cipher(char *text, char key) {
    int len = strlen(text);
    char* result = malloc(sizeof(char)*(len+1));
            for (int i = 0; i < len; i++) {
                result[i]= text[i] ^ key;
                return result;

        // TODO: Приложете XOR операция върху text[i]
    }
}

// В main функцията добавете:
int main(){
    char data[] = "Secret";
    char key = 'K';
    xor_cipher(data, key);
    printf("Encrypted: %s\n", data); // Внимание: Може да съдържа невидими символи!
    xor_cipher(data, key);
    printf("Decrypted: %s\n", data);
return EXIT_SUCCESS;

}