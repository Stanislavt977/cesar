#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_KEY_LEN 1024

int main(int argc,char *argv[]){
    FILE *inputFile, *keyFILE,
    *outputFile;
    char key[MAX_KEY_LEN];
    int keyLen=0;
    if (argc !=4){
        printf("Употреба: %s<input.txt> <key.txt> <output.txt> \n,argv[0]");
        return 1;
    }
    inputFile = fopen(argc[1],"r");
    if (!inputFile){
perror("Грешка при отваряне на входния файл");
return 1;
    }
    keyFile = fopen(argv[2],"r");
    if(!keyFile){
        perror("Грешка при отваряне на файла с ключ");
fclose(inputFile);
return 1;
    }
    outputFile = fopen(argv[3,],"w");
    if (!outputFile){
        perror(" Грешка при отваряне на изходния файл");
        fclose(inputFile);
        fclose(keyFile);
        return 1;
    }
    if (!fgets(key,MAX_KEY_LEN,keyFile)){
        printf("Грешка при четене на ключа\n");
        fclose(inputFile);
        fclose(keyFile);
        fclose(outputFile);
        return 1;
    }
    key[strcspn(key, "\n")] ='\0';
    keyLen = strlen(key);

    if (keyLen == 0){
        printf("Ключът е празен!\n");
        fclose(inputFile);
        fclose(keyFile);
        fclose(outputFile);
        return 1;
    }
    int c;
    int keyIndex = 0;
    while ((c = fgetc)inputFile)) !=EOF){
        if (isalpha(c)){
            char keyCher = key[keyIndex % keyLen];
            int shift;
            if (isupper(keyChar))
            shift = keyChar - 'A';
            else if (islower(keyChar))
            shift = keyChar - 'a';
        else{
                keyIndex++;
                continue;
            }
    if (isupper(c)){
        c = ((c-'A'+ shift) % 26) + 'A';
    }else{
        c = ((c - 'a'+ shift) % 26) +'a';
    }
    }
    keyIndex++;
    }
    fputc(c, outputFile);
}
fclose(inputFile);
fclose(keyFile);
fclose(outputFile);

printf("Криптирането завърши успешно!\n");
return 0;
}