
int main() {
    FILE *in = fopen("input.txt", "rb");
    if (in == NULL) {
        printf("Грешка при отваряне на input.txt\n");
        return 1;
    }

    FILE *out = fopen("encrypted.bin", "wb");
    if (out == NULL) {
        printf("Грешка при отваряне на encrypted.bin\n");
        fclose(in);
        return 1;
    }

    int ch;
    char key = 'X';

    while ((ch = fgetc(in)) != EOF) {
        char encrypted = ch ^ key;
        fputc(encrypted, out);
    }

    fclose(in);
    fclose(out);

    printf("Файлът беше успешно криптиран.\n");
    return 0;
}